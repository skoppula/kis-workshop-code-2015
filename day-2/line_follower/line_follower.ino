/*
 * Line Follower with Two Sensors on Either Side of Line
 * 
 * analogRead Documentation: http://arduino.cc/en/Reference/AnalogRead
 * (c) Skanda Koppula and Juan Castrillo
 */

#include <Servo.h>                          
 
Servo servoRight;                           
Servo servoLeft;                            

const float darkThreshold = 0.001;

const int leftSensor = A3;
const int rightSensor = A4;

int timeDelta = 300;

void setup() {
	Serial.begin(9600);                       // Set data rate to 9600 bps
}

void loop() {

	Serial.print(volts(A3));
	Serial.print(" ");
  	Serial.println(volts(A4));

//	if(volts(leftSensor) > darkThreshold && volts(rightSensor) > darkThreshold) {
//		//Both sensors read white: robot is straight along the line
//		moveForward(servoRight, servoLeft, timeDelta);
//	} else if(volts(leftSensor) <= darkThreshold) {
//		//Left sensor reads dark; need to turn left
//		turnDimeLeft(servoRight, servoLeft, timeDelta);
//	} else if(volts(rightSensor) <= darkThreshold) {
//		//Right sensor reads dark; turn right
//		turnDimeRight(servoRight, servoLeft, timeDelta);
//	}
}
                                             
float volts(int pin) {
	return float(analogRead(pin)) * 5.0 / 1024.0;
}
