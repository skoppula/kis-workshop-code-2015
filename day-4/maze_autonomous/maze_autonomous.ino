/*
* Solves a maze autonomously using three ultrasonic sensors
*
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <Servo.h>

const int numUltrasonics = 3;

//7: Left, 8: Forward, 9: Right
const int leftSensorIndex = 0;
const int centerSensorIndex = 1;
const int rightSensorIndex = 2;
const int pins[numUltrasonics] = {7, 8, 9};

long durations [numUltrasonics];
long inches [numUltrasonics];
long cms [numUltrasonics];

Servo servoRight;                           
Servo servoLeft;

void setup() {
	servoRight.attach(12);
	servoLeft.attach(13);
	Serial.begin(9600);
}

void loop() {

	updateSensorReadings();

	if(inches[leftSensorIndex] > 30) {
		while(inches[leftSensorIndex] > 30) {
			turnDimeLeft(servoRight, servoLeft, 100);
                        stopMovement(servoRight, servoLeft, 0);
			updateSensorReadings();
		}

	} else if (inches[centerSensorIndex] > 30) {
		moveForward(servoRight, servoLeft, 1000);
                stopMovement(servoRight, servoLeft, 0);

	} else {
		while(inches[centerSensorIndex] < 30) {
                        //This value might need to be adjusted
                        int turnTimeDelta = 300;
			turnDimeRight(servoRight, servoLeft, turnTimeDelta);
                        stopMovement(servoRight, servoLeft, 0);
			updateSensorReadings();
		}
	}
										  
	delay(50);
}

void updateSensorReadings() {
	for(int i=0; i<numUltrasonics; ++i) {
		durations[i] = getUSReading(i);
		inches[i] = microsecondsToInches(durations[i]);
		cms[i] = microsecondsToCentimeters(durations[i]);
		printUSReading(i, inches[i], cms[i]);
	}
}

void printUSReading(int sensor, int inches, int cm) {
	Serial.print("sensor: ");
	Serial.print(sensor);
	Serial.print(" ");
	Serial.print(inches);
	Serial.print("in, ");
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
}

long getUSReading(int sensorIndex) {

	int pingPin = pins[sensorIndex];

	// The PING is triggered by a HIGH pulse of 2 or more microseconds.
	// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	pinMode(pingPin, OUTPUT);
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(pingPin, LOW);

	// The same pin is used to read the signal from the PING))): a HIGH
	// pulse whose duration is the time (in microseconds) from the sending
	// of the ping to the reception of its echo off of an object.
	pinMode(pingPin, INPUT);
	long duration = pulseIn(pingPin, HIGH);
	return duration;
}

long microsecondsToInches(long microseconds) {
	// According to Parallax's datasheet for the PING))), there are
	// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
	// second).  This gives the distance travelled by the ping, outbound
	// and return, so we divide by 2 to get the distance of the obstacle.
	// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
	return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
	// The speed of sound is 340 m/s or 29 microseconds per centimeter.
	// The ping travels out and back, so to find the distance of the
	// object we take half of the distance travelled.
	return microseconds / 29 / 2;
}
