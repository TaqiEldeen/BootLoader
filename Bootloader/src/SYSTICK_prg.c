/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/

/*  LIB Inclusion   */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*  Module Inclusion   */
#include "SYSTICK_pri.h"
#include "SYSTICK_cfg.h"
#include "SYSTICK_int.h"
#include "SYSTICK_reg.h"

/**
 * @brief Global Variable to Hold the CallBack Function
 * 
 */
static ptr_func_t SYSTICK_CallBack = ADDRESS_NULL;

/**
 * @brief Global Variable to Hold the state of the SYSTICK in Async mode
 * 
 */
static u8 isSingleInterval = FALSE;

/**
 * @brief Interface Function to Initialize the SYSTICK
 * 
 * @note To enable the SYSTICK you can call the SYSTICK_vTurnOff() function
 */
void SYSTICK_vInit(void) {
    SYSTICK-> CTRL = 0;                                       /* Clear CTRL */
    SYSTICK-> LOAD = SYSTICK_RELOAD_VALUE;                    /* Set the maximum value */   
    SYSTICK-> VAL  = 0;                                       /* Clear the current value */
    SYSTICK-> CTRL |= (SYSTICK_CLKSOURCE << CLKSOURCE);       /* Select the clock source */
}

/**
 * @brief Interface Function to Turn on the SYSTICK
 * 
 */
void SYSTICK_vTurnOn(void) {
    SET_BIT(SYSTICK-> CTRL, ENABLE);
}

/**
 * @brief  Interface Function to Turn off the SYSTICK
 * 
 */
void SYSTICK_vTurnOff(void) {
    CLR_BIT(SYSTICK-> CTRL, ENABLE);
}

/**
 * @brief Interface Function to Set the Reload Value
 * 
 * @param A_u32Ticks 
 */
void SYSTICK_vSetReload(u32 A_u32Ticks){
    SYSTICK-> LOAD = A_u32Ticks;
}

/**
 * @brief Interface Function to Get the Elapsed Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetElapsedTicks(void) {
    return ( (SYSTICK->LOAD) - (SYSTICK-> VAL) );
}

/**
 * @brief Interface Function to Get the Remaining Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetRemainingTicks(void) {
    return (SYSTICK-> VAL);
}

/**
 * @brief Interface Function to Set the Interval for only one time
 * 
 * @param A_u32Ticks the ticks needed for this interval
 * @param A_ptr_func the function to be called after this interval
 */
void SYSTICK_vSetIntervalSingle(u32 A_u32Ticks, ptr_func_t A_ptr_func){
    SYSTICK-> CTRL |= (1 << TICKINT);          /* Enable the interrupt */
    SYSTICK-> LOAD = A_u32Ticks;               /* Set the maximum value */
    SYSTICK_CallBack = A_ptr_func;             /* Set the CallBack Function */
    isSingleInterval = TRUE;                   /* Set the state to single interval */
    SYSTICK_vTurnOn();                         
}

/**
 * @brief Interface Function to Set the Interval for periodic calls
 * 
 * @param A_u32Ticks the ticks needed for this interval
 * @param A_ptr_func the function to be called after this interval
 */
void SYSTICK_vSetIntervalPeriodic(u32 A_u32Ticks, ptr_func_t A_ptr_func){
    SYSTICK-> CTRL |= (1 << TICKINT);          /* Enable the interrupt */
    SYSTICK-> LOAD = A_u32Ticks;               /* Set the maximum value */
    SYSTICK_CallBack = A_ptr_func;             /* Set the CallBack Function */
    isSingleInterval = FALSE;                  /* Set the state to single interval */
    SYSTICK_vTurnOn();
}

/**
 * @brief Interface Function to set a busy wait for a specific time
 * 
 * @param A_u32Ticks the ticks needed for this busy wait
 */
void SYSTICK_vSetBusyWait(u32 A_u32Ticks){
    SYSTICK-> CTRL &= ~(1 << TICKINT);          /* Disable the interrupt */
    SYSTICK-> LOAD = A_u32Ticks;                /* Set the maximum value */
    SYSTICK_vTurnOn();
    while (GET_BIT(SYSTICK-> CTRL, COUNTFLAG) == 0)
    {
        /* Wait for time to pass */
    }
    SYSTICK_vTurnOff();
}

/**
 * @brief Interface function to reset the systick
 * 
 * @note Resets the value of the VAL register
 * 
 */
void SYSTICK_vReset(){
    SYSTICK -> VAL = 0; 
}

/**
 * @brief ISR Function to Handle the SYSTICK Interrupt
 * 
 *  */
void SysTick_Handler(void) {
    if (SYSTICK_CallBack != ADDRESS_NULL) {
        SYSTICK_CallBack();

        if(isSingleInterval) {
            isSingleInterval = FALSE;
            SYSTICK-> CTRL &= ~(1 << TICKINT);          /* Disable the interrupt */
            SYSTICK_vTurnOff();
        } 
        else {
            /*  Do Nothing  */
        }
        
    } else {
        /*  Do Nothing  */
    }
}