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

int counterClockwiseValue = 1300;
int clockwiseValue = 1700;
int stopValue = 1500;
int dimeTurnTime = 700;
int turnTime = 1000; //MAY BE WRONG!

void turnDimeRight() {
  	servoRight.writeMicroseconds(clockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
  	delay(dimeTurnTime);
}

void stopMovement(int time) {
        servoRight.writeMicroseconds(stopValue);
        servoLeft.writeMicroseconds(stopValue);
        delay(time);
}

void turnDimeLeft() {
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(counterClockwiseValue);
	delay(dimeTurnTime);
}

void turnLeft() {
        servoLeft.writeMicroseconds(stopValue);
  	servoRight.writeMicroseconds(clockwiseValue);
	delay(turnTime);
}

void turnRight() {
  	servoLeft.writeMicroseconds(counterClockwiseValue);
  	servoRight.writeMicroseconds(stopValue);
	delay(turnTime);
}

void moveBackward(int time) {
	delay(time);
  	servoRight.writeMicroseconds(clockwiseValue);
  	servoLeft.writeMicroseconds(counterClockwiseValue);
}

void moveForward(int time) {
	delay(time);
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
}

void setup() {
	servoRight.attach(12);                     // Attach left signal to pin 12
	servoLeft.attach(13);                     // Attach left signal to pin 12

}  
 
void loop() {                                            
	//moveForward(1000);
	//moveBackward(1000);
	//turnDimeRight();
	//turnLeft();
	//turnRight();
        //turnDimeRight();
        //stopMovement(1000);
}

