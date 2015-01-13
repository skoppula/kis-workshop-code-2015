/*
* Exercise to make LEDs light up based on remote input
*
* (c) Juan Castrillo and Skanda Koppula 2014
*/

#include <IRremote.h>

const int RECV_PIN = 3;

const int UP_KEY = /* ??? what is this value ??? */;
const int RIGHT_KEY = /* ??? what is this value ??? */;
const int DOWN_KEY = /* ??? what is this value ??? */;
const int LEFT_KEY = /* ??? what is this value ??? */;

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
		//What do you do with results.value now?
		//If UP_KEY is detected: light up LED one
		//If RIGHT_KEY is detected: light up LED two
		//If DOWN_KEY is detected: light up LED three
		//If LEFT_KEY is detected: light up LED four

		irrecv.resume(); 
	}
	delay(100);
}
