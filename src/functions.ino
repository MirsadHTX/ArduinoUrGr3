// All of this can be done smarter, feel free to add functions, and do smarter return types

// State of the box
uint8_t getState(void) {
	// Should get the state, unsigned number between 0 and 4, inclusive
	uint8_t gesture = 0;
	paj7620ReadReg(0x43, 1, &gesture);
	if (gesture == GES_RIGHT_FLAG) {
		state++;
		stateChanged = 1;
	}
	if (gesture == GES_LEFT_FLAG) {
		state--;
		stateChanged = 1;
	}
	return state % 5;
}

// Calendar
// Should show how many days left until the next 24. of december
void calendar(void) {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Days left:");
	lcd.setCursor(0, 1);
	lcd.print(clock.dayOfMonth, DEC);
	delay(100);
}

// Clock related functions
void printTime(void) {
	// Print the time and date on the first line
	lcd.clear();
	lcd.setCursor(0, 0);
	clock.getTime();
	lcd.print(clock.hour, DEC);
	lcd.print(":");
	lcd.print(clock.minute, DEC);
	lcd.print(":");
	lcd.print(clock.second, DEC);
	// Sets the cursor to 16 - (length)
	lcd.setCursor(11, 0);
	lcd.print(clock.month, DEC);
	lcd.print("/");
	lcd.print(clock.dayOfMonth);
	// Print special dates, on second line
	lcd.setCursor(0, 1);
	switch (clock.dayOfWeek) // Friendly printout the weekday
	{
		case MON:
			lcd.print("Monday :(");
			break;
		case TUE:
			lcd.print("Tuesday");
			break;
		case WED:
			lcd.print("Wednesday");
			break;
		case THU:
			lcd.print("Thursday");
			break;
		case FRI:
			lcd.print("Friday!!");
			break;
		case SAT:
			lcd.print("Saturday :)");
			break;
		case SUN:
			lcd.print("Sunday");
			break;
	}
	delay(100);
}

// Timer related functions
void printTimer(void) {
	uint8_t gesture = 0;
	paj7620ReadReg(0x43, 1, &gesture);
	if (gesture == GES_UP_FLAG) {
		secs += 10;
	}
	if (gesture == GES_DOWN_FLAG) {
		if (secs > 10) {
			secs -= 10;
		} else {
			secs = 10;
		}
	}
	// if (secs > 999) secs = 999;
	// if (secs < 0) secs = 0;
	lcd.clear();
	lcd.setRGB(255, 255, 255);
	lcd.setCursor(0, 0);
	lcd.print("How many secs?");
	lcd.setCursor(0, 1);
	lcd.print(secs);
	lcd.print(" seconds");
	delay(100);
	/* if (digitalRead(BUTTON) > 0) {
		 for (int i = secs; i > 0; i--) {
		 lcd.clear();
	// Setting colors and speaker depending on time left
	if (i < (secs >> 3)) {
	lcd.setRGB(255, 0, 0);
	} else if (i < (secs >> 2)) {
	lcd.setRGB(255, 255, 0);
	}
	lcd.setCursor(0, 0);
	lcd.print(secs);
	lcd.print(" seconds");
	lcd.setCursor(0, 1);
	lcd.print(i);
	lcd.print(" seconds left");
	if (i == 3) {
	digitalWrite(SPEAKER, HIGH);
	}
	delay(1000);
	if (digitalRead(BUTTON) > 0) {
	break;
	}
	}
	digitalWrite(SPEAKER, LOW);
	} */
}

// Temperature related stuff
void printTemp(void) {
	float temperature;
	lcd.clear();
	lcd.setCursor(0, 0);
	// There is not a linear relation between the resistance and the temperature, but a logarithmic one
	temperature = 1.0 / (log(1023.0 / analogRead(A1) - 1.0) / B + 1 / 298.15) - 273.15;
	// Prints temperature
	lcd.print(temperature);
	lcd.print(" degrees C");
	// Prints cute comments about temperature
	lcd.setCursor(0, 1);
	if (temperature > 30) {
		lcd.print("This is too hot");
	} else if (temperature > 25) {
		lcd.print("A bit warm");
	} else if (temperature > 20) {
		lcd.print("Pretty nice temp");
	} else if (temperature > 15) {
		lcd.print("Kinda cold, no?");
	} else if (temperature > 10) {
		lcd.print("It's pretty cold");
	} else if (temperature > -10) {
		lcd.print("Wear a jacket");
	} else if (temperature > -40) {
		lcd.print("Are you alive?");
	}
	delay(100);
}

// Speaker related functions:
void sound(uint8_t time) {
	digitalWrite(SPEAKER, HIGH);
	delay(time * 1000);
	digitalWrite(SPEAKER, LOW);
	// Make a sounds, for (time) seconds
}
