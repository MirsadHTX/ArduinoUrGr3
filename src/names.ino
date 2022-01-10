// Replace with printName()'s
char names[30][10] = {
	"Anders",
	"Emil",
	"Fahmi",
	"Freja",
	"Gustav W.",
	"Gustav E.",
	"Haris",
	"Ismail",
	"Jabriil",
	"Jacob",
	"Ludvig",
	"Jeppe",
	"Jonatan",
	"Kasper",
	"Lovro",
	"Mathias",
	"Mie",
	"Mohammad",
	"Nelisa",
	"Nicolai",
	"Pernille",
	"Rasmus",
	"Robert",
	"Sarah",
	"Silas",
	"Simon",
	"Thoeger",
	"Tobias",
	"Taaha",
	"William"
};

void getName(void) {
	uint8_t gesture = 0;
	// Prints a random name on line 0
	paj7620ReadReg(0x43, 1, &gesture);
	if (gesture == GES_UP_FLAG || gesture == GES_DOWN_FLAG || stateChanged) {
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.setRGB(255, 255, 255);
		lcd.print(names[random(0, 30)]);
	}
	stateChanged = 0;
}
