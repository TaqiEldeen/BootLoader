/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/

#ifndef NVIC_REG_H_
#define NVIC_REG_H_

#define NVIC_BASE_ADDRESS		0xE000E100

/*      Interrupt set-enable registers       */
#define NVIC_ISER0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x000))      
#define NVIC_ISER1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x004))   

/*      Interrupt clear-enable registers     */
#define NVIC_ICER0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x084))

/*      Interrupt set-pending registers      */
#define NVIC_ISPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))

/*      Interrupt clear-pending registers    */
#define NVIC_ICPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x184))

/*      Interrupt active bit registers       */
#define NVIC_IABR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))

/*      Interrupt priority registers
*       This register is byte accessible
*       So we will use an array to access it
*       Therefore we dont dereference it here
*/
#define NVIC_IPR				 ((volatile u8*)(NVIC_BASE_ADDRESS + 0x300))

/*      Software trigger interrupt register  */
#define NVIC_STIR				*((volatile u32*)(NVIC_BASE_ADDRESS + 0xE00))

/*      System control block_Application Interrupt and Reset Control Register       
*       This register is used to set the priority group
*       So we will use it in the NVIC driver
*       The most significant 2 bytes is the lock key = 0x05FA
*/
#define SCB_AIRCR				*((volatile u32*)(0xE000ED0C))

#endif /* NVIC_REG_H_ */