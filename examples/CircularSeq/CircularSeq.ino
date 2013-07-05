/*
  CircularSeq
  Turn on LED for a circular sequence.
 
  This example code is in the public domain.
 */
 
 #include <Circleduino.h>

Circleduino circled(8, 9, 10);

void setup() {

}

void loop() {

  circled.clear();
  circled.setPin(0, HIGH);
  delay(100);
  for(int i = 1; i < 16; i++){
    circled.setPin(i - 1, LOW);
    circled.setPin(i, HIGH);
    delay(100);
  }
}
