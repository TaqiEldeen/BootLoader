/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: FPEC  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 11 OCT 2023	 	**************/
/*********************************************************/

#ifndef FPEC_INT_H
#define FPEC_INT_H

typedef enum{
    FPEC_OK,
    FPEC_NOK
}FPEC_CheckType;

/**
 * @brief This function is used to unlock the FPEC using the unlock sequence
 * 
 */
void FPEC_vUnlock(void);

/**
 * @brief This function is used to write half-word data to the flash memory
 * 
 * @param A_u32Address  The address of the data to be written
 * @param A_u16Data     The data to be written
 * @return FPEC_CheckType 
 */
FPEC_CheckType FPEC_eWriteHalfWord(u32 A_u32Address, u16 A_u16Data);

/**
 * @brief This function is used to write the needed data to the flash memory
 * 
 * @param A_u32Address  The Start address of the data to be written
 * @param A_u16Data     The data to be written
 * @param A_u16Length   The length of the data to be written
 * @return FPEC_CheckType 
 */
FPEC_CheckType FPEC_eWriteData(u32 A_u32Address, u16 * A_u16Data, u16 A_u16Length);


/**
 * @brief This function is used to erase the application area
 * 
 */
FPEC_CheckType FPEC_vEraseAppArea(void);

#endif // FPEC_INT_H
