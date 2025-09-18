#include "../../LIB/STD_TYPES.h"
#include "../../MCALL/DIO/DIO_Interface.h"
#include "MOTOR_Interface.h"

void Motors_Init(void) {
    DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_OUTPUT);
}

void Motors_Stop(void) {
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_LOW);
}

void Motors_Forward(void) {
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
}

void Motors_Backward(void) {
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_LOW);
}

void Motors_Left(void) {
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_LOW);
}

void Motors_Right(void) {
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_HIGH);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
}
