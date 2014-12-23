/*
* Maze Solving with Hardcoded Distances (Template)
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <Servo.h>                          // Include servo library
 
Servo servoRight;                           // Declare left servo
Servo servoLeft;                            // Declare left servo

const int rightAngleDimeTurnTime = 700;
const int rightAngleTurnTime = 1000; //MAY BE WRONG!

void setup() {
	servoRight.attach(12);                     // Attach left signal to pin 12
	servoLeft.attach(13);                     // Attach left signal to pin 12
}  
 
void loop() {                                            
	//moveForward(servoRight, servoLeft, 1000);
	//moveBackward(servoRight, servoLeft, 1000);
	//turnDimeRight(servoRight, servoLeft, rightAngleDimeTurnTime);
	//turnDimeLeft(servoRight, servoLeft, rightAngleDimeTurnTime);
    //stopMovement(servoRight, servoLeft, 1000);
}

