#include <Wire.h>    // Allows I2C connection
#include <math.h>    // Allows calculation of temperature
#include "rgb_lcd.h" // Allows usage of the rgb lcd
#include "DS1307.h"  // Allows usage of the real time clock
#include "paj7620.h" // Allows usage of the gesture sensor

#define B 4275       // Value of thermistor, used to calculate temperature
#define SPEAKER 3    // Speaker PIN

/*
 * button in D2
 * speaker in D3
 * knob in A0
 * temperature sensor in A1
 */

rgb_lcd lcd;   // I2C port
DS1307  clock; // I2C port
// Gesture sensor in I2C

uint16_t state;
uint8_t stateChanged = 1;

uint16_t secs = 5;

void setup() {
	// Initalizes the three I2C ports
	lcd.begin(16, 2);
	clock.begin();
	paj7620Init();
	// Initalizes the button and speaker
	pinMode(SPEAKER, OUTPUT);
}

void loop() {
	// State checking
	uint8_t currentState = getState();
	if (currentState == 0) {
		printTime();
	} else if (currentState == 1) {
		printTimer();
	} else if (currentState == 2) {
		printTemp();
	} else if (currentState == 3) {
		getName();
	} else if (currentState == 4) {
		calendar();
	}
}
