#include <Wire.h>     // Allows I2C connection
#include <math.h>     // Allows calculation of temperature
#include "MMA7660.h"  // Allows usage of 3d accelerometer
#include "rgb_lcd.h"  // Allows usage of the rgb lcd
#include "DS1307.h"   // Allows usage of the real time clock

// Value for calculating temperature
#define B 4275    // Value of thermistor

#define BUTTON 2
#define SPEAKER 3

/*
 * button in D2
 * speaker in D3
 * knob in A0
 * temperature sensor in A1
 */

rgb_lcd lcd;   // I2C port
MMA7660 accel; // I2C port
DS1307  clock; // I2C port

void setup() {
	lcd.begin(16, 2);
	accel.init();
	clock.begin();
	pinMode(BUTTON, INPUT);
	pinMode(SPEAKER, OUTPUT);
}

void loop() {
	if (getState() == 0) {
		printTime();
	} else if (getState() == 1) {
		printTimer();
	} else if (getState() == 2) {
		printTemp();
	} else if (getState() == 3) {
		getName();
	} else if (getState() == 4) {
		calendar();
	}
}
