/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef UART_PRI_H
#define UART_PRI_H

#define UART_DATA_LENGTH_8  0
#define UART_DATA_LENGTH_9  1


#define UART_PARITY_MODE_DISABLED   0
#define UART_PARITY_MODE_EVEN       1
#define UART_PARITY_MODE_ODD        2


#define UART_STOP_BIT_1         0
#define UART_STOP_BIT_2         1


/* fPCLK = 36 MHz */
#define UART_36MHZ_BAUD_RATE_2400     937.5f
#define UART_36MHZ_BAUD_RATE_4800	  468.75f
#define UART_36MHZ_BAUD_RATE_9600     234.375f
#define UART_36MHZ_BAUD_RATE_115200   19.5f

/* fPCLK = 8 MHz */
#define UART_8MHZ_BAUD_RATE_2400	 208.333f
#define UART_8MHZ_BAUD_RATE_4800	 104.166f
#define UART_8MHZ_BAUD_RATE_9600     52.0833f
#define UART_8MHZ_BAUD_RATE_115200	 4.34027f

/* fPCLK = 72 MHz */
#define UART_72MHZ_BAUD_RATE_2400	 1875.0f
#define UART_72MHZ_BAUD_RATE_4800	 937.5f
#define UART_72MHZ_BAUD_RATE_9600	 468.75f
#define UART_72MHZ_BAUD_RATE_115200	 39.0625f


#define UART_STATE_ENABLED      0
#define UART_STATE_DISABLED     1

#define DMA_UART1_RX_CH         DMA_CHANNEL_5      
#define DMA_UART1_TX_CH         DMA_CHANNEL_4

#define DMA_UART2_RX_CH         DMA_CHANNEL_6      
#define DMA_UART2_TX_CH         DMA_CHANNEL_7

#define DMA_UART3_RX_CH         DMA_CHANNEL_3
#define DMA_UART3_TX_CH         DMA_CHANNEL_2

#endif /* UART_PRI_H */