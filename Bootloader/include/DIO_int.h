/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DIO			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 08 APRIL 2023	 	**************/
/*********************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_

/* In register CRL  */
#define PIN0_ID  0
#define PIN1_ID  1
#define PIN2_ID  2
#define PIN3_ID  3
#define PIN4_ID  4
#define PIN5_ID  5
#define PIN6_ID  6
#define PIN7_ID  7

/* In register CRH  */
#define PIN8_ID  8
#define PIN9_ID  9
#define PIN10_ID 10
#define PIN11_ID 11
#define PIN12_ID 12
#define PIN13_ID 13
#define PIN14_ID 14
#define PIN15_ID 15

/* Available Ports*/
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2

/* Pin states */
#define VAL_LOW  0
#define VAL_HIGH 1

/* Pin Direction: For compatibility with AVR COTS */
#define DIR_INPUT  0
#define DIR_OUTPUT 1


/* Available Modes */
#define INPUT_FLOATING      0b0100
#define INPUT_PULLUP        0b1000
#define INPUT_PULLDOWN      0b1000
#define OUTPUT_10MHZ_PP     0b0001
#define OUTPUT_10MHZ_OD     0b0101
#define OUTPUT_10MHZ_AFPP   0b1001
#define OUTPUT_10MHZ_AFOD   0b1101
#define OUTPUT_2MHZ_PP      0b0010
#define OUTPUT_2MHZ_OD      0b0110
#define OUTPUT_2MHZ_AFPP    0b1010
#define OUTPUT_2MHZ_AFOD    0b1110
#define OUTPUT_50MHZ_PP     0b0011
#define OUTPUT_50MHZ_OD     0b0111
#define OUTPUT_50MHZ_AFPP   0b1011
#define OUTPUT_50MHZ_AFOD   0b1111

/**********************************************************************************************************
 * Description : Interface Function to Set a specific pin direction
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16), A_u8Mode -> Pin Direction (INPUT, OUTPUT)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Mode);

/**********************************************************************************************************
 * Description : Interface Function to Set a specific pin value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16), A_u8Value -> Pin Value (LOW, HIGH)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPinVal(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Value);

/**********************************************************************************************************
 * Description : Interface Function to Toggle a specific pin value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vTogPinVal(u8 A_u8PortId, u8 A_u8PinId);

/**********************************************************************************************************
 * Description : Interface Function to Set a specific port value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8Value -> Port Value (LOW, HIGH)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPortVal(u8 A_u8PortId, u8 A_u8Value);


/**********************************************************************************************************
 * Description : Interface Function to Get a specific pin value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
u8 DIO_u8GetPinVal(u8 A_u8PortId, u8 A_u8PinId);

/**********************************************************************************************************
 * Description : Interface Function to Get a specific port value
 * Outputs     : Port value
 * Inputs      : A_u8PortId -> Port ID (A, B, C)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
u16 DIO_u16GetPortVal(u8 A_u8PortId);

#endif /* DIO_INT_H_ */
