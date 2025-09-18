#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCALL/I2C/I2C_Interface.h"
#include "LCD_I2C_Interface.h"

void I2C_LCD_Write(u8 data) {
    I2C_Start();
    I2C_Write(LCD_ADDR << 1);
    I2C_Write(data | LCD_BACKLIGHT);
    I2C_Stop();
}

void LCD_Pulse(u8 data) {
    I2C_LCD_Write(data | ENABLE);
    _delay_us(1);
    I2C_LCD_Write(data & ~ENABLE);
    _delay_us(50);
}

void LCD_Command(u8 cmd) {
    u8 high = cmd & 0xF0;
    u8 low  = (cmd << 4) & 0xF0;
    I2C_LCD_Write(high);
    LCD_Pulse(high);
    I2C_LCD_Write(low);
    LCD_Pulse(low);
}

void LCD_Char(u8 data) {
    u8 high = (data & 0xF0) | 0x01;
    u8 low  = ((data << 4) & 0xF0) | 0x01;
    I2C_LCD_Write(high);
    LCD_Pulse(high);
    I2C_LCD_Write(low);
    LCD_Pulse(low);
}

void LCD_Init(void) {
    _delay_ms(50);
    LCD_Command(0x33);
    LCD_Command(0x32);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
    _delay_ms(2);
}

void LCD_String(const char *str)
{
    while(*str) {
        LCD_Char(*str++);
    }
}

void LCD_SetCursor(u8 row, u8 col) {
    u8 pos;
    if(row == 0) pos = 0x80 + col;
    else         pos = 0xC0 + col;
    LCD_Command(pos);
}

