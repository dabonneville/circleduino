/*
  Blink
  Blink some of the LED.
 
  This example code is in the public domain.
 */
 
 #include <Circleduino.h>

Circleduino circled(8, 9, 10);

void setup() {

}

void loop() {

  boolean prueba[] = {0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1};
  circled.setAll(prueba);
  delay(200);
  circled.clear();
  delay(200);
}
