/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 APRIL 2023	 	**************/
/*********************************************************/

#ifndef UART_REG_H
#define UART_REG_H

#define USART_1_BASE_ADDRESS	0x40013800     /* On APB2 */
#define USART_2_BASE_ADDRESS	0x40004400     /* On APB1 */
#define USART_3_BASE_ADDRESS	0x40004800     /* On APB1 */

typedef struct
{
    volatile u32 SR;    /* Status Register */
    volatile u32 DR;    /* Data Register */
    volatile u32 BRR;   /* Baud Rate Register */
    volatile u32 CR1;   /* Control Register 1 */
    volatile u32 CR2;   /* Control Register 2 */
    volatile u32 CR3;   /* Control Register 3 */
    volatile u32 GTPR;  /* Guard Time and Prescaler Register */
}USART_T;


#define USART1	((volatile USART_T *) USART_1_BASE_ADDRESS)
#define USART2	((volatile USART_T *) USART_2_BASE_ADDRESS)
#define USART3	((volatile USART_T *) USART_3_BASE_ADDRESS)

/* Status register bits */
#define CTS        9
#define LBD        8
#define TXE        7
#define TC         6
#define RXNE       5
#define IDLE       4
#define ORE        3
#define NF         2
#define FE         1
#define PE         0

/* Control register 1 bits */
#define UE         13
#define M          12
#define WAKE       11
#define PCE        10
#define PS         9
#define PEIE       8
#define TXEIE      7
#define TCIE       6
#define RXNEIE     5
#define IDLEIE     4
#define TE         3
#define RE         2
#define RWU        1
#define SBK        0

/* Control register 2 bits */
#define LINEN      14
#define STOP       12
#define CLKEN      11
#define CPOL       10
#define CPHA       9
#define LBCL       8
#define LBDIE      6
#define LBDL       5
#define ADD        0

/* Control register 3 bits */
#define CTSIE      10
#define CTSE       9
#define RTSE       8
#define DMAT       7
#define DMAR       6
#define SCEN       5
#define NACK       4
#define HDSEL      3
#define IRLP       2
#define IREN       1
#define EIE        0

/* Guard time and prescaler register bits */
#define GT         8
#define PSC        0

#endif /* UART_REG_H */