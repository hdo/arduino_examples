#include <Arduino.h>

#define LED_PIN 13    // LED connected to digital pin 13
#define SW_PIN 10

#define CLOCK 7
#define LATCH 5
#define DATA 6

byte value[] ={ B11111001, // 1
                B10100100, // 2
                B10110000, // 3
                B10011001, // 4
                B10010010, // 5
                B10000010, // 6
                B11111000, // 7
                B10000000, // 8
                B10010000, // 9
                B11000000, // 0
                B11111111};// nothing

// The setup() method runs once, when the sketch starts
void setup() {
	// initialize the digital pin as an output:
	pinMode(CLOCK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	pinMode(DATA, OUTPUT);
	digitalWrite(CLOCK, HIGH);
	digitalWrite(LATCH, HIGH);
	digitalWrite(DATA, HIGH);
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop() {
	digitalWrite(LATCH, LOW);
	shiftOut(DATA, CLOCK, MSBFIRST, value[0]);  // 1
	shiftOut(DATA, CLOCK, MSBFIRST, B00001000); // 1. digit
	digitalWrite(LATCH, HIGH);

	digitalWrite(LATCH, LOW);
	shiftOut(DATA, CLOCK, MSBFIRST, value[1]);  // 2
	shiftOut(DATA, CLOCK, MSBFIRST, B00000100); // 2. digit
	digitalWrite(LATCH, HIGH);

	digitalWrite(LATCH, LOW);
	shiftOut(DATA, CLOCK, MSBFIRST, value[2]);  // 3
	shiftOut(DATA, CLOCK, MSBFIRST, B00000010); // 3. digit
	digitalWrite(LATCH, HIGH);

	digitalWrite(LATCH, LOW);
	shiftOut(DATA, CLOCK, MSBFIRST, value[3]);  // 4
	shiftOut(DATA, CLOCK, MSBFIRST, B00000001); // 4. digit
	digitalWrite(LATCH, HIGH);
}

int main(void) {

	init();
	setup();

	while (true) {
		loop();
	}
}
