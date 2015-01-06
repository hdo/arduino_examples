/*
 * segment.h
 *
 *  Created on: Jan 5, 2015
 *      Author: huy
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <avr/io.h>

#define SEGMENT_COUNT 1
#define SEGMENT_PORT DDRD
#define SEGMENT_PIN_CLOCK 5
#define SEGMENT_PIN_DATA  6
#define SEGMENT_PIN_LATCH 7


struct sVALUE {
	uint16_t value;
	uint8_t d0; // pre-calculated digit values
	uint8_t d1; // pre-calculated digit values
	uint8_t d2; // pre-calculated digit values
	uint8_t d3; // pre-calculated digit values
};

void segment_init();
void segment_update();
void segment_set_value(uint16_t value, uint8_t index);


#endif /* SEGMENT_H_ */
