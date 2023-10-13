/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/
#ifndef SYSTICK_CFG_H
#define SYSTICK_CFG_H

/*
* Clock Source
* Options: 
*   1- SYSTICK_AHB_DIV_8
*   2- SYSTICK_AHB       
*/
#define SYSTICK_CLKSOURCE		SYSTICK_AHB_DIV_8

/*
* Interrupt Enable
* Options:
*   1- SYSTICK_INTERRUPT_ENABLE
*   2- SYSTICK_INTERRUPT_DISABLE
*/
#define SYSTICK_INTERRUPT		SYSTICK_INTERRUPT_ENABLE

/*
* Enable
* Options:
*   1- SYSTICK_ENABLE
*   2- SYSTICK_DISABLE
*/
#define SYSTICK_STATE			SYSTICK_ENABLE

/*
* Reload Value
* Options:
*   1- 0x00000000 to 0x00FFFFFF
*/
#define SYSTICK_RELOAD_VALUE	0x00FFFFFF


#endif  // SYSTICK_CFG_H
