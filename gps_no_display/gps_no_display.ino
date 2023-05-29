//GPS Includes
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//GPS
static const int RXPin = A1, TXPin = A2;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  //Serial communication
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop() {
  while (ss.available() > 0){ // if there are bytes availble to be read from the serial port, start processing them.
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
    }

    // if(gps.speed.isUpdated()){
    //   Serial.print("Speed = "); 
    //   Serial.print(gps.speed.kmph(), 2);
    //   Serial.println(" km/h" + '\n');
    // }
  }
}
