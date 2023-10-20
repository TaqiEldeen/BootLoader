/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/
#ifndef SYSTICK_INT_H
#define SYSTICK_INT_H

/**
 * @brief Interface Function to Initialize the SYSTICK
 * 
 * @note This Function Must be called before any other function in this module
 *       Initialize the SYSTICK with the configured values in the configuration file
 * 
 */
void SYSTICK_vInit(void);

/**
 * @brief Interface Function to Set the Reload Value
 * 
 * @param A_u32Ticks 
 */
void SYSTICK_vSetReload(u32 A_u32Ticks);

/**
 * @brief Interface Function to get the Elapsed Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetElapsedTicks(void);

/**
 * @brief Interface Function to Get the Remaining Ticks
 * 
 * @return u32 
 */
u32 SYSTICK_u32GetRemainingTicks(void);

/**
 * @brief Interface Function to Turn off the SYSTICK
 * 
 */
void SYSTICK_vTurnOff(void);

/**
 * @brief Interface Function to Turn on the SYSTICK
 * 
 */
void SYSTICK_vTurnOn(void);

/**
 * @brief Interface Function to Set the Interval for only one time
 * 
 * @param A_u32Ticks the ticks needed for this interval
 * @param A_ptr_func the function to be called after this interval
 */
void SYSTICK_vSetIntervalSingle(u32 A_u32Ticks, ptr_func_t A_ptr_func);

/**
 * @brief Interface Function to Set the Interval for periodic calls
 * 
 * @param A_u32Ticks the ticks needed for this interval
 * @param A_ptr_func the function to be called after this interval
 */
void SYSTICK_vSetIntervalPeriodic(u32 A_u32Ticks, ptr_func_t A_ptr_func);

/**
 * @brief Interface Function to set a busy wait for a specific time
 * 
 * @param A_u32Ticks the ticks needed for this busy wait
 */
void SYSTICK_vSetBusyWait(u32 A_u32Ticks);

/**
 * @brief Interface function to reset the systick
 * 
 * @note Resets the value of the VAL register
 * 
 */
void SYSTICK_vReset();


#endif // SYSTICK_INT_H