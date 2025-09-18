#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCALL/DIO/DIO_Interface.h"

#include "Ultrasonic_Interface.h"

#define TRIGGER_PORT   DIO_u8_PORTB
#define TRIGGER_PIN    DIO_u8_PIN5

#define ECHO_PORT      DIO_u8_PORTD
#define ECHO_PIN       DIO_u8_PIN6

void Ultrasonic_Init(void)
{

    DIO_u8SetPinDirection(TRIGGER_PORT, TRIGGER_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(ECHO_PORT, ECHO_PIN, DIO_u8_INPUT);
}

u16 Ultrasonic_ReadDistance(void)
{
    u16 count = 0;
    u8 echoValue = 0;

    DIO_u8SetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_u8_HIGH);
    _delay_us(10);
    DIO_u8SetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_u8_LOW);

    do {
        DIO_u8GetPinValue(ECHO_PORT, ECHO_PIN, &echoValue);
    } while (echoValue == 0);


    TCNT2 = 0;
    TCCR2 = (1 << CS21);


    do {
        DIO_u8GetPinValue(ECHO_PORT, ECHO_PIN, &echoValue);

        if (TCNT2 >= 255) {
            count += 255;
            TCNT2 = 0;
        }
    } while (echoValue == 1);

    count += TCNT2;

    TCCR2 = 0;

    u16 distance = count / 58;

    return distance;
}
