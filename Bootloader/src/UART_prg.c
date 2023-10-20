/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

/*          LIB Inclusion           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*          MCAL Inclusion          */
#include "DIO_int.h"

/*          Module Inclusion           */
#include "UART_pri.h"
#include "UART_cfg.h"
#include "UART_int.h"
#include "UART_reg.h"

/*          Global Variables            */
static ptr_func_Iu16_Ov G_Uart1CallBack = ADDRESS_NULL;
static ptr_func_Iu16_Ov G_Uart2CallBack = ADDRESS_NULL;
static ptr_func_Iu16_Ov G_Uart3CallBack = ADDRESS_NULL;



/**********************************************************************************************************
 * Description : Interface Function to Initialize the UART
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void UART_vInit(void){
    u16 L_u16Mantissa = 0;
    u8 L_u8Fraction = 0;
    #if UART1_STATE == UART_STATE_ENABLED

        DIO_vSetPinMode(PORTA_ID, PIN9_ID, OUTPUT_10MHZ_AFPP);	// TX pin
        DIO_vSetPinMode(PORTA_ID, PIN10_ID, INPUT_PULLUP);	// RX pin

        SET_BIT(USART1->CR1, UE); // Enable USART1
        SET_BIT(USART1->CR1, TE); // Enable TX
        SET_BIT(USART1->CR1, RE); // Enable RX

        #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
            SET_BIT(USART1->CR1, M); // 9-bit data
        #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

        #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
            SET_BIT(USART1->CR1, PCE); // Enable parity
        #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
            SET_BIT(USART1->CR1, PCE); // Enable parity
            SET_BIT(USART1->CR1, PS);  // Odd parity
            SET_BIT(USART1->CR1, M); // 9-bit data
        #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

        #if UART_STOP_BIT == UART_STOP_BIT_2
            SET_BIT(USART1->CR2, 13); // 2 stop bits
            CLR_BIT(USART1->CR2, 12);
            SET_BIT(USART1->CR1, M); // 9-bit data
        #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

        #if UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1
            SET_BIT(USART1->CR1, RXNEIE);
        #endif /* UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1 */

        L_u16Mantissa = (u16)UART1_BAUD_RATE;
        L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

        USART1->BRR = (L_u16Mantissa << 4) | L_u8Fraction;

    #endif /* UART1_STATE == UART_STATE_ENABLED */

    #if UART2_STATE == UART_STATE_ENABLED

        DIO_vSetPinMode(PORTA_ID, PIN2_ID, OUTPUT_10MHZ_AFPP);	// TX pin
        DIO_vSetPinMode(PORTA_ID, PIN3_ID, INPUT_PULLUP);	// RX pin

        SET_BIT(USART2->CR1, UE); // Enable USART2
        SET_BIT(USART2->CR1, TE); // Enable TX
        SET_BIT(USART2->CR1, RE); // Enable RX

        #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
            SET_BIT(USART2->CR1, M); // 9-bit data
        #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

        #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
            SET_BIT(USART2->CR1, PCE); // Enable parity
        #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
            SET_BIT(USART2->CR1, PCE); // Enable parity
            SET_BIT(USART2->CR1, PS);  // Odd parity
        #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

        #if UART_STOP_BIT == UART_STOP_BIT_2
            SET_BIT(USART2->CR2, 13); // 2 stop bits
            CLR_BIT(USART2->CR2, 12);
        #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

        #if UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1
            SET_BIT(USART2->CR1, RXNEIE);
        #endif /* UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1 */

        L_u16Mantissa = (u16)UART1_BAUD_RATE;
        L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

        USART2->BRR = (L_u16Mantissa << 4) | L_u8Fraction;



    #endif /* UART2_STATE == UART_STATE_ENABLED */

    #if UART3_STATE == UART_STATE_ENABLED

        DIO_vSetPinMode(PORTB_ID, PIN10_ID, OUTPUT_10MHZ_AFPP);	// TX pin
        DIO_vSetPinMode(PORTB_ID, PIN11_ID, INPUT_PULLUP);	// RX pin

        SET_BIT(USART3->CR1, UE); // Enable USART1
        SET_BIT(USART3->CR1, TE); // Enable TX
        SET_BIT(USART3->CR1, RE); // Enable RX

        #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
            SET_BIT(USART3->CR1, M); // 9-bit data
        #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

        #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
            SET_BIT(USART3->CR1, PCE); // Enable parity
        #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
            SET_BIT(USART3->CR1, PCE); // Enable parity
            SET_BIT(USART3->CR1, PS);  // Odd parity
        #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

        #if UART_STOP_BIT == UART_STOP_BIT_2
            SET_BIT(USART3->CR2, 13); // 2 stop bits
            CLR_BIT(USART3->CR2, 12);
        #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

        #if UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1
            SET_BIT(USART3->CR1, RXNEIE);
        #endif /* UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1 */

        L_u16Mantissa = (u16)UART1_BAUD_RATE;
        L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

        USART3->BRR = (L_u16Mantissa << 4) | L_u8Fraction;

    #endif /* UART3_STATE == UART_STATE_ENABLED */
}

/**********************************************************************************************************
 * Description : Interface Function to Initialize the UART1
 * Outputs     : void
 * Inputs      : void
 **********************************************************************************************************/
void UART_vInitUart1(void){
    u16 L_u16Mantissa = 0;
    u8 L_u8Fraction = 0;

    DIO_vSetPinMode(PORTA_ID, PIN9_ID, OUTPUT_10MHZ_AFPP);	// TX pin
    DIO_vSetPinMode(PORTA_ID, PIN10_ID, INPUT_PULLUP);	// RX pin

    SET_BIT(USART1->CR1, UE); // Enable USART1
    SET_BIT(USART1->CR1, TE); // Enable TX
    SET_BIT(USART1->CR1, RE); // Enable RX

    #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
        SET_BIT(USART1->CR1, M); // 9-bit data
    #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

    #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
        SET_BIT(USART1->CR1, PCE); // Enable parity
    #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
        SET_BIT(USART1->CR1, PCE); // Enable parity
        SET_BIT(USART1->CR1, PS);  // Odd parity
    #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

    #if UART_STOP_BIT == UART_STOP_BIT_2
        SET_BIT(USART1->CR2, 13); // 2 stop bits
        CLR_BIT(USART1->CR2, 12);
    #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

    #if UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1
        SET_BIT(USART1->CR1, RXNEIE);
    #endif /* UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1 */

    L_u16Mantissa = (u16)UART1_BAUD_RATE;
    L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

    USART1->BRR = (L_u16Mantissa << 4) | L_u8Fraction;
}


/**********************************************************************************************************
 * Description : Interface Function to Initialize the UART2
 * Outputs     : void
 * Inputs      : void
 **********************************************************************************************************/
void UART_vInitUart2(void){
    u16 L_u16Mantissa = 0;
    u8 L_u8Fraction = 0;

    DIO_vSetPinMode(PORTA_ID, PIN2_ID, OUTPUT_10MHZ_AFPP);	// TX pin
    DIO_vSetPinMode(PORTA_ID, PIN3_ID, INPUT_FLOATING);	// RX pin

    SET_BIT(USART2->CR1, UE); // Enable USART2
    SET_BIT(USART2->CR1, TE); // Enable TX
    SET_BIT(USART2->CR1, RE); // Enable RX

    #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
        SET_BIT(USART2->CR1, M); // 9-bit data
    #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

    #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
        SET_BIT(USART2->CR1, PCE); // Enable parity
    #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
        SET_BIT(USART2->CR1, PCE); // Enable parity
        SET_BIT(USART2->CR1, PS);  // Odd parity
    #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

    #if UART_STOP_BIT == UART_STOP_BIT_2
        SET_BIT(USART2->CR2, 13); // 2 stop bits
        CLR_BIT(USART2->CR2, 12);
    #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

    #if UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1
        SET_BIT(USART2->CR1, RXNEIE);
    #endif /* UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1 */

    L_u16Mantissa = (u16)UART1_BAUD_RATE;
    L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

    USART2->BRR = (L_u16Mantissa << 4) | L_u8Fraction;
}


/**********************************************************************************************************
 * Description : Interface Function to Initialize the UART3
 * Outputs     : void
 * Inputs      : void
 **********************************************************************************************************/
void UART_vInitUart3(void){
    u16 L_u16Mantissa = 0;
    u8 L_u8Fraction = 0;

    DIO_vSetPinMode(PORTB_ID, PIN10_ID, OUTPUT_10MHZ_AFPP);	// TX pin
    DIO_vSetPinMode(PORTB_ID, PIN11_ID, INPUT_PULLUP);	// RX pin

    SET_BIT(USART3->CR1, UE); // Enable USART1
    SET_BIT(USART3->CR1, TE); // Enable TX
    SET_BIT(USART3->CR1, RE); // Enable RX

    #if UART_DATA_LENGTH == UART_DATA_LENGTH_9
        SET_BIT(USART3->CR1, M); // 9-bit data
    #endif /* UART_DATA_LENGTH == UART_DATA_LENGTH_9 */

    #if UART_PARITY_MODE == UART_PARITY_MODE_EVEN
        SET_BIT(USART3->CR1, PCE); // Enable parity
    #elif UART_PARITY_MODE == UART_PARITY_MODE_ODD
        SET_BIT(USART3->CR1, PCE); // Enable parity
        SET_BIT(USART3->CR1, PS);  // Odd parity
    #endif /* UART_PARITY_MODE == UART_PARITY_MODE_EVEN */

    #if UART_STOP_BIT == UART_STOP_BIT_2
        SET_BIT(USART3->CR2, 13); // 2 stop bits
        CLR_BIT(USART3->CR2, 12);
    #endif /* UART_STOP_BIT == UART_STOP_BIT_2 */

    #if UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1
        SET_BIT(USART3->CR1, RXNEIE);
    #endif /* UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE == 1 */

    L_u16Mantissa = (u16)UART1_BAUD_RATE;
    L_u8Fraction = (u8)((UART1_BAUD_RATE - L_u16Mantissa) * 16.0);

    USART3->BRR = (L_u16Mantissa << 4) | L_u8Fraction;
}

/**********************************************************************************************************
 * Description : Interface Function to Send a Byte
 * Outputs     : void
 * Inputs      : Byte to be sent, UART ID
 ***********************************************************************************************************/
void UART_vSendByte(u8 A_u8Data, UART_ENUM A_u8UartId){
    switch(A_u8UartId){
        case UART1_ID:
            USART1->DR = A_u8Data;
            while(!GET_BIT(USART1->SR, TXE));
            break;
        case UART2_ID:
            USART2->DR = A_u8Data;
            while(!GET_BIT(USART2->SR, TXE));
            break;
        case UART3_ID:
            USART3->DR = A_u8Data;
            while(!GET_BIT(USART3->SR, TXE));
            break;
        default:
            break;
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Send a String
 * Outputs     : void
 * Inputs      : String to be sent, UART ID
 ***********************************************************************************************************/
void UART_vSendString(u8 *A_u8Data, UART_ENUM A_u8UartId){
    u8 L_u8Index = 0;
    while(A_u8Data[L_u8Index] != '\0'){
        UART_vSendByte(A_u8Data[L_u8Index], A_u8UartId);
        L_u8Index++;
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Receive a Byte
 * Outputs     : Received Byte
 * Inputs      : UART ID
 ***********************************************************************************************************/
u8 UART_u8ReceiveByte(UART_ENUM A_u8UartId){
    u8 L_u8Data = 0;
    switch(A_u8UartId){
        case UART1_ID:
            while(!GET_BIT(USART1->SR, RXNE));
            L_u8Data = USART1->DR;
            break;
        case UART2_ID:
            while(!GET_BIT(USART2->SR, RXNE));
            L_u8Data = USART2->DR;
            break;
        case UART3_ID:
            while(!GET_BIT(USART3->SR, RXNE));
            L_u8Data = USART3->DR;
            break;
        default:
            break;
    }
    return L_u8Data;
}

/**********************************************************************************************************
 * Description : Interface Function to Receive a String
 * Outputs     : void
 * Inputs      : String to be received, UART ID
 * NOTE        : String must be terminated by '\r'
 ***********************************************************************************************************/
void UART_vReceiveString(u8 *A_u8Data, UART_ENUM A_u8UartId){
    u8 L_u8Index = 0;
    A_u8Data[L_u8Index] = UART_u8ReceiveByte(A_u8UartId);
    while(A_u8Data[L_u8Index] != '\r'){
        L_u8Index++;
        A_u8Data[L_u8Index] = UART_u8ReceiveByte(A_u8UartId);
    }
    A_u8Data[L_u8Index] = '\0';
}

/**********************************************************************************************************
 * Description : Interface Function to Set Call Back Function
 * Outputs     : void
 * Inputs      : Pointer to Call Back Function, UART ID
 ***********************************************************************************************************/
void UART_vSetCallBack(ptr_func_Iu16_Ov A_ptr, UART_ENUM A_u8UartId){
    switch(A_u8UartId){
        case UART1_ID:
            G_Uart1CallBack = A_ptr;
            break;
        case UART2_ID:
            G_Uart2CallBack = A_ptr;
            break;
        case UART3_ID:
            G_Uart3CallBack = A_ptr;
            break;
        default:
            break;
    }
}

// /**
//  * @brief   This function is used to setup the DMA for UART1 TX 
//  * 
//  * @param A_DmaCfg              DMA configuration structure for UART1_TX channel
//  * @param A_u32SourceAddress    Pointer to the source address
//  * @param A_u16BlockLength      Length of the block to be transmitted
//  * 
//  * @note   This function uses channel 4 of DMA1, so please make sure that this channel is not used by any other peripheral
//  */
// void UART_vSetupDMA_UART1_TX(DMA_CFG_t* A_DmaCfg, u32* A_u32SourceAddress, u16 A_u16BlockLength){
//     /* Enable UART TX DMA*/
//     SET_BIT(USART1->CR3, DMAT);

//     DMA_vInit(&A_DmaCfg);

//     DMA_vStartTransaction(&A_DmaCfg, A_u32SourceAddress, (u32*)&(USART1->DR), A_u16BlockLength);
// }

// /**
//  * @brief   This function is used to setup the DMA for UART1 RX and uses channel 5 of DMA1
//  * 
//  * @param A_DmaCfg                  DMA configuration structure for UART1_RX channel
//  * @param A_u32DestinationAddress   Pointer to the destination address
//  * @param A_u16BlockLength          Length of the block to be received
//  * 
//  * @note   This function uses channel 5 of DMA1, so please make sure that this channel is not used by any other peripheral
//  */
// void UART_vSetupDMA_UART1_RX(DMA_CFG_t* A_DmaCfg, u32* A_u32DestinationAddress, u16 A_u16BlockLength){
//     /* Enable UART RX DMA*/
//     SET_BIT(USART1->CR3, DMAR);

//     DMA_vInit(&A_DmaCfg);

//     DMA_vStartTransaction(&A_DmaCfg, (u32*)&(USART1->DR), A_u32DestinationAddress, A_u16BlockLength);
// }

// /**
//  * @brief This function is used to setup the DMA for UART2 TX and uses channel 7 of DMA1
//  * 
//  * @param A_DmaCfg              DMA configuration structure for UART2_TX channel
//  * @param A_u32SourceAddress    Pointer to the source address
//  * @param A_u16BlockLength      Length of the block to be transmitted
//  */
// void UART_vSetupDMA_UART2_TX(DMA_CFG_t* A_DmaCfg, u32* A_u32SourceAddress, u16 A_u16BlockLength){

// }

// /**
//  * @brief This function is used to setup the DMA for UART2 RX and uses channel 6 of DMA1
//  * 
//  * @param A_DmaCfg                  DMA configuration structure for UART2_RX channel
//  * @param A_u32DestinationAddress   Pointer to the destination address
//  * @param A_u16BlockLength          Length of the block to be received
//  */
// void UART_vSetupDMA_UART2_RX(DMA_CFG_t* A_DmaCfg, u32* A_u32DestinationAddress, u16 A_u16BlockLength){

// }

// /**
//  * @brief This function is used to setup the DMA for UART3 TX and uses channel 2 of DMA1
//  * 
//  * @param A_DmaCfg              DMA configuration structure for UART3_TX channel
//  * @param A_u32SourceAddress    Pointer to the source address
//  * @param A_u16BlockLength      Length of the block to be transmitted
//  */
// void UART_vSetupDMA_UART3_TX(DMA_CFG_t* A_DmaCfg, u32* A_u32SourceAddress, u16 A_u16BlockLength){

// }

// /**
//  * @brief This function is used to setup the DMA for UART3 RX and uses channel 3 of DMA1
//  * 
//  * @param A_DmaCfg                  DMA configuration structure for UART3_RX channel
//  * @param A_u32DestinationAddress   Pointer to the destination address
//  * @param A_u16BlockLength          Length of the block to be received
//  */
// void UART_vSetupDMA_UART3_RX(DMA_CFG_t* A_DmaCfg, u32* A_u32DestinationAddress, u16 A_u16BlockLength){

// }

/* Only Used for RXNE */
void USART1_IRQHandler() {
    if(G_Uart1CallBack != ADDRESS_NULL){
        G_Uart1CallBack( USART1->DR );
    } else {
        USART1->DR;
    }
}

/* Only Used for RXNE */
void USART2_IRQHandler() {
    if(G_Uart2CallBack != ADDRESS_NULL){
        G_Uart2CallBack( USART2->DR );
    } else {
        USART2->DR;
    }
}

/* Only Used for RXNE */
void USART3_IRQHandler() {
    if(G_Uart3CallBack != ADDRESS_NULL){
        G_Uart3CallBack( USART3->DR );
    } else {
        USART3->DR;
    }
}
