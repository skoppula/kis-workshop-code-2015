int ir_pin = 2;                        //Sensor pin 1 wired through a 220 ohm resistor
int led_pin = 13;                      //"Ready to Recieve" flag, not needed but nice
int debug = 0;                         //Serial connection must be started to debug
int start_bit = 2200;                  //Start bit threshold (Microseconds)
int bin_1 = 1000;                      //Binary 1 threshold (Microseconds)
int bin_0 = 400;                       //Binary 0 threshold (Microseconds)

 
void setup() {
	pinMode(led_pin, OUTPUT);            //This shows when we're ready to recieve
	pinMode(ir_pin, INPUT);
	digitalWrite(led_pin, LOW);          //not ready yet
	Serial.begin(9600);
}

void loop() {
	int key = getIRKey();                //Fetch the key
	Serial.print("Key Recieved: ");      
	Serial.println(key);                
}


int getIRKey() {
	int data[12];
	digitalWrite(led_pin, HIGH);         //Ok, i'm ready to recieve
	while(pulseIn(ir_pin, LOW) < start_bit) { //Wait for a start bit}
	data[0] = pulseIn(ir_pin, LOW);      //Start measuring bits, I only want low pulses
	data[1] = pulseIn(ir_pin, LOW);
	data[2] = pulseIn(ir_pin, LOW);
	data[3] = pulseIn(ir_pin, LOW);
	data[4] = pulseIn(ir_pin, LOW);
	data[5] = pulseIn(ir_pin, LOW);
	data[6] = pulseIn(ir_pin, LOW);
	data[7] = pulseIn(ir_pin, LOW);
	data[8] = pulseIn(ir_pin, LOW);
	data[9] = pulseIn(ir_pin, LOW);
	data[10] = pulseIn(ir_pin, LOW);
	data[11] = pulseIn(ir_pin, LOW);
	digitalWrite(led_pin, LOW);
						 
	if(debug == 1) {
		Serial.println("-----");
	}
	
	for(int i=0;i<11;i++) {

		if (debug == 1) {
			Serial.println(data[i]);
		}             

		//Read in bits
		if(data[i] > bin_1) {
			data[i] = 1;
		} else {
			if(data[i] > bin_0) {
				data[i] = 0;
			} else {
				data[i] = 2;
			}
		}
	}

	//Deal with invalid					   
	for(int i=0;i<11;i++) {              //Pre-check data for errors
		if(data[i] > 1) {                 
			return -1;                       //Return -1 on invalid data
		}
	}
	
	//Convert bits to integer
	int result = 0;  
	int seed = 1;                                      
	for(int i=0;i<11;i++) {
		if(data[i] == 1) {
			result += seed;
		}
		seed = seed * 2;
	}

	return result;
} 
