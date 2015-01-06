#include <Arduino.h>

#define LED_PIN 13    // LED connected to digital pin 13
#define SW_PIN 10

#define CLOCK 7
#define LATCH 5
#define DATA 6

byte VALUE_CONSTANT[] ={ B11000000, // 0
				B11111001, // 1
                B10100100, // 2
                B10110000, // 3
                B10011001, // 4
                B10010010, // 5
                B10000010, // 6
                B11111000, // 7
                B10000000, // 8
                B10010000, // 9
                B11111111};// nothing

uint32_t loop_counter = 0;
uint32_t counter = 0;

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


void displayDigitAt(byte value, byte index) {
	if (value >= 0 && value <= 10 && index >= 0 && index < 4) {
		digitalWrite(LATCH, LOW);
		shiftOut(DATA, CLOCK, MSBFIRST, VALUE_CONSTANT[value]);
		shiftOut(DATA, CLOCK, MSBFIRST, (1 << index ));
		digitalWrite(LATCH, HIGH);
	}
}


void loop() {
	// very simple delay
	if (loop_counter++ > 5) {
		loop_counter = 0;
		// update counter
		if (counter++ > 9999) {
			counter = 0;
		}
	}

	uint8_t d0 = counter % 10;
	uint8_t d1 = (counter / 10) % 10;
	uint8_t d2 = (counter / 100) % 10;
	uint8_t d3 = (counter / 1000) % 10;

	// prevent preceeding zeros
	if (counter < 10) {
		d1 = 10; // to display nothing
		d2 = 10;
		d3 = 10;
	} else if (counter < 100) {
		d2 = 10;
		d3 = 10;
	} else if (counter < 1000) {
		d3 = 10;
	}

	// display value
	displayDigitAt(d0, 0);
	displayDigitAt(d1, 1);
	displayDigitAt(d2, 2);
	displayDigitAt(d3, 3);
}

int main(void) {

	init();
	setup();

	while (true) {
		loop();
	}
}
