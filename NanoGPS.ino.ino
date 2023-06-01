#include "SevSeg.h"
#include <TinyGPS++.h>

//7 Segment Display object
SevSeg sevseg; 

//Loading animation variables
String prevText;
bool gpsLoaded;

//GPS
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

//Timers
unsigned long previousMillis = 0;  // will store last time timer loop was active.
const long interval = 700;  // timer interval for loading animation.
const long connectionLossInterval = 3000; // timer interval for when connection is lost.

void setup(){
  //7 Segment Display settings
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  //Prepare Loading animation
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
      // save the last time loading animation was updated
      previousMillis = currentMillis;

      Serial.println("Searching for satellites...\n");

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
  } else if(Serial.available() == 0){ // Timer to restart loading animation on display if we lose connection for 3 seconds or more.
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= connectionLossInterval) {
      // save the last time you checked if any data was recieved.
      previousMillis = currentMillis;
      gpsLoaded = false;
    }
  }
  
  //GPS Speedometer
  while (Serial.available() > 0){ // if there are bytes availble to be read from the serial port, start processing them.
    if (!gpsLoaded) gpsLoaded = true; // Disables to connecting animation once connection has been established.
    
    previousMillis = millis(); // Keeps time value updated for the connection loss timer.

    gps.encode(Serial.read());

    if(gps.speed.isUpdated()){ // Print current speed to serial and display.
      Serial.print("Speed = "); 
      Serial.print(gps.speed.kmph(), 2);
      Serial.println(" km/h\n");

      sevseg.setNumberF(gps.speed.kmph());
    }
  }

  //Needs to run every loop to keep display updated.
  sevseg.refreshDisplay(); 
}