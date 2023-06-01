# NanoGPS - Arduino Nano GPS Speedometer
With this code, you can connect an Arduino Nano with a NEO-6M GPS Module to get speed data, and display this on a simple 7-segment display.

## Features
- Shows current speed in km/h once it locks onto satellites.
- Loading animation while attemping to lock onto satellites.
- Since it uses hardware serial communication, we can utilize a cheap 7-segment display without the flickering that software serial would cause.

## Hardware Required
- Arduino Nano 
- 7-Segment Display (Common-cathode)
- 4x 1k Ohm Resitors
- NEO-6M GPS Module

## Wiring
### GPS Module
The GPS Module is connected to the Arduino Nano via four wires. 
- 5V from the Arduino to VCC on the module.
- GND from the Arduino to GND on the module.
- TX from the Arduino to RX on the module.
- RX from the Arduino to TX on the module.
### 7-Segment Display
#### Pinout of 7-Segment Display
This is how we will reference the pins when connecting them to the Arduino.

![Picture of the pinout on a 4x7-segmented display.](https://github.com/simonliii/NanoGPS/assets/18261239/4ca3092e-9f21-44c4-9a4f-2ea03320729c)
