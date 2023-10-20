/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/

#ifndef NVIC_INT_H_
#define NVIC_INT_H_

typedef enum {
    /* Interrupts ID for STM32F103C8T6 */
    NVIC_WWDG = 0,
    NVIC_PVD,
    NVIC_TAMPER,
    NVIC_RTC,
    NVIC_FLASH,
    NVIC_RCC,
    NVIC_EXTI0,
    NVIC_EXTI1,
    NVIC_EXTI2,
    NVIC_EXTI3,
    NVIC_EXTI4,
    NVIC_DMA1_Channel1,
    NVIC_DMA1_Channel2,
    NVIC_DMA1_Channel3,
    NVIC_DMA1_Channel4,
    NVIC_DMA1_Channel5,
    NVIC_DMA1_Channel6,
    NVIC_DMA1_Channel7,
    NVIC_ADC1_2,
    NVIC_CAN1_TX,
    NVIC_CAN1_RX0,
    NVIC_CAN1_RX1,
    NVIC_CAN1_SCE,
    NVIC_EXTI9_5,
    NVIC_TIM1_BRK,
    NVIC_TIM1_UP,
    NVIC_TIM1_TRG_COM,
    NVIC_TIM1_CC,
    NVIC_TIM2,
    NVIC_TIM3,
    NVIC_TIM4,
    NVIC_I2C1_EV,
    NVIC_I2C1_ER,
    NVIC_I2C2_EV,
    NVIC_I2C2_ER,
    NVIC_SPI1,
    NVIC_SPI2,
    NVIC_USART1,
    NVIC_USART2,
    NVIC_USART3,
    NVIC_EXTI15_10,
    NVIC_RTCAlarm,
    NVIC_USBWakeUp,
    NVIC_TIM8_BRK,
    NVIC_TIM8_UP,
    NVIC_TIM8_TRG_COM,
    NVIC_TIM8_CC,
    NVIC_ADC3,
    NVIC_FSMC,
    NVIC_SDIO,
    NVIC_TIM5,
    NVIC_SPI3,
    NVIC_UART4,
    NVIC_UART5,
    NVIC_TIM6,
    NVIC_TIM7,
    NVIC_DMA2_Channel1,
    NVIC_DMA2_Channel2,
    NVIC_DMA2_Channel3,
    NVIC_DMA2_Channel4_5
}NVIC_ENUM;

/**********************************************************************************************************
 * Description : Interface Function to Enable Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vEnableInterrupt(u8 A_u8IntId );

/**********************************************************************************************************
 * Description : Interface Function to Disable Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_vDisableInterrupt(u8 A_u8IntId);

/**********************************************************************************************************
 * Description : Interface Function to Set Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vSetPendingInterrupt(u8 A_u8IntI);

/**********************************************************************************************************
 * Description : Interface Function to Clear Pending Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
void NVIC_vClearPendingInterrupt(u8 A_u8IntId );

/**********************************************************************************************************
 * Description : Interface Function to Get Active Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetActiveInterrupt(u8 A_u8IntId );

/**********************************************************************************************************
 * Description : Interface Function to Set Priority of Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number, Priority, Group Priority
 * NOTES       : This Function adaptes to the Priority Grouping chosen in the configuration file
 ***********************************************************************************************************/
void NVIC_vSetPriority(u8 A_u8IntI, u8 A_u8SubPriority, u8 A_u8GroupPriority);

/**********************************************************************************************************
 * Description : Interface Function to Get Priority of Interrupts in NVIC
 * Outputs     : Void
 * Inputs      : Interrupt Number
 ***********************************************************************************************************/
u8 NVIC_u8GetPriority(u8 A_u8IntId);


#endif /* NVIC_INT_H_ */