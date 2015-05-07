#include <Arduino.h>

#define LED_PIN 13    // LED connected to digital pin 13
#define SW_PIN 10

// The setup() method runs once, when the sketch starts
void setup() {
	// initialize the digital pin as an output:
	pinMode(LED_PIN, OUTPUT);
	pinMode(SW_PIN, INPUT);
	digitalWrite(LED_PIN, LOW);    // set the LED off
	//digitalWrite(SW_PIN, HIGH);    // set the LED off
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop() {
	digitalWrite(LED_PIN, HIGH);   // set the LED on
	delay(1000);                  // wait for a second
	digitalWrite(LED_PIN, LOW);    // set the LED off
	delay(1000);                  // wait for a second
}

int main(void) {

	init();
	setup();

	for(int i=0; i < 15; i++) {
		digitalWrite(LED_PIN, HIGH);
		delay(100);
		digitalWrite(LED_PIN, LOW);
		delay(100);
	}

	digitalWrite(SW_PIN, HIGH);
	pinMode(SW_PIN, OUTPUT);
	digitalWrite(SW_PIN, HIGH);
	delay(200);
	digitalWrite(SW_PIN, LOW);
	delay(500);
	digitalWrite(SW_PIN, HIGH);
	delay(200);
	pinMode(SW_PIN, INPUT);

	while (true) {
		loop();
	}
}
