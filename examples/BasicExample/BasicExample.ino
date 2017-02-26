//
// Created by Geoff Berl on 2/25/17.
//

#include "Arduino.h"
#include "SharpDistance.h"

#define SENSOR_PIN 35
#define ONE_SECOND_TO_MICROS  1000000

int sensorReading = 0;
unsigned long lastUpdate;
unsigned long thisUpdate;
SharpDistance distanceSensor(SENSOR_PIN, &sensorReading);

void setup() {
  Serial.begin(115200);

  // Update the last update time right before the loop
  lastUpdate = micros();
}

void loop() {
  // Record our current micros to use it a few times in this loop
  thisUpdate = micros();

  // Call update on the sensor
  distanceSensor.update(thisUpdate);

  // If one half second has passed, print the sensor reading
  if (thisUpdate - lastUpdate > ONE_SECOND_TO_MICROS/2) {
    lastUpdate = thisUpdate;
    Serial.println(sensorReading);
  }
}