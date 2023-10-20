/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef UART_INT_H
#define UART_INT_H

typedef enum {
    UART1_ID,
    UART2_ID,
    UART3_ID
}UART_ENUM;

/**********************************************************************************************************
 * Description : Interface Function to Initialize the UART
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void UART_vInit(void);

/**********************************************************************************************************
 * Description : Interface Function to Send a Byte
 * Outputs     : void
 * Inputs      : Byte to be sent, UART ID
 ***********************************************************************************************************/
void UART_vSendByte(u8 A_u8Data, UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Send a String
 * Outputs     : void
 * Inputs      : String to be sent, UART ID
 ***********************************************************************************************************/
void UART_vSendString(u8 *A_u8Data, UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Receive a Byte
 * Outputs     : Received Byte
 * Inputs      : UART ID
 ***********************************************************************************************************/
u8 UART_u8ReceiveByte(UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Receive a String
 * Outputs     : void
 * Inputs      : String to be received, UART ID
 ***********************************************************************************************************/
void UART_vReceiveString(u8 *A_u8Data, UART_ENUM A_u8UART_ID);

/**********************************************************************************************************
 * Description : Interface Function to Set Call Back Function
 * Outputs     : void
 * Inputs      : Pointer to Call Back Function, UART ID
 ***********************************************************************************************************/
void UART_vSetCallBack(ptr_func_Iu16_Ov A_ptr, UART_ENUM A_u8UartId);

///**
// * @brief   This function is used to setup the DMA for UART1 TX and uses channel 4 of DMA1
// *
// * @param A_u32SourceAddress    Pointer to the source address
// * @param A_u16BlockLength      Length of the block to be transmitted
// *
// */
//void UART_vSetupDMA_UART1_TX(DMA_CFG_t* A_DmaCfg, u32* A_u32SourceAddress, u16 A_u16BlockLength);
//
///**
// * @brief   This function is used to setup the DMA for UART1 RX and uses channel 5 of DMA1
// *
// * @param A_u32DestinationAddress   Pointer to the destination address
// * @param A_u16BlockLength          Length of the block to be received
// *
// */
//void UART_vSetupDMA_UART1_RX(DMA_CFG_t* A_DmaCfg, u32* A_u32DestinationAddress, u16 A_u16BlockLength);
//
///**
// * @brief This function is used to setup the DMA for UART2 TX and uses channel 7 of DMA1
// *
// * @param A_u32SourceAddress    Pointer to the source address
// * @param A_u16BlockLength      Length of the block to be transmitted
// */
//void UART_vSetupDMA_UART2_TX(DMA_CFG_t* A_DmaCfg, u32* A_u32SourceAddress, u16 A_u16BlockLength);
//
///**
// * @brief This function is used to setup the DMA for UART2 RX and uses channel 6 of DMA1
// *
// * @param A_u32DestinationAddress   Pointer to the destination address
// * @param A_u16BlockLength          Length of the block to be received
// */
//void UART_vSetupDMA_UART2_RX(DMA_CFG_t* A_DmaCfg, u32* A_u32DestinationAddress, u16 A_u16BlockLength);
//
///**
// * @brief This function is used to setup the DMA for UART3 TX and uses channel 2 of DMA1
// *
// * @param A_u32SourceAddress    Pointer to the source address
// * @param A_u16BlockLength      Length of the block to be transmitted
// */
//void UART_vSetupDMA_UART3_TX(DMA_CFG_t* A_DmaCfg, u32* A_u32SourceAddress, u16 A_u16BlockLength);
//
///**
// * @brief This function is used to setup the DMA for UART3 RX and uses channel 3 of DMA1
// *
// * @param A_u32DestinationAddress   Pointer to the destination address
// * @param A_u16BlockLength          Length of the block to be received
// */
//void UART_vSetupDMA_UART3_RX(DMA_CFG_t* A_DmaCfg, u32* A_u32DestinationAddress, u16 A_u16BlockLength);


#endif /* UART_INT_H */
