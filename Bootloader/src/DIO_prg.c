/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DIO			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 08 APRIL 2023	 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_reg.h"
#include "DIO_pri.h"
#include "DIO_cfg.h"

/**********************************************************************************************************
 * Description : Interface Function to Set a specific pin direction
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16), A_u8Mode -> Pin Direction (INPUT, OUTPUT)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Mode){
    if( A_u8PinId < 8 ){     /*	Check if the pin is in the first 8 pins of the port	*/
        switch (A_u8PortId)
        {
            case PORTA_ID:  
                GPIOA_CRL &= ~(0xF << (A_u8PinId * 4));     /* Clear the mode */
                GPIOA_CRL |= (A_u8Mode << (A_u8PinId * 4)); /* Set the mode */
                break;
            case PORTB_ID:
                GPIOB_CRL &= ~(0xF << (A_u8PinId * 4));     /* Clear the mode */
                GPIOB_CRL |= (A_u8Mode << (A_u8PinId * 4)); /* Set the mode */
                break;
            case PORTC_ID:
                GPIOC_CRL &= ~(0xF << (A_u8PinId * 4));     /* Clear the mode */
                GPIOC_CRL |= (A_u8Mode << (A_u8PinId * 4)); /* Set the mode */
                break;
            default:
                /*	Invalid PORT ID	*/
                break;
        }
    }
    else if(A_u8Mode < 16){ /*	Check if the pin is in the second 8 pins of the port	*/
        switch (A_u8PortId)
        {
            case PORTA_ID:  
                GPIOA_CRH &= ~(0xF << ((A_u8PinId - 8) * 4));     /* Clear the mode */
                GPIOA_CRH |= (A_u8Mode << ((A_u8PinId - 8) * 4)); /* Set the mode */
                break;
            case PORTB_ID:
                GPIOB_CRH &= ~(0xF << ((A_u8PinId - 8) * 4));     /* Clear the mode */
                GPIOB_CRH |= (A_u8Mode << ((A_u8PinId - 8) * 4)); /* Set the mode */
                break;
            case PORTC_ID:
                GPIOC_CRH &= ~(0xF << ((A_u8PinId - 8) * 4));     /* Clear the mode */
                GPIOC_CRH |= (A_u8Mode << ((A_u8PinId - 8) * 4)); /* Set the mode */
                break;
            default:
                /*	Invalid PORT ID	*/
                break;
        }
    }
    else{
        /*	Invalid PIN ID	*/
    } 
}

/**********************************************************************************************************
 * Description : Interface Function to Set a specific pin value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16), A_u8Value -> Pin Value (VAL_HIGH, VAL_LOW)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPinVal(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Value){
    if(A_u8PinId < 16) {
        if(A_u8Value == VAL_LOW){
            switch (A_u8PortId)
            {
                case PORTA_ID:  GPIOA_ODR &= ~(1 << A_u8PinId);  break;
                case PORTB_ID:  GPIOB_ODR &= ~(1 << A_u8PinId);  break;
                case PORTC_ID:  GPIOC_ODR &= ~(1 << A_u8PinId);  break;
                default:
                    /*	Invalid PORT ID	*/
                    break;
            }
        } else if(A_u8Value == VAL_HIGH) {
            switch (A_u8PortId)
            {
                case PORTA_ID:  GPIOA_ODR |= (1 << A_u8PinId);  break;
                case PORTB_ID:  GPIOB_ODR |= (1 << A_u8PinId);  break;
                case PORTC_ID:  GPIOC_ODR |= (1 << A_u8PinId);  break;
                default:
                    /*	Invalid PORT ID	*/
                    break;
            }
        } else {
            /*	Invalid PIN Value	*/
        }
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Get a specific pin value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16), A_u8Value -> Pin Value (VAL_HIGH, VAL_LOW)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
u8 DIO_u8GetPinVal(u8 A_u8PortId, u8 A_u8PinId){
    u8 L_u8Result = 0;
    if(A_u8PinId < 16) {
        switch (A_u8PortId)
        {
            case PORTA_ID:  L_u8Result = GET_BIT(GPIOA_IDR, A_u8PinId);  break;
            case PORTB_ID:  L_u8Result = GET_BIT(GPIOB_IDR, A_u8PinId);  break;
            case PORTC_ID:  L_u8Result = GET_BIT(GPIOC_IDR, A_u8PinId);  break;
            default:
                /*	Invalid PORT ID	*/
                break;
        }
    } else {
        /*	Invalid PIN ID	*/
    }
    return L_u8Result;
}

/**********************************************************************************************************
 * Description : Interface Function to Set a specific port direction
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8Mode -> Port Direction (INPUT, OUTPUT)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPortMode(u8 A_u8PortId, u8 A_u8Mode){
    switch (A_u8PortId)
    {
        case PORTA_ID:  GPIOA_CRL = A_u8Mode;  GPIOA_CRH = A_u8Mode;  break;
        case PORTB_ID:  GPIOB_CRL = A_u8Mode;  GPIOB_CRH = A_u8Mode;  break;
        case PORTC_ID:  GPIOC_CRL = A_u8Mode;  GPIOC_CRH = A_u8Mode;  break;
        default:
            /*	Invalid PORT ID	*/
            break;
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Set a specific port value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8Value -> Port Value (VAL_HIGH, VAL_LOW)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPortVal(u8 A_u8PortId, u8 A_u8Value){
    switch (A_u8PortId)
    {
        case PORTA_ID:  GPIOA_ODR = A_u8Value;  break;
        case PORTB_ID:  GPIOB_ODR = A_u8Value;  break;
        case PORTC_ID:  GPIOC_ODR = A_u8Value;  break;
        default:
            /*	Invalid PORT ID	*/
            break;
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Get a specific port value
 * Outputs     : Port value
 * Inputs      : A_u8PortId -> Port ID (A, B, C)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
u16 DIO_u16GetPortVal(u8 A_u8PortId){
    u16 L_u8Result = 0;
    switch (A_u8PortId)
    {
        case PORTA_ID:  L_u8Result = GPIOA_IDR;  break;
        case PORTB_ID:  L_u8Result = GPIOB_IDR;  break;
        case PORTC_ID:  L_u8Result = GPIOC_IDR;  break;
        default:
            /*	Invalid PORT ID	*/
            break;
    }
    return L_u8Result;
}

/**********************************************************************************************************
 * Description : Interface Function to Set a specific port pin direction
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16), A_u8Mode -> Pin Direction (DIR_INPUT, DIR_OUTPUT)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vSetPinDir(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Mode){
    if(A_u8PinId < 16) {
        if(A_u8PinId < 8) {
            switch (A_u8PortId)
            {
                case PORTA_ID:  GPIOA_CRL &= ~(0xF << (A_u8PinId * 4));  GPIOA_CRL |= (A_u8Mode << (A_u8PinId * 4));  break;
                case PORTB_ID:  GPIOB_CRL &= ~(0xF << (A_u8PinId * 4));  GPIOB_CRL |= (A_u8Mode << (A_u8PinId * 4));  break;
                case PORTC_ID:  GPIOC_CRL &= ~(0xF << (A_u8PinId * 4));  GPIOC_CRL |= (A_u8Mode << (A_u8PinId * 4));  break;
                default:
                    /*	Invalid PORT ID	*/
                    break;
            }
        } else {
            switch (A_u8PortId)
            {
                case PORTA_ID:  GPIOA_CRH &= ~(0xF << ((A_u8PinId - 8) * 4));  GPIOA_CRH |= (A_u8Mode << ((A_u8PinId - 8) * 4));  break;
                case PORTB_ID:  GPIOB_CRH &= ~(0xF << ((A_u8PinId - 8) * 4));  GPIOB_CRH |= (A_u8Mode << ((A_u8PinId - 8) * 4));  break;
                case PORTC_ID:  GPIOC_CRH &= ~(0xF << ((A_u8PinId - 8) * 4));  GPIOC_CRH |= (A_u8Mode << ((A_u8PinId - 8) * 4));  break;
                default:
                    /*	Invalid PORT ID	*/
                    break;
            }
        }
    } else {
        /*	Invalid PIN ID	*/
    }
}

/**********************************************************************************************************
 * Description : Interface Function to Toggle a specific pin value
 * Outputs     : Error State (Not yet implemented)
 * Inputs      : A_u8PortId -> Port ID (A, B, C), A_u8PinId -> Pin ID (0 - 16)
 * NOTES       : PORTC only has 3 pins (13, 14, 15)
 ***********************************************************************************************************/
void DIO_vTogPinVal(u8 A_u8PortId, u8 A_u8PinId){
	switch (A_u8PortId)
	{
		case PORTA_ID:  GPIOA_ODR ^= (1 << A_u8PinId);  break;
		case PORTB_ID:  GPIOB_ODR ^= (1 << A_u8PinId);  break;
		case PORTC_ID:  GPIOC_ODR ^= (1 << A_u8PinId);  break;
		default:
			/*	Invalid PORT ID	*/
			break;
	}
}
