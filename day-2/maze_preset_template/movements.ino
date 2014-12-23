/*
* Helper functions for robot movement
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <Servo.h>                          // Include servo library
 
//for writeMicroseconds(): sets an internal speed setting on the motor
//0-1500, 0 is fully counter-clockwise; 1500-2500, 2500 is fully clockwise
//MAKE SURE TO CENTER SERVOS AT 1500 BEFORE USING

const int counterClockwiseValue = 1300;
const int clockwiseValue = 1700;
const int stopValue = 1500;

void stopMovement(Servo servoRight, Servo servoLeft, const int time) {
    servoRight.writeMicroseconds(stopValue);
    servoLeft.writeMicroseconds(stopValue);
    delay(time);
}

void turnDimeRight(Servo servoRight, Servo servoLeft, const int time) {
  	servoRight.writeMicroseconds(clockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
  	delay(time);
}

void turnDimeLeft(Servo servoRight, Servo servoLeft, const int time) {
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(counterClockwiseValue);
	delay(time);
}

void turnLeft(Servo servoRight, Servo servoLeft, const int time) {
    servoLeft.writeMicroseconds(stopValue);
  	servoRight.writeMicroseconds(clockwiseValue);
	delay(time);
}

void turnRight(Servo servoRight, Servo servoLeft, const int time) {
  	servoLeft.writeMicroseconds(counterClockwiseValue);
  	servoRight.writeMicroseconds(stopValue);
	delay(time);
}

void moveBackward(Servo servoRight, Servo servoLeft, const int time) {
	delay(time);
  	servoRight.writeMicroseconds(clockwiseValue);
  	servoLeft.writeMicroseconds(counterClockwiseValue);
}

void moveForward(Servo servoRight, Servo servoLeft, const int time) {
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
	delay(time);
}

