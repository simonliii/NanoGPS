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


![Picture of the pinout on a 4x7-Segmented Display.](https://github.com/simonliii/NanoGPS/assets/18261239/03463748-8713-46c4-8b11-6f7b9c949dad)
#### Resistors
We will connect a 1K Ohm resistor to each of the digit pins (DP). These are as follows:
- DP1 is pin 12.
- DP2 is pin 9.
- DP3 is pin 8.
- DP4 is pin 6.

#### Wiring
How to connect the Arduino pins to the display pins.

- Arduino Pin 2 to Display Pin 7.
- Arduino Pin 3 to Display Pin 4.
- Arduino Pin 4 to Display Pin 3.
- Arduino Pin 5 to Display Pin 2.
- Arduino Pin 6 to Display Pin 1.
- Arduino Pin 7 to Display Pin 5.
- Arduino Pin 8 to Display Pin 10.
- Arduino Pin 9 to Display Pin 11.
- Arduino Pin 10 to Display Pin 12 (With 1k Ohm Resistor).
- Arduino Pin 11 to Display Pin 9  (With 1k Ohm Resistor).
- Arduino Pin 12 to Display Pin 8  (With 1k Ohm Resistor).
- Arduino Pin 13 to Display Pin 6  (With 1k Ohm Resistor).
