
#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_Interface.h"

void UART_Init(u16 baud) {
    u16 ubrr = (F_CPU / (16UL * baud)) - 1;
    UBRRH = (u8)(ubrr >> 8);
    UBRRL = (u8)ubrr;

    // Enable RX and TX
    SET_BIT(UCSRB, RXEN);
    SET_BIT(UCSRB, TXEN);


    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}

u8 UART_Receive(void) {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

void UART_Transmit(u8 data) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}
