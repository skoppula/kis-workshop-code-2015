#include <Servo.h>                          // Include servo library

Servo servoRight;

void setup() {
  servoRight.attach(12);    // attach to pin 12
  
  // Move the right wheel Forward
  servoRight.writeMicroseconds(2000);
}

void loop() {
  
}
