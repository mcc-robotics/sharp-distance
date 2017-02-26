//
// Created by Geoff Berl on 2/25/17.
//

#include "Arduino.h"
#include "SharpDistance.h"

SharpDistance::SharpDistance(unsigned char sensorPin, int *readingVariable) {

  // Set up the pin as an input (in case it isn't already done)
  pinMode(sensorPin, INPUT);

  // Assign the pointer to the reading variable pointer
  SharpDistance::reading = readingVariable;

  // Setup other variables
  SharpDistance::lastUpdateMicros = micros();
  SharpDistance::sensorPin = sensorPin;

  // Wait 40ms to allow the sensor to initialize a good first reading
  delay(40);

}

void SharpDistance::setNumBurstSamples(unsigned char numBurstSamples) {

  // Update the number of burst samples variable
  SharpDistance::numBurstSamples = numBurstSamples;
}

bool SharpDistance::update(unsigned long micros) {

  // If enough time has not passed, return false
  if (micros - lastUpdateMicros < SAMPLE_RATE_MICROS) {
    return false;
  }

  // Update the last update time
  lastUpdateMicros = micros;

  // Take our burst readings
  int currReading;
  int lowestReading = 1024;
  for (int i = 0; i < numBurstSamples; i++) {
    currReading = analogRead(sensorPin);

    if (currReading < lowestReading) {
      lowestReading = currReading;
    }

    // Delay a short time before taking another reading
    delayMicroseconds(BURST_DELAY_MICROS);
  }

  // Update the sensor reading variable
  *reading = lowestReading;

  return true;
}
