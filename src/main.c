/*
 * main.c
 *
 *  Created on: 12 Oct 2023
 *      Author: 20109
 */


/* LIB Inclusion  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Inclusion */
#include "RCC_int.h"
#include "DIO_int.h"
#include "NVIC_int.h"
#include "SYSTICK_int.h"
#include "UART_int.h"
#include "FPEC_int.h"

#include "PARSER/PARSER.h"

#define APP_FIRST_ADDRESS   0x08001004

volatile u8 endOfBLF = 0;
volatile u8 u8RecBuffer[100];
volatile u8 startParse = 0;
volatile u8 eraseState = 1;

void endBootLoader(void);
void uartHandler(u16 data);

int main() {
    /* System Clocks init */
    RCC_vInitSysClk();
    RCC_vEnableClk(RCC_APB2, USART1);
    RCC_vEnableClk(RCC_APB2, IOPA);
    RCC_vEnableClk(RCC_AHB, FLITF);

    /* BOOTLOADER LED */
//    DIO_vSetPinMode(PORTA_ID, PIN1_ID, OUTPUT_2MHZ_PP);
//    DIO_vSetPinVal(PORTA_ID, PIN1_ID, VAL_HIGH);

    /**
     * UART Initialise:
     * 1- UART 1 enable
     * 2- 9600 BAUD
     * 3- Read register not empty interrupt
     */
    UART_vInit();
    UART_vSetCallBack( &uartHandler, UART1_ID );
    NVIC_vEnableInterrupt(NVIC_USART1);

    /**
     * SysTick init
     * 1- AHB/8 clock
     */
    SYSTICK_vInit();

    /* Unlock the flash memory */
    FPEC_vUnlock();

    SYSTICK_vSetIntervalSingle(15000000, &endBootLoader);

    while(endOfBLF == 0) {
        if(startParse == 1) {
            Parser_voidParseRecord(&u8RecBuffer);
            UART_vSendString("ok", UART1_ID);
            SYSTICK_vTurnOn();
            startParse = 0;
        }
    }
}

void endBootLoader(void) {
    /* Definition for the vector table */
    #define SCB_VTOR   *((volatile u32*)0xE000ED08)

    ptr_func_t L_AppFirstAdd;

    /* The Start Of The Victor table: Start with stack pointer */
	SCB_VTOR = 0x08001000;

    L_AppFirstAdd = *((ptr_func_t*) APP_FIRST_ADDRESS);

    /* Start The Application Code */
    L_AppFirstAdd();
}

void uartHandler(u16 data) {
    static u8 u8RecIndex = 0;

    /* Received New Data: Reset The Timeout to 5 seconds */
    SYSTICK_vTurnOff();
    SYSTICK_vSetIntervalSingle(5000000, &endBootLoader);

    if(data == '\n') {
    	/* If The First Record Has Been Received, Erase The Application Flash Area */
        if( eraseState == 1) {
            FPEC_vEraseAppArea();
            eraseState = 0;
        }
    	/* New Record Has Been Received, Parse the Record */
        startParse = 1;

        /* Reset The Index ( For New Records ) */
        u8RecIndex = 0;
    } else {
    	/* Save The New Data Received */
        u8RecBuffer[u8RecIndex++] = (u8)data;
    }
}




