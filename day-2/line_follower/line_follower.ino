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

const int counterClockwiseValue = 1300;
const int clockwiseValue = 1700;
const int stopValue = 1500;

const int leftSensor = A3;
const int rightSensor = A4;

int timeDelta = 300;

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

void moveForward(const int time) {
  	servoRight.writeMicroseconds(counterClockwiseValue);
  	servoLeft.writeMicroseconds(clockwiseValue);
	delay(time);
}

void setup() {
	Serial.begin(9600);                       // Set data rate to 9600 bps
}

void loop() {

	Serial.print(volts(A3));
	Serial.print(" ");
  	Serial.println(volts(A4));

	if(volts(leftSensor) > darkThreshold && volts(rightSensor) > darkThreshold) {
		//Both sensors read white: robot is straight along the line
		moveForward(timeDelta);
	} else if(volts(leftSensor) <= darkThreshold) {
		//Left sensor reads dark; need to turn left
		turnDimeLeft(timeDelta);
	} else if(volts(rightSensor) <= darkThreshold) {
		//Right sensor reads dark; turn right
		turnDimeRight(timeDelta);
	}
}
                                             
float volts(int pin) {
	return float(analogRead(pin)) * 5.0 / 1024.0;
}
