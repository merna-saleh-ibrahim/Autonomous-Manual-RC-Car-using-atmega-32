#include <avr/io.h>
#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "I2C_Interface.h"

#define F_SCL 100000UL
#define TWBR_val ((((F_CPU / F_SCL) - 16 ) / 2))

void I2C_Init(void) {
    TWSR = 0x00;
    TWBR = (u8)TWBR_val;
}

void I2C_Start(void) {
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    while (GET_BIT(TWCR, TWINT) == 0);
}

void I2C_Stop(void) {
    TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
}

void I2C_Write(u8 data) {
    TWDR = data;
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (GET_BIT(TWCR, TWINT) == 0);
}
