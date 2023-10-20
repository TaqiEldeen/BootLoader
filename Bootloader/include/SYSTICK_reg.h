/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SYSTICK		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 APRIL 2023	 	**************/
/*********************************************************/
#ifndef SYSTICK_REG_H
#define SYSTICK_REG_H

#define SYSTICK_BASE_ADDRESS	0xE000E010

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}SYSTICK_t;

#define SYSTICK      ((volatile SYSTICK_t*) SYSTICK_BASE_ADDRESS)

/*  CTRL Bits  */
#define ENABLE      0
#define TICKINT     1
#define CLKSOURCE   2
#define COUNTFLAG   16


#endif // SYSTICK_REG_H