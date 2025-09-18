
#ifndef HAL_LCD_LCD_I2C_INTERFACE_H_
#define HAL_LCD_LCD_I2C_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define LCD_ADDR        0x27
#define LCD_BACKLIGHT   0x08
#define ENABLE          0x04

void I2C_LCD_Write(u8 data);
void LCD_Pulse(u8 data);
void LCD_Command(u8 cmd);
void LCD_Char(u8 data);
void LCD_Init(void);
void LCD_String(const char *str);
void LCD_SetCursor(u8 row, u8 col);

#endif /* HAL_LCD_LCD_I2C_INTERFACE_H_ */

