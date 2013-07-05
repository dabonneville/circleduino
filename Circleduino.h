/*
 Arduino Library for Circular LED Bargraphs
 go to https://www.sparkfun.com/products/10595 for more information

 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created July 2013
 by Jonathan Ruiz de Garibay

 Notes:
   In the Bargraph board, CLR pin must be connected on Vcc and EN pin on GND.

 */ 

#ifndef Circleduino_h
#define Circleduino_h

#include "Arduino.h"

class Circleduino
{
	public:
		Circleduino(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);
		void clear();
		void setAll(boolean values[]);
		void setPin(uint8_t index, uint8_t value);

	private:
		uint8_t _dataPin;
		uint8_t _clkPin;
		uint8_t _latchPin;
		boolean _registers[16];
		void writeValues();

};

#endif