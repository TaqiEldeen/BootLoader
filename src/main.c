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

/* APP Inclusion */
#include "PARSER/PARSER.h"

/*****              MACROS                              *****/
#define APP_FIRST_ADDRESS   0x08001004



/*****              GLOBAL VARIABLES                    *****/
volatile u8 endOfBLF = 0;
volatile u8 u8RecBuffer[100];
volatile u8 startParse = 0;
volatile u8 eraseState = 1;
ptr_func_t G_AppFirstAdd;



/*****              Local Functions                    *****/

/**
 * @brief End the bootloader and start the application
 * 
 */
static void endBootLoader(void);

/**
 * @brief UART Handler for the bootloader
 * 
 * @param data 
 */
static void uartHandler(u16 data);

/**
 * @brief Initialise the system clocks
 * 
 */
static void initSystemClks(void);


int main() {
    /* System Clocks init */
    initSystemClks();

    /* BOOTLOADER LED */
    DIO_vSetPinMode(PORTA_ID, PIN1_ID, OUTPUT_2MHZ_PP);
    DIO_vSetPinVal(PORTA_ID, PIN1_ID, VAL_HIGH);

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

    HEX_RECORD_TYPE recordType;
    while(endOfBLF == 0) {

        /* Wait For Receiving New Record */
        if(startParse == 1) {
            /* Parse The Received Record */
            recordType = Parser_voidParseRecord(&u8RecBuffer);

            /* Check If It the last record */
            if(recordType == END_OF_FILE_RECORD) {
                endOfBLF = 1;
                endBootLoader();
            }

            /* Reply For The GUI APP To receive New Record */
            UART_vSendString("ok", UART1_ID);

            SYSTICK_vTurnOn();
            startParse = 0;
        }
    }

    /* Start The Application Code */
    G_AppFirstAdd();
}


/**
 * @brief End the bootloader and start the application
 * 
 */
static void endBootLoader(void) {
    /* Definition for the vector table */
    #define SCB_VTOR   *((volatile u32*)0xE000ED08)

    /* The Start Of The Victor table: Start with stack pointer */
	SCB_VTOR = 0x08001000;

	G_AppFirstAdd = *((ptr_func_t*) APP_FIRST_ADDRESS);

    DIO_vSetPinVal(PORTA_ID, PIN1_ID, VAL_LOW);

    /* Indicating The End Of BootLoader */
    endOfBLF = 1;
}


/**
 * @brief UART Handler for the bootloader
 * 
 * @param data 
 */
static void uartHandler(u16 data) {
    static u8 u8RecIndex = 0;

    /* Received New Data: Reset The Timeout to 5 seconds */
    SYSTICK_vTurnOff();

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
    SYSTICK_vReset();
    SYSTICK_vSetIntervalSingle(5000000, &endBootLoader);
}


/**
 * @brief Initialise the system clocks
 * 
 */
void initSystemClks(void) {
    RCC_vInitSysClk();
    RCC_vEnableClk(RCC_APB2, USART1);
    RCC_vEnableClk(RCC_APB2, IOPA);
    RCC_vEnableClk(RCC_AHB, FLITF);
}


