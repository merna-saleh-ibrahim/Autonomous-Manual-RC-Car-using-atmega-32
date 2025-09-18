#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void UART_Init(u16 baud);
u8 UART_Receive(void);
void UART_Transmit(u8 data);

#endif /* UART_INTERFACE_H_ */
