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
	printName(names[random(0, 30)]);
	while (digitalRead(BUTTON) == 0) {
	}
}
