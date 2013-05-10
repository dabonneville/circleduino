/*
  Library to control the 74HC595
  More info at http://bildr.org/?s=74hc595
*/

#ifndef Circleduino_h
#define Circleduino_h

#include "Arduino.h"

class Circleduino
{
	public:
		Circleduino(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);
		void clear();
		void write(boolean values[]);
		void writePin(int index, int value);

	private:

};

#endif