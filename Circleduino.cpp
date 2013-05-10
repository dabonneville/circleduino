/*
  Library to control the Circular LED bargraphs
*/

#include "Arduino.h"
#include "Circleduino.h"

int _dataPin;				//pin 14 on the 75HC595
int _latchPin;				//pin 12 on the 75HC595
int _clockPin;				//pin 11 on the 75HC595

boolean _registers[16];

Circleduino::Circleduino(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin){

	_dataPin = dataPin;
	pinMode(_dataPin, OUTPUT);

	_clockPin = clockPin;
	pinMode(_clockPin, OUTPUT);

	_latchPin = latchPin;
	pinMode(_latchPin, OUTPUT);

	//reset all register pins
	clear();
	writeValues();
}                             


//set all register pins to LOW
void Circleduino::clear(){
	for(int i = 15; i >=  0; i--){
		_registers[i] = LOW;
	}

	//set pins
	writeValues();
} 

//set all pins HIGH or LOW
void Circleduino::writeAll(boolean values[]){
  for(int i = 15; i >=  0; i--){
     _registers[i] = values[i];
  }

  //set pins
  writeValues();
}

void Circleduino::writePin(int index, int value){
	_registers[index] = value;

	//set pins
	writeValues();
}

//Set and display registers
void Circleduino::writeValues(){

	digitalWrite(_latchPin, LOW);

	for(int i = 15; i >=  0; i--){
		digitalWrite(_clockPin, LOW);

		int value = _registers[i];

		digitalWrite(_dataPin, value);
		digitalWrite(_clockPin, HIGH);

	}
	digitalWrite(_latchPin, HIGH);
}