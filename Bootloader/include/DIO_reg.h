/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DIO			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 08 APRIL 2023	 	**************/
/*********************************************************/

#ifndef DIO_REG_H_
#define DIO_REG_H_

/******  GPIOA Registers    *******/
#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOA_CRL   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR  *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR  *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))


/******  GPIOB Registers    *******/
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOB_CRL   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSRR  *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCKR  *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))


/******  GPIOC Registers    *******/
#define GPIOC_BASE_ADDRESS 0x40011000
#define GPIOC_CRL   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSRR  *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCKR  *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))


#endif /* DIO_REG_H_ */