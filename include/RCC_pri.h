/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: RCC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 07 APRIL 2023	 	**************/
/*********************************************************/
#ifndef RCC_PRI_H
#define RCC_PRI_H

/******		System clock select		******/
#define HSI_SELECT		    0
#define HSE_CRYSTAL_SELECT	1
#define HSE_RC_SELECT	    2
#define PLL_SELECT		    3


/******		PLL entry clock source		******/	
#define HSI_DIV_2_PLL	0
#define HSE_PLL         1    

/******		PLL multiplication factor		******/	
#define PLL_MUL_2		0
#define PLL_MUL_3		1
#define PLL_MUL_4		2
#define PLL_MUL_5		3
#define PLL_MUL_6		4
#define PLL_MUL_7		5
#define PLL_MUL_8		6
#define PLL_MUL_9		7
#define PLL_MUL_10		8
#define PLL_MUL_11		9
#define PLL_MUL_12		10
#define PLL_MUL_13		11
#define PLL_MUL_14		12
#define PLL_MUL_15		13
#define PLL_MUL_16		14


/******		APB high-speed & low_speed prescaler		******/	
#define HCLK_NOT_DIVIDED	0
#define HCLK_DIV_2			4
#define HCLK_DIV_4			5
#define HCLK_DIV_8			6
#define HCLK_DIV_16			7

/******      AHB Prescaler      ******/
#define AHB_NOT_DIVIDED		0
#define AHB_DIV_2			8
#define AHB_DIV_4			9
#define AHB_DIV_8			10
#define AHB_DIV_16			11
#define AHB_DIV_64			12
#define AHB_DIV_128			13
#define AHB_DIV_256			14
#define AHB_DIV_512			15


/******		General ON/OFF macro		******/	
#define OFF		0
#define ON		1


/******		External high-speed clock bypass		******/	
#define	BYPASS		1
#define NO_BYPASS	0

/******      External Clock on board     ******/
#define HSE_CRYSTAL_8MHZ	(u32)8000000
#define HSE_CRYSTAL_12MHZ	(u32)12000000
#define HSE_CRYSTAL_16MHZ	(u32)16000000
#define HSE_CRYSTAL_24MHZ	(u32)24000000
#define HSE_CRYSTAL_32MHZ	(u32)32000000
#define HSE_CRYSTAL_48MHZ	(u32)48000000

/******		PLL HSE DIV		******/
#define PLL_HSE_DIV_2		1
#define PLL_HSE_NOT_DIV		0

/******		PLL MULTIPLIER MASK		******/
#define PLL_MUL_MASK		0xFFC3FFFF


/******     Private functions       ******/
static void RCC_vInitHSI();
static void RCC_vInitHSE();
static void RCC_vInitPLL();

#endif