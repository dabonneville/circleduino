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

#include "Arduino.h"
#include "Circleduino.h"

//
// Constructor
//
// It is necesary indicate clock, data and lanch pins.
Circleduino::Circleduino(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin){

	_dataPin = dataPin;
	pinMode(_dataPin, OUTPUT);

	_clkPin = clkPin;
	pinMode(_clkPin, OUTPUT);

	_latchPin = latchPin;
	pinMode(_latchPin, OUTPUT);

	//reset all register pins
	clear();
	writeValues();
}                             


//
// clear
//
// Set all register pins to LOW
void Circleduino::clear(){

	for(int i = 15; i >=  0; i--){
		_registers[i] = LOW;
	}

	//set pins
	writeValues();
} 

//
// writeAll
//
// Set each pin HIGH or LOW
void Circleduino::setAll(boolean values[]){

  for(int i = 15; i >=  0; i--){
     _registers[i] = values[i];
  }

  //set pins
  writeValues();
}

//
// writePin
//
// set one pin HIGH or LOW
void Circleduino::setPin(uint8_t index, uint8_t value){

	_registers[index] = value;

	//set pins
	writeValues();
}

//
// writeAll
//
// Set and display registers
void Circleduino::writeValues(){

	digitalWrite(_latchPin, LOW);
	for(int i = 15; i >=  0; i--){
		digitalWrite(_clkPin, LOW);

		int value = _registers[i];

		digitalWrite(_dataPin, value);
		digitalWrite(_clkPin, HIGH);

	}
	digitalWrite(_latchPin, HIGH);
}