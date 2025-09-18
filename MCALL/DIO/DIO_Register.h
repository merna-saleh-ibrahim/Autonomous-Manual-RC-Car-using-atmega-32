
#ifndef MCALL_DIO_DIO_REGISTER_H_
#define MCALL_DIO_DIO_REGISTER_H_

#include "../../LIB/STD_TYPES.h"

/* Port A */
#define DDRA   (*(volatile u8*)0x3A)
#define PORTA  (*(volatile u8*)0x3B)
#define PINA   (*(volatile u8*)0x39)

/* Port B */
#define DDRB   (*(volatile u8*)0x37)
#define PORTB  (*(volatile u8*)0x38)
#define PINB   (*(volatile u8*)0x36)

/* Port C */
#define DDRC   (*(volatile u8*)0x34)
#define PORTC  (*(volatile u8*)0x35)
#define PINC   (*(volatile u8*)0x33)

/* Port D */
#define DDRD   (*(volatile u8*)0x31)
#define PORTD  (*(volatile u8*)0x32)
#define PIND   (*(volatile u8*)0x30)

#endif /* MCALL_DIO_DIO_REGISTER_H_ */

