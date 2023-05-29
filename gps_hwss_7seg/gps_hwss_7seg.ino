#include "SevSeg.h"
#include <TinyGPS++.h>

SevSeg sevseg; 
String prevText;
bool gpsLoaded;

//GPS
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

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
  gpsLoaded = false;

  //Serial communication
  Serial.begin(GPSBaud);
}

void loop(){
  //Loading screen animation
  if(gpsLoaded == false && Serial.available() == 0){
    
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      if(prevText == "GPS."){
        sevseg.setChars("GPS..");
        prevText = "GPS..";
      } else if(prevText == "GPS.."){
        sevseg.setChars("GPS");
        prevText = "GPS";
      } else {
        sevseg.setChars("GPS.");
        prevText = "GPS.";
      }
    }
  }
  
  //GPS Speedometer
  while (Serial.available() > 0){ // if there are bytes availble to be read from the serial port, start processing them.
    if (!gpsLoaded) gpsLoaded = true;
    gps.encode(Serial.read());

    if(gps.speed.isUpdated()){
      // Serial printing for troubleshooting
      Serial.print("Speed = "); 
      Serial.print(gps.speed.kmph(), 2);
      Serial.println(" km/h\n");
      sevseg.setNumberF(gps.speed.kmph());
    }
  }

  //Needs to run every loop to keep display updated.
  sevseg.refreshDisplay(); 
}