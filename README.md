# Arduino Ur

## Description
Vi har lavet et ur ud af en arduino uno, revision 3, samt en masse moduler fra [seeed](https://www.seeedstudio.com).

## Pseudo-code
Her er vores pseudo-code for at få et overblik over vores software's struktur:

* Pre-processing
* Start **setup**
* Initialize moduler
* Initialize pins
* Slut **setup**
* Start **loop**
* Checker state
* **State 0**
* Checker ugedag
* Printer tid
* **State 1**
* Reads A0 - analogue knob
* Prints instructions
* Prints time selected time - if no, restarts **state 1**
* Checks for activation
* Prints total time
* Prints time left
* Colors screen according to time left
* Outputs sound according to time left
* **State 2**
* Calculates temperature
* Prints temperature
* Prints sentence according to temperature
* **State 3**
* Checks if button is pressed - if no, restarts **state 3**
* Print random name
* **State 4**
* Checks time until christmas
* Prints days left
* Prints statement relevant to date (birthday, holiday etc.)

## Flow-chart
Her er et flow-chart for at få et overblik over vores software's flow:
Dette flowchart følger ISO 5807:1985 standarden for flowcharts og deres symboler.



Dette var lavet i Lucidchart.

## State-diagram
Her er et state-diagram for vores software:
Dette diagram kan bruges til både udviklingen af softwaren, men også som en brugsguide.



Dette var lavet i Lucidchart.

## Authors
Dette software er lavet af:

* [Ludvig Schou-Hansen](https://github.com/LAHVIG)

* [Tobias Clasen](https://github.com/sandalbanditten)

* [Jonatan Mulgeta](https://github.com/sandalbanditten)

## License
Vores projekt er under en MIT-licens.

* [MIT-license](https://mit-license.org)

### The MIT License (MIT)

Copyright © 2021 AARHUS TECH

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Fork this project to create your own MIT license that you can always link to.

## Tools
Her er de forskellige redskaber vi har brugt til at lave vores projekt:

### Software
* [Lucidchart](https://lucid.app)
* [Neovim](https://neovim.io)
* [Visual Studio Code](https://code.visualstudio.com)
* [Arduino-ide](https://www.arduino.cc/en/guide/windows)
* [Arduino-cli](https://arduino.github.io/arduino-cli)
* [git](https://git-scm.com)
* [github](https://github.com)
* [trello](https://trello.com)

### Hardware
* [Arduino UNO, revision 3](https://www.arduino.cc/en/Main/arduinoBoardUno&gt)
 * [Arduino Grove shield & modules](https://www.seeedstudio.com/category/Grove-c-1003.html)
