#include "servo_interface.h"
#include "../../MCALL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>

#define SERVO_MIN   65
#define SERVO_MID   175
#define SERVO_MAX   300

void Servo_Init(void)
{

	DIO_u8SetPinDirection(DIO_u8_PORTD, 5, DIO_u8_OUTPUT);


    TCNT1 = 0;
    ICR1  = 2499;

    TCCR1A = 0;
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1A, COM1A1);

    TCCR1B = 0;
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);
    SET_BIT(TCCR1B, CS10);
    SET_BIT(TCCR1B, CS11);
}

void Servo_SetAngle(s8 angle)
{

    if(angle < -90) angle = -90;
    if(angle >  90) angle =  90;


    OCR1A = SERVO_MID + ((s32)angle * (SERVO_MAX - SERVO_MIN) / 180);

    _delay_ms(500);
}
