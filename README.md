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

## Link And Download

---

## Author Information

Name    : Fatih Uhda A.
NIM     : 24090620033
Matkul  : Praktik Mikrokontroller
Email   : fatihudhaffg@gmail.com


# Mixer-O-Matic with Inlet and Outlet Valves

## 📌 Description

Hello everyone!

This project was developed for my Microcontroller midterm exam. **Mixer-O-Matic** is a simple **Batch Mixing system** based on Arduino. The system consists of three main processes: **filling**, **mixing**, and **discharging** of materials.

Currently, the system uses **two servo motors** as inlet and outlet valves. However, the design can be modified and expanded to suit different requirements or applications.

This project demonstrates basic process control and actuator integration using a microcontroller.

---

## ⚙️ Features

* Adjustable mixing time using a **potentiometer (ADC)**
* Two servo motors:

  * Inlet Valve (material input)
  * Outlet Valve (material output)
* DC motor as mixer (controlled using L293D)
* LCD 16x2 (I2C) for system monitoring
* LED indicators:

  * 🟢 Ready
  * 🟡 Process
  * 🔴 Done / Emergency
* Three control buttons:

  * START
  * EMERGENCY (E-STOP)
  * RESET
* Emergency system with real-time response
* Blinking LED indicator during emergency condition

---

## 🔄 System Workflow

1. The system starts in **Ready mode**
2. Press **START** to begin the process
3. The system performs:

   * **Filling** → Inlet valve opens
   * **Mixing** → Motor runs based on potentiometer setting
   * **Discharging** → Outlet valve opens
4. The process ends and returns to **Ready mode**

---

## 🚨 Emergency Stop (E-STOP)

* The emergency button can be pressed at any time
* The system will immediately:

  * Stop the motor
  * Close all valves
  * Activate blinking red LED
  * Display emergency message on LCD
* The system can only resume after pressing the **RESET button**

---

## 🧩 Components Used

* Arduino Uno
* LCD 16x2 with I2C module
* Servo Motors (2x)
* DC Motor
* L293D Motor Driver
* Potentiometer
* Push Buttons (3x)
* LEDs (3x)
* Resistors
* Breadboard and jumper wires
* External power supply (for motor and servo)

---

## 🔌 Pin Configuration

| Component     | Arduino Pin |
| ------------- | ----------- |
| Start Button  | D7          |
| Emergency     | D2          |
| Reset         | D3          |
| Servo In      | D6          |
| Servo Out     | D4          |
| Motor IN1     | D9          |
| Motor EN      | D5          |
| LED Ready     | D10         |
| LED Process   | D8          |
| LED Done      | D13         |
| Potentiometer | A0          |
| LCD SDA       | A4          |
| LCD SCL       | A5          |

---

## 🖼️ System Diagram

See the system diagram here:
👉 [Schematics](schematics.md)

---

## 🧠 Concepts Applied

* Sequence control system
* Non-blocking delay using `millis()`
* Analog-to-Digital Conversion (ADC)
* Basic process automation

---

## 📌 Notes

* The system uses separate power supply for motor and servo to ensure stability
* All grounds must be connected (common ground)
* LCD I2C address is set to `0x27`

---

## 🎯 Project Purpose

This project aims to demonstrate:

* Basic control system design
* Integration of sensors and actuators
* Simulation of industrial batch processes using Arduino

---

## 👨‍💻 Author

Name: (Your Name)
Class: (Your Class)
Course: Microcontroller Systems

---

