
/* LIB Include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Module Include */
#include "PARSER.h"

/* MCAL include */
#include "FPEC_int.h"

u16 Data[100] = {0};
u32 Address= 0x08000000;


/**
 * @brief This function handle the verification of the checksum received in the record
 * 
 * @param Copy_u8Record			pointer to the record
 * @param Copy_u8Data 			The Data decoded to hex by ParseData function
 * @param Copy_u8LengthOfData 	The length of the decoded data
 * @return CHECK_SUM_t 			enum for error checking
 */
static CHECK_SUM_t	checkSumVerifier(u8 *Copy_u8Record, u8 *Copy_u8Data, u8 Copy_u8LengthOfData);



/**
 * @brief Convert ASCII characters to hex values 
 * 
 * @param Copy_u8Asci The ASCII Character
 * @return u8 
 */
static u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}

	else
	{
		Result = Copy_u8Asci - 55;
	}

	return Result;
}


/**
 * @brief Parse the data received, and flash it 
 * 
 * @param Copy_u8BufData 	The data record
 * @return CHECK_SUM_t 
 */
static CHECK_SUM_t ParseData(u8* Copy_u8BufData)
{
	u8 DigitLow,DigitHigh,CC,i;
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 DataCounter = 0;

	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufData[1]);
	DigitLow  = AsciToHex (Copy_u8BufData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
	DataDigit3 = AsciToHex (Copy_u8BufData[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

	for (i=0; i< CC/2; i++)
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i+9 ]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+10]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+11]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+12]);
		/* EX: 0xFACB. D0 = F, D1 = A, D2 = C, D3 = B
		 * Data --->  0X D2 D3 D0 D1  ---> 0x CB FA 
		 * This is due to little-endian memory organization 
		 * :07230C00  6572 7275 7074 0000    28
		 */
		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);

		DataCounter++;
		/* If it is ODD */
		if( i == (CC/2 - 1)){
			if( (CC % 2) != 0) {
				DataDigit0 = AsciToHex (Copy_u8BufData[4*i+13]);
				DataDigit1 = AsciToHex (Copy_u8BufData[4*i+14]);
				Data[DataCounter] = (DataDigit1) | (DataDigit0 << 4) | (0x00 << 8) | (0x00 << 12);
				DataCounter++;
			}
		}
	}

	/* DataCounter is for half-word access, therefor we multiply it by 2 to get every byte.
	 * As the pointer in the function is u8 (Byte access)
	 */
	CHECK_SUM_t L_verifyCheckSum = checkSumVerifier(Copy_u8BufData, Data, CC );

	if(L_verifyCheckSum == NO_ERR) {
		FPEC_eWriteData(Address,Data,CC/2);
	} else {
		/* error in check sum */
	}

	return L_verifyCheckSum;
}

/**
 * @brief 	Parse the record to identify the type of this record
 * 
 * @note we have 6 types but we handle currently data and eof records
 * 
 * @param Copy_u8BufData 
 * @return HEX_RECORD_TYPE 
 */
HEX_RECORD_TYPE Parser_eParseRecord(u8* Copy_u8BufData)
{
	HEX_RECORD_TYPE RecordType = DEFAULT;
	switch (Copy_u8BufData[8])
	{
		case '0': /* Data Record */
		{
			RecordType = DATA_RECORD;	
			CHECK_SUM_t checkSumVerify = ParseData(Copy_u8BufData);	 
			if(checkSumVerify == ERR) {
				RecordType = CHECK_SUM_ERROR;
			}
			break;
		}
		case '1': RecordType = END_OF_FILE_RECORD; break;
		case '4': RecordType = EXTENDED_LINEAR_ADDRESS_RECORD; /* ParseUpperAddress(Copy_u8BufData); */ break;
	}

	return RecordType;
}


/**
 * @brief This function handle the verification of the checksum received in the record
 * 
 * @param Copy_u8Record			pointer to the record
 * @param Copy_u8Data 			The Data decoded to hex by ParseData function
 * @param Copy_u8LengthOfData 	The length of the decoded data
 * @return CHECK_SUM_t 			enum for error checking
 */
static CHECK_SUM_t checkSumVerifier(u8 *Copy_u8Record, u8 *Copy_u8Data, u8 Copy_u8LengthOfData){
	CHECK_SUM_t L_verifyCheckSum = NO_ERR;
	u16 L_u16CheckSum = 0x00;
	u8 L_u8ReceivedCheckSum = 0x00;

	/* 
	* Convert to HEX
	* Starts at 1 which is bytes count and ends with index of 8 which is record type */
	for(u8 i = 1; i <= 7; i += 2) {
		/* EX: A4 -->  ( AsciToHex(0) << 4 ) means A0 then | AsciToHex(1) result = A4 as a HEX */
		L_u16CheckSum += (  ( AsciToHex(Copy_u8Record[i]) << 4 ) | AsciToHex(Copy_u8Record[i + 1]) );
	}

	/**
	 * Add the already converted data to checksum
	 * 6572 7275 7074 0000
	 */
	for(u8 i=0; i < Copy_u8LengthOfData; i++) {
		L_u16CheckSum += Copy_u8Data[i];
	}

	/* Convert the recevied checksum to HEX 
	 * EX: :1012A400 000000000000000024000020380000209E
	 * The checksum is at index of (cc + address characters + cc characters + record type characters + : character)
	 * 9 ---> means: 	:1012A400
	 * Copy_u8LengthOfData*2 --> means: every character in the data
	 * Therefore we get the index of the last two bytes which is the checksum index
	*/
	L_u8ReceivedCheckSum =  ( AsciToHex(Copy_u8Record[Copy_u8LengthOfData*2 + 9]) << 4 ) | AsciToHex(Copy_u8Record[Copy_u8LengthOfData*2 + 10]);

	/* Get The 2s complement */
	L_u16CheckSum = (~L_u16CheckSum) + 1;

	if((u8)L_u16CheckSum != L_u8ReceivedCheckSum) {
		L_verifyCheckSum = ERR ;
	}

	return L_verifyCheckSum;
}
