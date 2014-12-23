/*
 Robotics with the BOE Shield – RightServoClockwise
 Generate a servo full speed clockwise signal on digital pin 12.
 */

#include <Servo.h>                           // Include servo library
 
Servo servoRight;                            // Declare left servo
Servo servoLeft;                            // Declare left servo

void setup()                                 // Built in initialization block
{
  servoRight.attach(12);                     // Attach left signal to pin 12
  servoLeft.attach(13);                     // Attach left signal to pin 12
        // 1.3 ms full speed clockwise
}  
 
void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
  delay(1000);
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1300);
  delay(1000);
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1700);
}

