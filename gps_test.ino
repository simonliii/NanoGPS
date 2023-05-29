#include <TinyGPS++.h>
#include <SoftwareSerial.h>
//LCD
#include <LiquidCrystal.h>

static const int RXPin = 7, TXPin = 8;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

//Pins for LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String prevLine1;
String prevLine2;
int topkmh;

void setup(){
  analogWrite(9, 10); // Generate PWM signal at pin D9, value of 10 (out of 255)
  lcd.begin(16,2);
  lcd.print("Connecting GPS...");
  Serial.begin(9600);
  ss.begin(GPSBaud);

  prevLine1 = "Connecting GPS...";
  prevLine2 = " ";
  topkmh = 0;
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){ // if there are bytes availble to be read from the serial port, start processing them.
    gps.encode(ss.read());
    // if (gps.location.isUpdated()){
    //   Serial.print("Latitude= "); 
    //   Serial.print(gps.location.lat(), 6);
    //   Serial.print(" Longitude= "); 
    //   Serial.println(gps.location.lng(), 6);
    //   writeToLCD("Lat: " + String(gps.location.lat(), 6), "Long: " + String(gps.location.lng(), 6));
    // }

    if(gps.speed.isUpdated)){
      //updateTopSpeed(gps.speed.kmph());
      Serial.print("Speed = "); 
      Serial.print(gps.speed.kmph(), 2);
      Serial.println(" km/h");
      writeToLCD(String(gps.speed.kmph(), 1) + " km/h", "Top Speed: " + String(topkmh));
    }
  }
}

void updateTopSpeed(int kmh){
  if(kmh > topkmh){
    topkmh = kmh;
  }
}

void writeToLCD(String line1, String line2){
  if(prevLine1.length() > line1.length() || prevLine2.length() > line2.length()){
    lcd.clear();
  }

  //if(line1 != prevLine1 && line2 != prevLine2){
    lcd.setCursor(0, 0);
    lcd.print(line1);
    prevLine1 = line1;

    lcd.setCursor(0, 1);
    lcd.print(line2);
    prevLine2 = line2;
  //}
}