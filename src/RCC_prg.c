/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: RCC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 07 APRIL 2023	 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_pri.h"
#include "RCC_cfg.h"
#include "RCC_reg.h"

/**********************************************************************************************************
 * Description : Interface Function to Disable a clock for a specific peripheral
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8BusId -> Bus ID (AHB, APB1, APB2), A_u8PerId -> Peripheral ID
 ***********************************************************************************************************/
void RCC_vInitSysClk( void ) {
	RCC_CR   = 0x00000083;	/* Enable HSI */

	RCC_CFGR = 0x00000000;	/* Use HSI */

	RCC_CR  &= ~((1<<PLLON) | (1<<HSEON) | (1<<CSSON));

	/* Apply busses prescaler */
	RCC_CFGR |= (   (APB2_PRESCALLER << PPRE2)
				  | (APB1_PRESCALLER << PPRE1)
				  | (AHB_PRESCALLER  << HPRE)
				);

	/*	Select system clock source	*/
	#if RCC_SYSCLK_SELECT == HSI_SELECT
		RCC_vInitHSI();
	#elif RCC_SYSCLK_SELECT == HSE_CRYSTAL_SELECT || RCC_SYSCLK_SELECT == HSE_RC_SELECT
		RCC_vInitHSE();
	#elif RCC_SYSCLK_SELECT == PLL_SELECT
		RCC_vInitPLL();
	#else
		#error "Wrong system clock selection!"
	#endif

}

/**********************************************************************************************************
 * Description : Private Function to Init HSI Based on configuration
 * Outputs     : VOID
 * Inputs      : VOID
 ***********************************************************************************************************/
static void RCC_vInitHSI(){
	/*	Enable HSI	*/
	SET_BIT(RCC_CR, HSION);

	/*	Wait till HSI is ready	*/
	while( GET_BIT(RCC_CR, HSIRDY) == 0 );

	/*	Select HSI as system clock	*/
	RCC_CFGR &= ~( (1 << SW0) | (1 << SW1));
}

/**********************************************************************************************************
 * Description : Private Function to Init HSE Based on configuration
 * Outputs     : VOID
 * Inputs      : VOID
 ***********************************************************************************************************/
static void RCC_vInitHSE(){
	/*	Enable HSE	*/
	SET_BIT(RCC_CR, HSEON);

	#if RCC_SYSCLK_SELECT == HSE_CRYSTAL_SELECT
		/*	Select HSE crystal oscillator as HSE clock source	*/
		CLR_BIT(RCC_CR, HSEBYP);
	#elif RCC_SYSCLK_SELECT == HSE_RC_SELECT
		/*	Select HSE RC oscillator as HSE clock source	*/
		SET_BIT(RCC_CR, HSEBYP);
	#endif

	/*	Wait till HSE is ready	*/
	while( GET_BIT(RCC_CR, HSERDY) == 0 );
	
	/*	Select HSE as system clock	*/
	SET_BIT(RCC_CFGR, SW0);
	CLR_BIT(RCC_CFGR, SW1);
}

/**********************************************************************************************************
 * Description : Private Function to Init PLL Based on configuration
 * Outputs     : VOID
 * Inputs      : VOID
 ***********************************************************************************************************/
static void RCC_vInitPLL(){

#if RCC_SYSCLK_SELECT == PLL_SELECT
	RCC_CFGR &= PLL_MUL_MASK ;
	RCC_CFGR |= (PLL_MUL_SELECT << PLLMUL);
#endif
	#if PLL_SRC_SELECT == HSI_DIV_2_PLL
		/*	Enable HSI	*/
		SET_BIT(RCC_CR, HSION);

		/*	Wait till HSI is ready	*/
		while( GET_BIT(RCC_CR, HSIRDY) == 0 );

		/*	Select HSI/2 as PLL entry clock source	*/
		CLR_BIT(RCC_CFGR, PLLSRC);
		CLR_BIT(RCC_CFGR, PLLXTPRE);

	#elif PLL_SRC_SELECT == HSE_PLL

		/* Selecting HSE type */
		#if PLL_HSE_SRC_SELECT == HSE_CRYSTAL_SELECT
			/*	Select HSE crystal oscillator as HSE clock source	*/
			CLR_BIT(RCC_CR, HSEBYP);
		#elif PLL_HSE_SRC_SELECT == HSE_RC_SELECT
			/*	Select HSE RC oscillator as HSE clock source	*/
			SET_BIT(RCC_CR, HSEBYP);
		#else
			#error "Wrong HSE clock source selection!"
		#endif

		/*	Enable HSE	*/
		SET_BIT(RCC_CR, HSEON);

		/* Wait for HSE to be RDY */
		while( GET_BIT(RCC_CR, HSERDY) == 0 );

		/* Selecting HSE divider */
		#if PLL_HSE_DIV == PLL_HSE_NOT_DIV
			/*	Select HSE as PLL entry clock source	*/
			CLR_BIT(RCC_CFGR, PLLXTPRE);
			SET_BIT(RCC_CFGR, PLLSRC);

		#elif PLL_HSE_DIV == PLL_HSE_DIV_2
			/*	Select HSE/2 as PLL entry clock source	*/
			SET_BIT(RCC_CFGR, PLLXTPRE);
			SET_BIT(RCC_CFGR, PLLSRC);
		#else
			#error "Wrong PLL entry clock source selection!"
		#endif
		
	#else
		#error "Wrong PLL entry clock source selection!"
	#endif

	/*	Enable PLL	*/
	SET_BIT(RCC_CR, PLLON);

	/*	Wait till PLL is ready	*/
	while( GET_BIT(RCC_CR, PLLRDY) == 0 );

	/*	Select PLL as system clock	*/
	RCC_CFGR |=  ( 1 << SW1) ;
}


/**********************************************************************************************************
 * Description : Interface Function to Enable a clock for a specific peripheral
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8BusId -> Bus ID (AHB, APB1, APB2), A_u8PerId -> Peripheral ID
 ***********************************************************************************************************/
void RCC_vEnableClk( u8 A_u8BusId, u8 A_u8PerId ){
	if(A_u8PerId <= 31) {
		switch(A_u8BusId) {
			case RCC_AHB  :	SET_BIT(RCC_AHBENR  ,A_u8PerId);	break;
			case RCC_APB1 :	SET_BIT(RCC_APB1ENR ,A_u8PerId);	break;
			case RCC_APB2 :	SET_BIT(RCC_APB2ENR ,A_u8PerId);	break;
			default: /* Error */ break;
		}
	} else {
		/* Return error	*/
	}
}

/**********************************************************************************************************
 * Description : Interface Function to Initialize the System Clock
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : None
 ***********************************************************************************************************/
void RCC_vDisableClk( u8 A_u8BusId, u8 A_u8PerId ){
	if(A_u8PerId <= 31) {
		switch(A_u8BusId) {
			case RCC_AHB  :	CLR_BIT(RCC_AHBENR  ,A_u8PerId);	break;
			case RCC_APB1 :	CLR_BIT(RCC_APB1ENR ,A_u8PerId);	break;
			case RCC_APB2 :	CLR_BIT(RCC_APB2ENR ,A_u8PerId);	break;
			default: /* Error */ break;
		}
	} else {
		/* Return error	*/
	}
}


/**********************************************************************************************************
 * Description : Interface Function to Set the ADC Prescaler
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PreScaler -> ADC Prescaler
 ***********************************************************************************************************/
void RCC_vSetADCPreScaler(u8 A_u8PreScaler) {
	RCC_CFGR |= (A_u8PreScaler << 14);
}
