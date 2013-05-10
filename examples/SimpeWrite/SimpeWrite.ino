#include <Shiftduino.h>
#include <Circleduino.h>

Circleduino circled(8, 9, 10);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly: 
  boolean prueba[] = {0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1, 0 , 1};
  circled.write(prueba);
  delay(200);
  circled.clear();
  circled.writePin(0,1);
  delay(200);
}
