//GPS Includes
#include <TinyGPS++.h>

//GPS
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;

void setup() {
  //Serial communication
  Serial.begin(GPSBaud);
}

void loop() {
  while (Serial.available() > 0){ // if there are bytes availble to be read from the serial port, start processing them.
    gps.encode(Serial.read());
    // if (gps.location.isUpdated()){
    //   Serial.print("Latitude= "); 
    //   Serial.print(gps.location.lat(), 6);
    //   Serial.print(" Longitude= "); 
    //   Serial.println(gps.location.lng(), 6);
    // }

    if(gps.speed.isUpdated()){
      Serial.print("Speed = ");
      Serial.print(gps.speed.kmph(), 2);
      Serial.println(" km/h\n");
    }
  }
}
