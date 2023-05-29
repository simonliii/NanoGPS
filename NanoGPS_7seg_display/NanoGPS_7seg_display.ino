#include "SevSeg.h"
//GPS Includes
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SevSeg sevseg; 
String prevText;

//GPS
static const int RXPin = A1, TXPin = A2;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

//Timer
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time timer loop was active.
const long interval = 700;  // timer interval (sleep/delay)

void setup(){
  //Display settings
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  //Loading animation
  sevseg.setChars("GPS");
  prevText = "GPS";

  //Serial communication
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop(){
  //Loading screen animation
  //FIGURE OUT HOW TO NOT RUN THIS ONCE WE HAVE SAT CONNECTION
  // unsigned long currentMillis = millis();
  // if (currentMillis - previousMillis >= interval) {
  //   // save the last time you blinked the LED
  //   previousMillis = currentMillis;

  //   if(prevText == "GPS."){
  //     sevseg.setChars("GPS..");
  //     prevText = "GPS..";
  //   } else if(prevText == "GPS.."){
  //     sevseg.setChars("GPS");
  //     prevText = "GPS";
  //   } else {
  //     sevseg.setChars("GPS.");
  //     prevText = "GPS.";
  //   }
  // }

 while (ss.available() > 0){ // if there are bytes availble to be read from the serial port, start processing them.
    gps.encode(ss.read());
    // if (gps.location.isUpdated()){
    //   Serial.print("Latitude= "); 
    //   Serial.print(gps.location.lat(), 6);
    //   Serial.print(" Longitude= "); 
    //   Serial.println(gps.location.lng(), 6);
    //   writeToLCD("Lat: " + String(gps.location.lat(), 6), "Long: " + String(gps.location.lng(), 6));
    // }

    if(gps.speed.isUpdated()){
      Serial.print("Speed = "); 
      Serial.print(gps.speed.kmph(), 2);
      Serial.println(" km/h\n");
      sevseg.setNumberF(gps.speed.kmph(), 1);
    }
  }



  //Needs to run every loop to keep display updated.
  sevseg.refreshDisplay(); 
}