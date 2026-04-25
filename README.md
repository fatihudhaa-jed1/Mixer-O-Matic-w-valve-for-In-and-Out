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
     
