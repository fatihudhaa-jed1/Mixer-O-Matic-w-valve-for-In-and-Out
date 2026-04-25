# Mixer-O-Matic-w-valve-for-In-and-Out

![Image Alt](https://github.com/fatihudhaa-jed1/Mixer-O-Matic-w-valve-for-In-and-Out/blob/b08a7b7a10068944190aa8606c3726d26ecefb45/Files/Fatih%20Udha%20A.%20-%20Automatic%20Mixer%20w_%20valve%20in%20out.png)

## Descripton
Hello everyone!

This project was developed for my Microcontroller midterm exam. Mixer-O-Matic is a simple Mixing system based on Arduino. The system consists of three main processes: filling, mixing, and discharging of materials.

Currently, the system uses two servo motors as inlet and outlet valves. However, the design can be modified and expanded to suit different requirements or applications.

---

## Features
1. Adjustable Mixing Time using Potentiometer
2. DC Motor as mixer
3. LCD 16x2 (I2C) for Monitoring
4. LED Indicator
5. Control Buttons
6. Emergency Systems

---

## System Workflow

<p align="center">
  <img src="https://github.com/fatihudhaa-jed1/Mixer-O-Matic-w-valve-for-In-and-Out/blob/main/Files/FatihUdhaA_MixerDiagram%20(2).gif?raw=true" width="500">
</p>

1. The system starts in a "ready" mode (Green LED ON to indicate the systems is good and ready)
2. In "ready" mode, you can adjust the timer with potentiometer (5s - 20s)
3. To begin the process, press the START button
4. The systems gonna performs filling, mixing and discharging process (Yellow LED ON to indicate the process)
5. Process end and return to beginning

---

## Emergency STOP
1. Emergency button can be pressed at anytime in case something wrong happened
2. The systems will immediately :
   - Stop The Mixing
   - Close all valves
   - Blinking red LED ON
   - Display Emergency Message on LCD
4. The System can only be used after user press Reset button

---

## Component

| Name              | Quantity | Component                                  |
|------------------|----------|--------------------------------------------|
| U1               | 1        | Arduino Uno R3                             |
| Rpot2            | 1        | 250 kΩ Potentiometer                       |
| D1               | 1        | Red LED                                    |
| D2               | 1        | Yellow LED                                 |
| D3               | 1        | Green LED                                  |
| R1, R2, R3       | 3        | 220 Ω Resistor                             |
| U2               | 1        | LCD 16x2 I2C (PCF8574, 0x27)               |
| M1               | 1        | DC Motor                                   |
| SERVO1, SERVO2   | 2        | Positional Micro Servo                     |
| U3               | 1        | H-Bridge Motor Driver (L293D)              |
| P1               | 1        | 5V Power Supply                            |
| S1, S2, S3       | 3        | Pushbutton                                 |


---

## Pin Configuration
| Komponen          | Pin Arduino | Description           |
| ----------------- | ----------- | -------------------- |
| Start Button      | D7          | Input  |
| Emergency Button  | D2          | Input  |
| Reset Button      | D3          | Input  |
| Servo In (Valve)  | D6          | Output         |
| Servo Out (Valve) | D4          | Output               |
| Motor IN1         | D9          | Output  |
| Motor EN          | D5          | Output   |
| LED Ready         | D10         | Output               |
| LED Process       | D8          | Output               |
| LED Done          | D13         | Output               |
| Potensiometer     | A0          | Input          |
| LCD SDA           | A4          | I2C Data             |
| LCD SCL           | A5          | I2C Clock            |


---

## Link
- [Source Code](https://github.com/fatihudhaa-jed1/Mixer-O-Matic-w-valve-for-In-and-Out/blob/5fe014a2f3d1fee54d5e927ae5379248f16719d2/Code.ino)
- [TinkerCAD](https://link.com)
- [CSV File](https://link.com)
- [Youtube Documentation](https://youtu.be/sNdAc3KAxVc)

---

## Author Information

| Field   | Information              |
|--------|--------------------------|
| Name   | Fatih Uhda A.           |
| NIM    | 24090620033             |
| Course | Praktik Mikrokontroler  |
| Email  | fatihudhaffg@gmail.com  |

