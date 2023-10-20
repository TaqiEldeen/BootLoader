/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: RCC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 07 APRIL 2023	 	**************/
/*********************************************************/

#ifndef RCC_INT_H
#define RCC_INT_H

#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

typedef enum {
    DMA1 = 0,
    DMA2,
    SRAM,
    FLITF = 4,
    CRC = 6,
    FSMC = 8,
    SDIO = 10,
    AFIO = 0,
    IOPA = 2,
    IOPB,
    IOPC,
    ICPD,
    IOPE,
    IOPF,
    IOPG,
    ADC1,
    ADC2,
    TIM1,
    SPI1,
    TIM8,
    USART1,
    ADC3,
    TIM9 = 19,
    TIM10,
    TIM11,
    TIM2 = 0,
    TIM3,
    TIM4,
    TIM5,
    TIM6,
    TIM7,
    TIM12,
    TIM13,
    TIM14,
    WWDG = 11,
    SPI2 = 14,
    SPI3,
    USART2 = 17,
    USART3,
    USART4,
    USART5,
    I2C1,
    I2C2,
    PWR = 28,
    DAC
}peripheral_t;


/**********************************************************************************************************
 * Description : Interface Function to Disable a clock for a specific peripheral
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8BusId -> Bus ID (AHB, APB1, APB2), A_u8PerId -> Peripheral ID
 ***********************************************************************************************************/
void RCC_vDisableClk(u8 A_u8BusId, u8 A_u8PerId );

/**********************************************************************************************************
 * Description : Interface Function to Enable a clock for a specific peripheral
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8BusId -> Bus ID (AHB, APB1, APB2), A_u8PerId -> Peripheral ID
 ***********************************************************************************************************/
void RCC_vEnableClk(u8 A_u8BusId, u8 A_u8PerId );

/**********************************************************************************************************
 * Description : Interface Function to Initialize the System Clock
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : None
 ***********************************************************************************************************/
void RCC_vInitSysClk(void);

/**********************************************************************************************************
 * Description : Interface Function to Set the ADC Prescaler
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PreScaler -> ADC Prescaler
 ***********************************************************************************************************/
void RCC_vSetADCPreScaler(u8 A_u8PreScaler);


#endif
