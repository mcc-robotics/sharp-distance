//
// Created by Geoff Berl on 2/25/17.
//

#ifndef SHARP_DISTANCE_SHARPDISTANCE_H
#define SHARP_DISTANCE_SHARPDISTANCE_H

#define SAMPLE_RATE_MICROS  38000
#define BURST_DELAY_MICROS  1500

class SharpDistance {
public:
    SharpDistance(unsigned char sensorPin, int *readingVariable);

    bool update(unsigned long micros);

    void setNumBurstSamples(unsigned char numBurstSamples);

private:

    unsigned char sensorPin;            // The pin the sensor is connected to
    unsigned long lastUpdateMicros;     // The last time the sensor was updated (in microseconds)
    unsigned char numBurstSamples = 8;  // The number of samples to take during the burst reading
    int *reading;                       // A pointer to the variable holding the reading

};


#endif //SHARP_DISTANCE_SHARPDISTANCE_H
