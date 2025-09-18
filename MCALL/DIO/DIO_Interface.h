
#ifndef MCALL_DIO_DIO_INTERFACE_H_
#define MCALL_DIO_DIO_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"

/* Ports identifiers */
#define DIO_u8_PORTA    0
#define DIO_u8_PORTB    1
#define DIO_u8_PORTC    2
#define DIO_u8_PORTD    3

/* Pin identifiers */
#define DIO_u8_PIN0     0
#define DIO_u8_PIN1     1
#define DIO_u8_PIN2     2
#define DIO_u8_PIN3     3
#define DIO_u8_PIN4     4
#define DIO_u8_PIN5     5
#define DIO_u8_PIN6     6
#define DIO_u8_PIN7     7

/* Pin direction/value */
#define DIO_u8_INPUT    0
#define DIO_u8_OUTPUT   1

#define DIO_u8_LOW      0
#define DIO_u8_HIGH     1

/* Return status */
#define DIO_u8_OK       0
#define DIO_u8_NOK      1

/* Pin-level APIs */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);
u8 DIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);

/* Port-level APIs */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8DirectionMask); /* mask: 1 = output, 0 = input */
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_pu8Value);



#endif /* MCALL_DIO_DIO_INTERFACE_H_ */

