/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: RCC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 07 APRIL 2023	 	**************/
/*********************************************************/

#ifndef RCC_CFG_H
#define RCC_CFG_H

/*
*	System clock select
*	Options:
*	1- HSI_SELECT
*	2- HSE_CRYSTAL_SELECT
*   3- HSE_RC_SELECT
*	4- PLL_SELECT        
*/
#define RCC_SYSCLK_SELECT	HSI_SELECT

/* Use this if only you chose PLL_SELECT */
#if RCC_SYSCLK_SELECT == PLL_SELECT
    /*
    *	PLL entry clock source
    *	Options:
    *	1- HSI_DIV_2_PLL
    *	2- HSE_PLL
    */
    #define PLL_SRC_SELECT	HSE_PLL

    /*
    *	PLL multiplication factor
    *	Options:
    *	1- 	PLL_MUL_2
    *	2- 	PLL_MUL_3
    *	3- 	PLL_MUL_4
    *	4- 	PLL_MUL_5
    *	5- 	PLL_MUL_6
    *	6- 	PLL_MUL_7
    *	7- 	PLL_MUL_8
    *	8- 	PLL_MUL_9
    *	9- 	PLL_MUL_10
    *	10- PLL_MUL_11
    *	11- PLL_MUL_12
    *	12- PLL_MUL_13
    *	13- PLL_MUL_14
    *	14- PLL_MUL_15
    *	15- PLL_MUL_16
    */
    #define PLL_MUL_SELECT	PLL_MUL_4

    /*
    *	PLL HSE clock source
    *	Options:
    *	1- HSE_CRYSTAL_SELECT
    *	2- HSE_RC_SELECT
    */
    #define PLL_HSE_SRC_SELECT HSE_CRYSTAL_SELECT

    /*
    *   PLL HSE DIV
    *   Options:
    *   1- PLL_HSE_DIV_2
    *   2- PLL_HSE_NOT_DIV
    */
    #define PLL_HSE_DIV PLL_HSE_NOT_DIV
#endif

/*
*  HSE crystal frequency
*  Options:
*  1- HSE_CRYSTAL_8MHZ
*  2- HSE_CRYSTAL_12MHZ
*  3- HSE_CRYSTAL_16MHZ
*  4- HSE_CRYSTAL_24MHZ
*  5- HSE_CRYSTAL_32MHZ
*  6- HSE_CRYSTAL_48MHZ
*/
#define HSE_CRYSTAL_FREQ	HSE_CRYSTAL_8MHZ


/*
*	APB high-speed prescaler (APB2)
*	Options:
*	1- HCLK_NOT_DIVIDED
*	2- HCLK_DIV_2
*	3- HCLK_DIV_4
*	4- HCLK_DIV_8
*	5- HCLK_DIV_16		
*/
#define APB2_PRESCALLER		HCLK_NOT_DIVIDED

/*
*	APB low-speed prescaler (APB1)
*	Options:
*	1- HCLK_NOT_DIVIDED
*	2- HCLK_DIV_2
*	3- HCLK_DIV_4
*	4- HCLK_DIV_8
*	5- HCLK_DIV_16
*	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
*/
#define APB1_PRESCALLER		HCLK_NOT_DIVIDED

/*
*   AHB prescaler
*   Options:
*   1- AHB_NOT_DIVIDED
*   2- AHB_DIV_2
*   3- AHB_DIV_4
*   4- AHB_DIV_8
*   5- AHB_DIV_16
*   6- AHB_DIV_64
*   7- AHB_DIV_128
*   8- AHB_DIV_256
*   9- AHB_DIV_512     
*/
#define AHB_PRESCALLER      AHB_NOT_DIVIDED


/*
*	PLL Enable
*	Options:
*	1- ON
*	2- OFF
*/
#define PLL_STATE	ON

/*
*	Clock security system enable
*	Options:
*	1- ON
*	2- OFF
*/
#define CLK_SEC_STATE	OFF

/*
*	External high-speed clock bypass
*	Options:
*	1- BYPASS
*	2- NO_BYPASS
*/
#define EXT_CLK_BYPASS_STATE	BYPASS

#endif
