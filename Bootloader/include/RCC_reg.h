/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: RCC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 07 APRIL 2023	 	**************/
/*********************************************************/
#ifndef RCC_REG_H
#define RCC_REG_H

/* BaseAddress:	0x40021000 */ 

/*	Clock control register	*/
#define RCC_CR			*((volatile u32*) 0x40021000)
/*  Bits:
*   Notes: Bits 2 and 26 to 31 are reserved
*/
#define HSION			0
#define HSIRDY			1
#define HSITRIM			3
#define HSICAL			8
#define HSEON			16
#define HSERDY			17
#define HSEBYP			18
#define CSSON			19
#define PLLON			24
#define PLLRDY			25

/*	Clock configuration register	*/
#define RCC_CFGR		*((volatile u32*) 0x40021004)
/*  Bits:
*   Notes: Bits 2 and 26 to 31 are reserved
*/
#define SW0				0
#define SW1				1
#define SWS				2
#define HPRE			4
#define PPRE1			8
#define PPRE2			11
#define ADCPRE			14
#define PLLSRC			16
#define PLLXTPRE		17
#define PLLMUL			18
#define MCO				24


/*	Clock interrupt register	*/
#define RCC_CIR			*((volatile u32*) 0x40021008)
/* Bits:    */
#define LSIRDYF			0
#define LSERDYF			1
#define HSIRDYF			2
#define HSERDYF			3
#define PLLRDYF			4
#define CSSF			7
#define LSIRDYIE		8
#define LSERDYIE		9
#define HSIRDYIE		10
#define HSERDYIE		11
#define PLLRDYIE		12
#define LSIRDYC			16
#define LSERDYC			17
#define HSIRDYC			18
#define HSERDYC			19
#define PLLRDYC			20
#define CSSC			23


/*	APB2 peripheral reset register	*/
#define RCC_APB2RSTR	*((volatile u32*) 0x4002100C)
/* Bits:    */
#define AFIO			0
#define IOPA			2
#define IOPB			3
#define IOPC			4
#define IOPD			5
#define IOPE			6
#define IOPF			7
#define IOPG			8
#define ADC1			9
#define ADC2			10
#define TIM1			11
#define SPI1			12
#define TIM8			13
#define USART1			14
#define ADC3			15
#define TIM9			19
#define TIM10			20
#define TIM11			21


/*	APB1 peripheral reset register	*/
#define RCC_APB1RSTR	*((volatile u32*) 0x40021010)
/* Bits:    */
#define TIM2			0
#define TIM3			1
#define TIM4			2
#define TIM5			3
#define TIM6			4
#define TIM7			5
#define TIM12			6
#define TIM13			7
#define TIM14			8
#define WWDG			11
#define SPI2			14
#define SPI3			15
#define USART2			17
#define USART3			18
#define USART4			19
#define USART5			20
#define I2C1			21
#define I2C2			22
#define USB				23
#define CAN				25
#define BKP				27
#define PWR				28
#define DAC				29


/*	AHB peripheral clock enable register	*/
#define RCC_AHBENR		*((volatile u32*) 0x40021014)
/* Bits:    */
#define DMA1			0
#define DMA2			1
#define SRAM			2
#define FLITF			4
#define CRC				6
#define FSMC			8
#define SDIO			10


/*	APB2 peripheral clock enable register	*/
#define RCC_APB2ENR		*((volatile u32*) 0x40021018)
/* Bits:    */
#define AFIO			0
#define IOPA			2
#define IOPB			3
#define IOPC			4
#define IOPD			5
#define IOPE			6
#define IOPF			7
#define IOPG			8
#define ADC1			9
#define ADC2			10
#define TIM1			11
#define SPI1			12
#define TIM8			13
#define USART1			14
#define ADC3			15
#define TIM9			19
#define TIM10			20
#define TIM11			21


/*	APB1 peripheral clock enable register	*/
#define RCC_APB1ENR		*((volatile u32*) 0x4002101C)
/* Bits:    */
#define TIM2			0
#define TIM3			1
#define TIM4			2
#define TIM5			3
#define TIM6			4
#define TIM7			5
#define TIM12			6
#define TIM13			7
#define TIM14			8
#define WWDG			11
#define SPI2			14
#define SPI3			15
#define USART2			17
#define USART3			18
#define USART4			19
#define USART5			20
#define I2C1			21
#define I2C2			22
#define USB				23
#define CAN				25
#define BKP				27
#define PWR				28
#define DAC				29

/*	Backup domain control register	*/
#define RCC_BDCR		*(volatile (u32*) 0x40021020)
/* Bits:    */
#define LSEON			0
#define LSERDY			1
#define LSEBYP			2
#define RTCSEL			8
#define RTCEN			15
#define BDRST			16


/*	Control/status register	*/
#define RCC_CSR			*(volatile (u32*) 0x40021024)
/* Bits:    */
#define LSION			0
#define LSIRDY			1
#define RMVF			24
#define PINRSTF		    26
#define PORRSTF		    27
#define SFTRSTF		    28
#define IWDGRSTF	    29
#define WWDGRSTF		30

#define FLASH_ACR		*((volatile u32*) 0x40022000)
/*Bits :*/
#define LATENCY 0


/* MODES FOR LATENCY */
#define TWO_WAIT_STATES		0b010
#define ONE_WAIT_STATES		0b001
#define ZERO_WAIT_STATES	0b000

#endif
