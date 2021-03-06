#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_BMP085.h>

#include <DHT22.h>

// Data wire is plugged into port 7 on the Arduino
// Connect a 4.7K resistor between VCC and the data pin (strong pullup)
#define DHT22_PIN 9

/***************************************************
 This is an example for the BMP085 Barometric Pressure & Temp Sensor

 Designed specifically to work with the Adafruit BMP085 Breakout
 ----> https://www.adafruit.com/products/391

 These displays use I2C to communicate, 2 pins are required to
 interface
 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here
Adafruit_BMP085 bmp;

// Setup a DHT22 instance
DHT22 myDHT22(DHT22_PIN);

void setup() {
	Serial.begin(38400);
	if (!bmp.begin()) {
		Serial.println("Could not find a valid BMP085 sensor, check wiring!");
		while (1) {
		}
	}
}

void loop() {
	Serial.print("Temperature = ");
	Serial.print(bmp.readTemperature());
	Serial.println(" *C");

	Serial.print("Pressure = ");
	Serial.print(bmp.readPressure());
	Serial.println(" Pa");

	// Calculate altitude assuming 'standard' barometric
	// pressure of 1013.25 millibar = 101325 Pascal
	Serial.print("Altitude = ");
	Serial.print(bmp.readAltitude());
	Serial.println(" meters");

	Serial.print("Pressure at sealevel (calculated) = ");
	Serial.print(bmp.readSealevelPressure());
	Serial.println(" Pa");

	// you can get a more precise measurement of altitude
	// if you know the current sea level pressure which will
	// vary with weather and such. If it is 1015 millibars
	// that is equal to 101500 Pascals.
	Serial.print("Real altitude = ");
	Serial.print(bmp.readAltitude(101500));
	Serial.println(" meters");

	Serial.println();

	Serial.print("Requesting data...");

	DHT22_ERROR_t errorCode = myDHT22.readData();
	switch (errorCode) {
	case DHT_ERROR_NONE:
		Serial.print("{'temp':");
		Serial.print(myDHT22.getTemperatureC());
		Serial.print(", 'humidity':");
		Serial.print(myDHT22.getHumidity());
		Serial.print("}");

		// Alternately, with integer formatting which is clumsier but more compact to store and
		// can be compared reliably for equality:
		//
		/*
		 char buf[128];
		 sprintf(buf, "Integer-only reading: Temperature %hi.%01hi C, Humidity %i.%01i %% RH",
		 myDHT22.getTemperatureCInt()/10, abs(myDHT22.getTemperatureCInt()%10),
		 myDHT22.getHumidityInt()/10, myDHT22.getHumidityInt()%10);

		 Serial.println(buf);
		 */

		break;
	case DHT_ERROR_CHECKSUM:
		Serial.print("check sum error ");
		Serial.print(myDHT22.getTemperatureC());
		Serial.print("C ");
		Serial.print(myDHT22.getHumidity());
		Serial.println("%");
		break;
	case DHT_BUS_HUNG:
		Serial.println("BUS Hung ");
		break;
	case DHT_ERROR_NOT_PRESENT:
		Serial.println("Not Present ");
		break;
	case DHT_ERROR_ACK_TOO_LONG:
		Serial.println("ACK time out ");
		break;
	case DHT_ERROR_SYNC_TIMEOUT:
		Serial.println("Sync Timeout ");
		break;
	case DHT_ERROR_DATA_TIMEOUT:
		Serial.println("Data Timeout ");
		break;
	case DHT_ERROR_TOOQUICK:
		Serial.println("Polled to quick ");
		break;
	}
	Serial.println();

	delay(2000);
}

int main(void) {

	init();
	setup();

	while (true) {
		loop();
	}
}
