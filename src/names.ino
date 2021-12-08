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
	// Prints a random name on line 0
	print(names[random(0, 30)], 0);
	// Loops infinetely until the button is pressed
	while (digitalRead(BUTTON) == 0) {
	}
}
