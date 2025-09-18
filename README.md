# Autonomous & Manual RC Car

An embedded systems project for a dual-mode (Autonomous/Manual) RC car built around the ATmega32 microcontroller. Developed as part of the ITI AVR course.
📥 (https://drive.google.com/drive/folders/19AFSCeSxX6ibq_ClPdWeaYd1pqVYKnhC?usp=drive_link)

## 🧠Features
- **Dual Operating Modes:**
  - **Manual Mode:** Wireless control via a smartphone app over Bluetooth (HC-05).
  - **Autonomous Mode:** Line following and obstacle detection/avoidance using an ultrasonic sensor (HC-SR04).
- **Real-time Status Display:** LCD (16x2 with I2C) shows current mode, distance to obstacles, and status.
- **Obstacle Avoidance:** A servo motor sweeps the ultrasonic sensor to find a clear path.
- **Layered Software Architecture:** Well-structured, modular firmware for easy maintenance and scalability.

## 🔧 Hardware Components
- **Microcontroller:** ATmega32
- **Motor Driver:** L298N
- **Sensors:** HC-SR04 (Ultrasonic)
- **Wireless Communication:** HC-05 (Bluetooth Module)
- **Actuators:** DC Geared Motors, Micro Servo Motor (SG90)
- **Display:** 16x2 LCD with I2C Interface
- **Power:** 12V Battery for Motors, 5V Regulator for MCU & Components

## 🧰Software Architecture
The firmware follows a layered architecture:
- **LIB:** Bit Math and standard data types.
- **MCAL (Microcontroller Abstraction Layer):** Direct hardware drivers (DIO, I2C, UART).
- **HAL (Hardware Abstraction Layer):** Device drivers (Ultrasonic, Motor, LCD, Servo).
- **Application Layer:** Main application logic and mode switching.

## Getting Started

### Prerequisites
- **Compiler:** AVR-GCC
- **Programmer:** USBasp, AVRISP, or similar
- **Software:** SimulIDE, Proteus for simulation (optional)
- **Mobile App:** Any serial Bluetooth terminal app (e.g., 'Arduino Bluetooth Controller')
