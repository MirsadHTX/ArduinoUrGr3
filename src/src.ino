#include <Wire.h>
#include <math.h>
#include "MMA7660.h"
#include "rgb_lcd.h"
#include "DS1307.h"

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
	}
}
