/*
* Seeing the output of _n_ ultrasonic sensors
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* (c) Juan Castrillo and Skanda Koppula 2014
*/

const int numUltrasonics = 3;
const int pins[numUltrasonics] = {2,4,6};

void setup() {
	Serial.begin(9600);
}

void loop() {

	long durations [numUltrasonics];
	long inches [numUltrasonics];
	long cms [numUltrasonics];

	for(int i=0; i<numUltrasonics; ++i) {
		durations[i] = getUSReading(i);
		inches[i] = microsecondsToInches(durations[i]);
		cms[i] = microsecondsToCentimeters(durations[i]);
		Serial.print("(");
		Serial.print(inches[i]);
		Serial.print("in,");
		Serial.print(cms[i]);
		Serial.print("cm) ");
	}
	Serial.println("");
										  
	delay(100);
}

long getUSReading(int ultrasoundNumber) {

	int pingPin = pins[ultrasoundNumber];

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
