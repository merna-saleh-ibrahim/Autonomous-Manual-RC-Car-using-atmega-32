/*
 * I2C_Interface.h
 *
 * Created on: Sep 16, 2025
 * Author: DELL
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define F_SCL       100000UL
#define Prescaler   1
#define TWBR_val    ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);

#endif /* I2C_INTERFACE_H_ */
