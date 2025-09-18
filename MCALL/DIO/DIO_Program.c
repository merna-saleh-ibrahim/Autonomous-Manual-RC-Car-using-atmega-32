#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    if (Copy_u8Pin > 7) return DIO_u8_NOK;
    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRA, Copy_u8Pin);
            else CLR_BIT(DDRA, Copy_u8Pin);
            break;
        case DIO_u8_PORTB:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRB, Copy_u8Pin);
            else CLR_BIT(DDRB, Copy_u8Pin);
            break;
        case DIO_u8_PORTC:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRC, Copy_u8Pin);
            else CLR_BIT(DDRC, Copy_u8Pin);
            break;
        case DIO_u8_PORTD:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRD, Copy_u8Pin);
            else CLR_BIT(DDRD, Copy_u8Pin);
            break;
        default:
            return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    if (Copy_u8Pin > 7) return DIO_u8_NOK;
    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTA, Copy_u8Pin);
            else CLR_BIT(PORTA, Copy_u8Pin);
            break;
        case DIO_u8_PORTB:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTB, Copy_u8Pin);
            else CLR_BIT(PORTB, Copy_u8Pin);
            break;
        case DIO_u8_PORTC:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTC, Copy_u8Pin);
            else CLR_BIT(PORTC, Copy_u8Pin);
            break;
        case DIO_u8_PORTD:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTD, Copy_u8Pin);
            else CLR_BIT(PORTD, Copy_u8Pin);
            break;
        default:
            return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
    if (Copy_pu8Value == (void*)0) return DIO_u8_NOK;
    if (Copy_u8Pin > 7) return DIO_u8_NOK;

    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA: *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin); break;
        case DIO_u8_PORTB: *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin); break;
        case DIO_u8_PORTC: *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin); break;
        case DIO_u8_PORTD: *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin); break;
        default: return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}

u8 DIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    if (Copy_u8Pin > 7) return DIO_u8_NOK;
    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA: TOG_BIT(PORTA, Copy_u8Pin); break;
        case DIO_u8_PORTB: TOG_BIT(PORTB, Copy_u8Pin); break;
        case DIO_u8_PORTC: TOG_BIT(PORTC, Copy_u8Pin); break;
        case DIO_u8_PORTD: TOG_BIT(PORTD, Copy_u8Pin); break;
        default: return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}

/* Port-level */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8DirectionMask)
{
    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA: DDRA = Copy_u8DirectionMask; break;
        case DIO_u8_PORTB: DDRB = Copy_u8DirectionMask; break;
        case DIO_u8_PORTC: DDRC = Copy_u8DirectionMask; break;
        case DIO_u8_PORTD: DDRD = Copy_u8DirectionMask; break;
        default: return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA: PORTA = Copy_u8Value; break;
        case DIO_u8_PORTB: PORTB = Copy_u8Value; break;
        case DIO_u8_PORTC: PORTC = Copy_u8Value; break;
        case DIO_u8_PORTD: PORTD = Copy_u8Value; break;
        default: return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_pu8Value)
{
    if (Copy_pu8Value == (void*)0) return DIO_u8_NOK;
    switch(Copy_u8Port)
    {
        case DIO_u8_PORTA: *Copy_pu8Value = PINA; break;
        case DIO_u8_PORTB: *Copy_pu8Value = PINB; break;
        case DIO_u8_PORTC: *Copy_pu8Value = PINC; break;
        case DIO_u8_PORTD: *Copy_pu8Value = PIND; break;
        default: return DIO_u8_NOK;
    }
    return DIO_u8_OK;
}
