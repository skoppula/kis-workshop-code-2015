/*
* Day-two pre-written program. See what your robot can do!
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <Servo.h>                          // Include servo library
 
Servo servoRight;                           // Declare left servo
Servo servoLeft;                            // Declare left servo

// attach three LED lights in the right pins
int ledOne = 9;
int ledTwo = 10;
int ledThree = 11;

void setup() {
	servoRight.attach(12);                     // Attach left signal to pin 12
	servoLeft.attach(13);                     // Attach left signal to pin 12
        servoRight.write(90);
        servoLeft.write(90);
        
        // initialize LED lights
        pinMode(ledOne, OUTPUT);
        pinMode(ledTwo, OUTPUT);
        pinMode(ledThree, OUTPUT);
} 

void loop() {
  // Move forward for 2000 milliseconds (2 seconds).
  // Turn LED one ON
  digitalWrite(ledOne, HIGH);
  digitalWrite(ledThree, LOW);
  forward();            
  delay(2000);
  
  // Turn robot to the left, to the right, and back to center
  // Turn LED two ON
  digitalWrite(ledOne, LOW);
  digitalWrite(ledTwo, HIGH);
  turnRight();
  delay(2000);
  turnLeft();
  delay(2000);
  stopRobot();
  delay(2000);
  
  // Move back to starting position
  // Turn LED three ON
  digitalWrite(ledTwo, LOW);
  digitalWrite(ledThree, HIGH);
  reverse();
  delay(2000);
  stopRobot();
  delay(2000);
}

// Motion routines for forward, reverse, turns, and stop
void forward() {
  servoLeft.write(0);
  servoRight.write(180);
}

void reverse() {
  servoLeft.write(180);
  servoRight.write(0);
}

void turnRight() {
  servoLeft.write(180);
  servoRight.write(180);
}

void turnLeft() {
  servoLeft.write(0);
  servoRight.write(0);
}

void stopRobot() {
  servoLeft.write(90);
  servoRight.write(90);
}
