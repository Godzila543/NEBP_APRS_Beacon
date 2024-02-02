#include <Wire.h>
#include "ublox_GNSS.h"
#include <SoftwareSerial.h>


SoftwareSerial Serial_GNSS(4, 5); // RX, TX
float lat, lon, acc;
fixType_t fix = NO_FIX;
GNSS gnss(Serial_GNSS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial_GNSS.begin(9600);

  if (gnss.init())
    Serial.println("GNSS initialized.");
  else
    Serial.println("Failed to init GNSS");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (gnss.getCoodinates(lon, lat, fix, acc, 100) == 0)
    Serial.println("Failed to get coordinates!");

  Serial.println("Here you are, lon:" + String(lon, 7) +" lat:" + String(lat, 7));
  Serial.println("calculated error: " + String(acc) + "m");
}
