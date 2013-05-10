/*
  Library to control the Circular LED bargraphs
*/

#include "Arduino.h"
#include "Shiftduino.h"

#include "Circleduino.h"

Shiftduino shift;

Circleduino::Circleduino(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin){
	Shiftduino shift(dataPin, clockPin, latchPin, 2);
}               


//set all register pins to LOW
void Circleduino::clear(){
	shift.clear();
} 

//set all pins HIGH or LOW
void Circleduino::write(boolean values[]){
	shift.setPins(values);
}

void Circleduino::writePin(int index, int value){
	shift.setPin(index, value);
}