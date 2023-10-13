/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef UART_CFG_H
#define UART_CFG_H

/*
*   UART interrupt enable/disable
*   Options: 1 -> Enable    , 0 -> Disable
*   Only supported RXNEIE
*/
#define UART_RX_COMPLETE_INTERRUPT_ENABLE               0
#define UART_TX_COMPLETE_INTERRUPT_ENABLE               0
#define UART_TRANSMIT_REGISTER_EMPTY_INTERRUPT_ENABLE   0
#define UART_READ_REGISTER_NOT_EMPTY_INTERRUPT_ENABLE   1       

/*
*   UART Data Length
*   Options:
*   1-  UART_DATA_LENGTH_8
*   2-  UART_DATA_LENGTH_9
*/
#define UART_DATA_LENGTH    UART_DATA_LENGTH_8

/*
*  UART Parity Mode
*  Options:
*  1-  UART_PARITY_MODE_DISABLED
*  2-  UART_PARITY_MODE_EVEN
*  3-  UART_PARITY_MODE_ODD     
*/
#define UART_PARITY_MODE    UART_PARITY_MODE_DISABLED

/*
*   UART Stop Bit
*   Options:
*   1-  UART_STOP_BIT_1
*   2-  UART_STOP_BIT_2
*/
#define UART_STOP_BIT       UART_STOP_BIT_1

/*
*   UART Baud Rate
*   Options:
*   1-  UART_8MHZ_BAUD_RATE_2400
*   2-  UART_8MHZ_BAUD_RATE_4800
*   3-  UART_8MHZ_BAUD_RATE_9600
*   4-  UART_8MHZ_BAUD_RATE_115200
*   NOTE: also supported 36MHZ and 72 MHZ
*/
#define UART1_BAUD_RATE      UART_8MHZ_BAUD_RATE_9600
#define UART2_BAUD_RATE      UART_8MHZ_BAUD_RATE_115200
#define UART3_BAUD_RATE      UART_8MHZ_BAUD_RATE_115200


/*
*   UART State
*   Options:
*   1-  UART_STATE_ENABLED
*   2-  UART_STATE_DISABLED
*/
#define UART1_STATE         UART_STATE_ENABLED
#define UART2_STATE         UART_STATE_DISABLED
#define UART3_STATE         UART_STATE_DISABLED


#endif /* UART_CFG_H */