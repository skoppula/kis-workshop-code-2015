/*
* Maze solving with IR remote control
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <IRremote.h>
#include <Servo.h>

const int irReceiverPin = 3;
const int servoRightPin = 12;
const int servoLeftPin = 13;

const int timeDelta = 100;

/*
REMOTE BUTTON to KEY CODE MAPPING

UP BUTTON: 551485695
RIGHT BUTTON: 551502015
DOWN BUTTON: 551518335
LEFT BUTTON: 551534655
MIDDLE BUTTON: 551522415

BUTTON HELD DOWN: 4294967295
*/

const int UP_KEY = 551485695;
const int RIGHT_KEY = 551502015;
const int DOWN_KEY = 551518335;
const int LEFT_KEY = 551534655;
const int STOP_KEY = 551522415;
const int REPEAT_KEY = 4294967295;

int lastKey = STOP_KEY;

IRrecv irrecv(irReceiverPin);
decode_results results;

Servo servoRight;                           
Servo servoLeft;

void setup() {
	servoRight.attach(12);                    // Attach right signal to pin 12
	servoLeft.attach(13);                     // Attach left signal to pin 13

	irrecv.enableIRIn();
	Serial.begin(9600);
}  
 

void loop() {
	if (irrecv.decode(&results)) {
		Serial.println(results.value, DEC);

		int returnKey = (results.value == REPEAT_KEY) ? lastKey : results.value;
		lastKey = returnKey;

		switch(returnKey) {
			case UP_KEY:
					moveForward(servoRight, servoLeft, timeDelta);
					break;
			case RIGHT_KEY:
					turnDimeRight(servoRight, servoLeft, timeDelta);
					break;
			case DOWN_KEY:
					moveBackward(servoRight, servoLeft, timeDelta);
					break;
			case LEFT_KEY:
					turnDimeLeft(servoRight, servoLeft, timeDelta);
					break;
			//assume you want to stop if middle or other button pressed
			default: 
					stopMovement(servoRight, servoLeft, timeDelta);
		}
		irrecv.resume(); // Receive the next value
	}
	delay(100);
}



