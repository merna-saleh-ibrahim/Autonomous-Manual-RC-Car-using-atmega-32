//#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "../MCALL/I2C/I2C_Interface.h"
#include "../Hal/Ultrasonic/Ultrasonic_Interface.h"
#include "../Hal/Servo/servo_interface.h"
#include "../HAL/MOTOR/MOTOR_Interface.h"
#include "../HAL/LCD/LCD_I2C_Interface.h"
#include "../MCALL/UART/UART_Interface.h"

#define THRESHOLD 15

typedef enum {MODE_AUTO, MODE_MANUAL} Mode;

int main(void) {
    char buffer[16];
    unsigned char command;
    Mode currentMode = MODE_AUTO;

    Ultrasonic_Init();
    Servo_Init();
    I2C_Init();
    LCD_Init();
    UART_Init(9600);
    Motors_Stop();
/////////
    _delay_ms(2000);

    LCD_SetCursor(0,0);
    LCD_String("Waiting Mode");

    while (1) {

        if (UCSRA & (1<<RXC)) {
            command = UDR;

            if (command == 'A') {
                currentMode = MODE_AUTO;
                LCD_Command(0x01);
                LCD_SetCursor(0,0);
                LCD_String("AUTO MODE");
            }
            else if (command == 'M') {
                currentMode = MODE_MANUAL;
                LCD_Command(0x01);
                LCD_SetCursor(0,0);
                LCD_String("MANUAL MODE");
            }
            else if (currentMode == MODE_MANUAL) {

                switch(command) {
                    case 'F': Motors_Forward();
                    LCD_Command(0x01);
                    LCD_SetCursor(0,0);
                    LCD_String("FORWARD");
                    break;
                    case 'B': Motors_Backward();
                    LCD_Command(0x01);
                    LCD_SetCursor(0,0);
                    LCD_String("BACKWARD");
                    break;
                    case 'L': Motors_Left();
                    LCD_Command(0x01);
                    LCD_SetCursor(0,0);
                    LCD_String("LEFT");
                    break;
                    case 'R': Motors_Right();
                    LCD_Command(0x01);
                    LCD_SetCursor(0,0);
                    LCD_String("RIGHT");
                    break;
                    default:  Motors_Stop();    break;
                }
                _delay_ms(200);
                Motors_Stop();
            }
        }


        if (currentMode == MODE_AUTO) {
            uint16_t distance = Ultrasonic_ReadDistance();

            LCD_SetCursor(1,0);
            sprintf(buffer, "Dist:%3d cm", distance);
            LCD_String(buffer);

            if (distance > THRESHOLD) {
                Motors_Forward();
            } else {
                Motors_Stop();
                _delay_ms(300);

                Servo_SetAngle(90);
                _delay_ms(500);
                uint16_t rightDist = Ultrasonic_ReadDistance();

                Servo_SetAngle(-90);
                _delay_ms(500);
                uint16_t leftDist = Ultrasonic_ReadDistance();

                Servo_SetAngle(0);
                _delay_ms(300);

                if (rightDist > leftDist && rightDist > THRESHOLD) {
                    Motors_Right();
                    _delay_ms(600);
                } else if (leftDist > rightDist && leftDist > THRESHOLD) {
                    Motors_Left();
                    _delay_ms(600);
                } else {
                    Motors_Backward();
                    _delay_ms(500);
                }
                Motors_Stop();
            }
            _delay_ms(100);
        }
    }
}
