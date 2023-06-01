# NanoGPS - Arduino Nano GPS Speedometer
With this code, you can connect an Arduino Nano with a NEO-6M GPS Module to get speed data, and display this on a simple 7-segment display.

## Features
- Shows current speed in km/h once it locks onto satellites.
- Loading animation while attemping to lock onto satellites.
- Since it uses hardware serial communication, we can utilize a cheap 7-segment display without the flickering that software serial would cause.

## Hardware Required
- Arduino Nano 
- 7-Segment Display (Common-cathode)
- 8x 330 Ohm Resistors
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


![Picture of the pinout on a 4x7-Segmented Display.](https://github.com/simonliii/NanoGPS/assets/18261239/567cfaec-05b5-45c7-86c9-c068eccd28fb)

#### Resistors
We will connect a 330 Ohm resistor to each of the segment pins. These are as follows:
- Pin 1
- Pin 2
- Pin 3
- Pin 4
- Pin 5
- Pin 7
- Pin 10
- Pin 11


#### Wiring
How to connect the Arduino pins to the display pins. We are only using the digital pins on the Arduino.

- Arduino Pin 02 to Display Pin 07.
- Arduino Pin 03 to Display Pin 04.
- Arduino Pin 04 to Display Pin 03.
- Arduino Pin 05 to Display Pin 02.
- Arduino Pin 06 to Display Pin 01.
- Arduino Pin 07 to Display Pin 05.
- Arduino Pin 08 to Display Pin 10.
- Arduino Pin 09 to Display Pin 11.
- Arduino Pin 10 to Display Pin 12.
- Arduino Pin 11 to Display Pin 09.
- Arduino Pin 12 to Display Pin 08.
- Arduino Pin 13 to Display Pin 06.

