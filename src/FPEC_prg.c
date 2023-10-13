/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: FPEC  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 11 OCT 2023	 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_int.h"
#include "FPEC_pri.h"
#include "FPEC_cfg.h"
#include "FPEC_reg.h"


/**
 * @brief This function is used to unlock the FPEC using the unlock sequence
 * 
 */
void FPEC_vUnlock(void){
    FPEC->KEYR = FPEC_KEY1;
    FPEC->KEYR = FPEC_KEY2;
}

/**
 * @brief This function is used to write half-word data to the flash memory
 * 
 * @param A_u32Address  The address of the data to be written
 * @param A_u16Data     The data to be written
 * @return FPEC_CheckType 
 */
FPEC_CheckType FPEC_eWriteHalfWord(u32 A_u32Address, u16 A_u16Data){
    /* Flash Programming */
    SET_BIT(FPEC->CR, PG);

    /* Perform Half-Word write to the address */
    *((volatile u16*)A_u32Address) = A_u16Data;

    /* Wait For Operation To Be Completed */
    FPEC_CheckType L_eCheck = FPEC_eCheckLastOperation();

    /* Disable The PG Bit */
    CLR_BIT(FPEC->CR, PG);

    return L_eCheck;
}

/**
 * @brief This function is used to write the needed data to the flash memory
 * 
 * @param A_u32Address  The Start address of the data to be written
 * @param A_u16Data     The data to be written
 * @param A_u16Length   The length of the data to be written
 * @return FPEC_CheckType 
 */
FPEC_CheckType FPEC_eWriteData(u32 A_u32Address, u16 * A_u16Data, u16 A_u16Length){
    FPEC_CheckType L_eCheck = FPEC_OK;

    /* Flash Programming */
    SET_BIT(FPEC->CR, PG);

    /* Perform Half-Word write to the address */
    for(u16 i = 0; i < A_u16Length; i++){
        *((volatile u16*)(A_u32Address + (i * 2))) = A_u16Data[i];
        L_eCheck = FPEC_eCheckLastOperation();
        if(L_eCheck == FPEC_NOK){
            break;
        }
    }

    /* Disable The PG Bit */
    CLR_BIT(FPEC->CR, PG);

    return L_eCheck;
}

/**
 * @brief This function checks the last operation to be completed and returns the status
 * 
 * @note It clears the EOP bit after checking
 * 
 * @return FPEC_CheckType   The status of the last operation
 */
static FPEC_CheckType FPEC_eCheckLastOperation(void){
    FPEC_CheckType L_eCheck = FPEC_OK;

    /* Wait For Operation To Be Completed */
    while(GET_BIT(FPEC->SR, BSY) == 1);

    /* Check For Errors */
    if(GET_BIT(FPEC->SR, EOP) == 1){
        /* Clear EOP Bit */
        SET_BIT(FPEC->SR, EOP);
    }
    else{
        L_eCheck = FPEC_NOK;
    }

    return L_eCheck;
}

/**
 * @brief This function is used to erase the application area
 * 
 */
FPEC_CheckType FPEC_vEraseAppArea(void){
    FPEC_CheckType L_eCheck = FPEC_OK;

    /* Enable The Erase Bit */
    SET_BIT(FPEC->CR, PER);

    for(u8 i = 0; i < FPEC_APP_PAGES; i++){
        /* Set The Start Address */
        FPEC->AR = FPEC_APP_START_ADDRESS + (i * 1024);

        /* Start Erasing */
        SET_BIT(FPEC->CR, STRT);

        /* Wait For Operation To Be Completed */
        L_eCheck = FPEC_eCheckLastOperation();

        if(L_eCheck == FPEC_NOK){
            break;
        }
    }

    /* Disable The Erase Bit */
    CLR_BIT(FPEC->CR, PER);

    return L_eCheck;
}