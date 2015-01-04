/*
* Day-two pre-written program. See what your robot can do!
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
* 
* Circuit:
*    ServoRight -> pin 12
*    ServoLeft -> pin 13
*    3 LEDs -> pins 2,4,6
*/

#include <Servo.h>                          // Include servo library
 
Servo servoRight;                           // Declare right servo
Servo servoLeft;                            // Declare left servo

// attach three LED lights in the right pins
const int ledOne = 2;
const int ledTwo = 4;
const int ledThree = 6;

const int rightAngleDimeTurnTime = 700;

void setup() {
    servoRight.attach(12);                    // Attach right signal to pin 12
    servoLeft.attach(13);                     // Attach left signal to pin 13
    servoRight.write(90);
    servoLeft.write(90);
        
    // initialize LED lights
    pinMode(ledOne, OUTPUT);
    pinMode(ledTwo, OUTPUT);
    pinMode(ledThree, OUTPUT);
} 

void loop() {

	// Turn LED one ON
 	digitalWrite(ledOne, HIGH);
 	digitalWrite(ledTwo, LOW);
 	digitalWrite(ledThree, LOW);
	// Move forward for 2000 milliseconds (2 seconds).
	moveForward(servoRight, servoLeft, 2000);

	// Turn LED two ON
 	digitalWrite(ledOne, LOW);
 	digitalWrite(ledTwo, HIGH);
 	digitalWrite(ledThree, LOW);
	// Turn robot to the left, to the right, and back to center
	turnDimeLeft(servoRight, servoLeft, rightAngleDimeTurnTime);
	turnDimeRight(servoRight, servoLeft, rightAngleDimeTurnTime);
	turnDimeRight(servoRight, servoLeft, rightAngleDimeTurnTime);
	turnDimeLeft(servoRight, servoLeft, rightAngleDimeTurnTime);
  
	// Turn LED three ON
 	digitalWrite(ledOne, LOW);
 	digitalWrite(ledTwo, LOW);
 	digitalWrite(ledThree, HIGH);
	// Move backward for 2000 milliseconds (2 seconds), back to start
	moveBackward(servoRight, servoLeft, 2000);
}
