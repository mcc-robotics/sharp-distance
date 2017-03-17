# Sharp Distance Library

<strong>Important:</strong> This library currently only works with the Sharp 2Y0A21 (10-80cm) sensor 

The goal is to provide a library that can be used with analog Sharp distance sensors that can provide reliable output.

For a full write up on how this research was done, check out <a href="robotresearchlab.com/2017/02/26/sharp-distance-sensors-and-eliminating-noise/">my article here</a> on www.RobotResearchLab.com

## Problem
Sharp distance sensors send multiple pulses and if you happen to catch one of these pulses while reading the value you will get a spike in your reading. There is no easy way to time the readings so they avoid this repetitive pulsing and averaging values is still not enough to avoid the noise. For example, if you read a noisy output multiple times in a row or even within a short period your average will be skewed giving you a higher than normal reading.

## Proposed Solution
1. Read the sensor at a specific rate that is known to result in the fewest noise readings.
2. Read the sensor multiple times in a short period of time (burst reading)
3. Take the lowest value of those multiple readings and assume that is the best reading.

## Notes: 
* Taking the lowest value works to avoid the noise because reading during the pulse of the sensor always results in a higher value.
* Due to the nature of the library, when the library performs an actual reading (this does **not** happen every time update() is called) it will take 12ms to update. However, this delay will not affect the update frequency.

## Example Output
In this example, a sensor reading was taken every 500 milliseconds for ten minutes.
![Library vs Raw Comparison](http://robotresearchlab.com/wp-content/uploads/2017/02/Raw-vs-Library-Comparison.png)
