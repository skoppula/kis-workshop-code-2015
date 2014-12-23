/*
* Maze Solving with Hardcoded Distances (Template)
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <Servo.h>                          // Include servo library
 
Servo servoRight;                           // Declare left servo
Servo servoLeft;                            // Declare left servo

//for writeMicroseconds(): sets an internal speed setting on the motor
//0-1500, 0 is fully counter-clockwise; 1500-2500, 2500 is fully clockwise

const int counterClockwiseValue = 1300;
const int clockwiseValue = 1700;
const int stopValue = 1500;
const int rightAngleDimeTurnTime = 700;
const int rightAngleTurnTime = 1000; //MAY BE WRONG!

void stopMovement(const int time) {
    servoRight.writeMicroseconds(stopValue);
    servoLeft.writeMicroseconds(stopValue);
    delay(time);
}

void turnDimeRight(const int time) {
  	servoRight.writeMicroseconds(clockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
  	delay(time);
}

void turnDimeLeft(const int time) {
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(counterClockwiseValue);
	delay(time);
}

void turnLeft(const int time) {
    servoLeft.writeMicroseconds(stopValue);
  	servoRight.writeMicroseconds(clockwiseValue);
	delay(time);
}

void turnRight(const int time) {
  	servoLeft.writeMicroseconds(counterClockwiseValue);
  	servoRight.writeMicroseconds(stopValue);
	delay(time);
}

void moveBackward(const int time) {
	delay(time);
  	servoRight.writeMicroseconds(clockwiseValue);
  	servoLeft.writeMicroseconds(counterClockwiseValue);
}

void moveForward(const int time) {
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
	delay(time);
}

void setup() {
	servoRight.attach(12);                     // Attach left signal to pin 12
	servoLeft.attach(13);                     // Attach left signal to pin 12

}  
 
void loop() {                                            
	//moveForward(1000);
	//moveBackward(1000);
	//turnDimeRight(rightAngleDimeTurnTime);
	//turnDimeLeft(rightAngleDimeTurnTime);
    //stopMovement(1000);
}

