/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/

/*          LIB inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          Module inclusion        */
#include "NVIC_pri.h"
#include "NVIC_int.h"
#include "NVIC_reg.h"
#include "NVIC_cfg.h" 

/**********************************************************************************************************
 * Description : Interface Function to Enable Interrupts in NVIC
 * Outputs     : Error State
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vEnableInterrupt(u8 A_u8IntId) {
    u8 L_u8ErrorState = 0;
    if (A_u8IntId <= 31) {
        NVIC_ISER0 = (1 << A_u8IntId);  /* Writing 0 has no effect */
    } else if (A_u8IntId <= 59) {
        A_u8IntId -= 32;
        NVIC_ISER1 = (1 << A_u8IntId); 
    } else {
        /* Return Error */
        L_u8ErrorState = 1;
    }
    return L_u8ErrorState;
}

/**********************************************************************************************************
 * Description : Interface Function to Disable Interrupts in NVIC
 * Outputs     : Error State
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vDisableInterrupt(u8 A_u8IntId){
    u8 L_u8ErrorState = 0;
    if (A_u8IntId <= 31) {
        NVIC_ICER0 = (1 << A_u8IntId);
    } else if (A_u8IntId <= 59) {
        A_u8IntId -= 32;
        NVIC_ICER1 = (1 << A_u8IntId);
    } else {
        /* Return Error */
        L_u8ErrorState = 1;
    }
    return L_u8ErrorState;
}

/**********************************************************************************************************
 * Description : Interface Function to Set Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vSetPendingInterrupt(u8 A_u8IntId) {
    if (A_u8IntId <= 31) {
        NVIC_ISPR0 = (1 << A_u8IntId);
    } else if (A_u8IntId <= 59) {
        A_u8IntId -= 32;
        NVIC_ISPR1 = (1 << A_u8IntId);
    } else {
        /* Return Error */
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Clear Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vClearPendingInterrupt(u8 A_u8IntId) {
    if (A_u8IntId <= 31) {
        NVIC_ICPR0 = (1 << A_u8IntId);
    } else if (A_u8IntId <= 59) {
        A_u8IntId -= 32;
        NVIC_ICPR1 = (1 << A_u8IntId);
    } else {
        /* Return Error */
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Get Active Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetActiveInterrupt(u8 A_u8IntId) {
    u8 L_u8ActiveState = 0;
    if (A_u8IntId <= 31) {
        L_u8ActiveState = GET_BIT(NVIC_IABR0, A_u8IntId);
    } else if (A_u8IntId <= 59) {
        A_u8IntId -= 32;
        L_u8ActiveState = GET_BIT(NVIC_IABR1, A_u8IntId);
    } else {
        /* Return Error */
    }
    return L_u8ActiveState;
}

/**********************************************************************************************************
 * Description : Interface Function to Set Priority of Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number, Priority, Group Priority
 * NOTES       : This Function adaptes to the Priority Grouping chosen in the configuration file
 *               SubGroup and Group Priority can be neglected if the Priority Grouping is 0 or 4
 ***********************************************************************************************************/
void NVIC_vSetPriority(u8 A_u8IntId, u8 A_u8SubPriority, u8 A_u8GroupPriority){
    /* Choose The Priority grouping */
    SCB_AIRCR = NVIC_PRIORITY_GROUPING;

    /* Set Priority */
    #if NVIC_PRIORITY_GROUPING == NVIC_PRIORITY_GROUPING_0
        NVIC_IPR[A_u8IntId] = (A_u8GroupPriority << 4);
    #elif NVIC_PRIORITY_GROUPING == NVIC_PRIORITY_GROUPING_1
        if(A_u8SubPriority < 2) {  /* Prevent wrong priority */
            NVIC_IPR[A_u8IntId] = (A_u8GroupPriority << 5) | (A_u8SubPriority << 4);
        }
    #elif NVIC_PRIORITY_GROUPING == NVIC_PRIORITY_GROUPING_2
        if(A_u8SubPriority < 4) {  /* Prevent wrong priority */
            NVIC_IPR[A_u8IntId] = (A_u8GroupPriority << 6) | (A_u8SubPriority << 4);
        }
    #elif NVIC_PRIORITY_GROUPING == NVIC_PRIORITY_GROUPING_3
        if(A_u8SubPriority < 8) {  /* Prevent wrong priority */
            NVIC_IPR[A_u8IntId] = (A_u8GroupPriority << 7) | (A_u8SubPriority << 4);
        }
    #elif NVIC_PRIORITY_GROUPING == NVIC_PRIORITY_GROUPING_4
        NVIC_IPR[A_u8IntId] = (A_u8SubPriority << 4);
    #endif
}

/**********************************************************************************************************
 * Description : Interface Function to Get Priority of Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetPriority(u8 A_u8IntId){
    u8 L_u8Priority = 0;
    L_u8Priority = NVIC_IPR[A_u8IntId];
    return L_u8Priority;
}