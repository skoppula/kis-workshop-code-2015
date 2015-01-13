/*
* Demo of reading remote control values with IR sensor
*
* Servo Documentation: http://arduino.cc/en/reference/servo
* Juan Castrillo and Skanda Koppula 2014
*/

#include <IRremote.h>

const int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}

void loop() {
	//& gets the pointer variable to the address where results is stored
	if (irrecv.decode(&results)) {
		Serial.println(results.value, DEC);
		irrecv.resume(); // Receive the next value
	}
	delay(100);
}
