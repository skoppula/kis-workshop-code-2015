/*
 * Play with potentiometers!
 * Manually turn the right wheel (servo). 
 * The left wheel should mirror the movement and the light should blink at different speeds
 * 
 * THIS DOES NOT WORK BECAUSE WE HAVE FULL ROTATION SERVOS (BI DIRECTIONAL GEARED MOTOR DRIVE) - NO WAY FOR ARDUINO TO KNOW POSITION
 */

/*
#include <Servo.h>

Servo servoRight;
Servo servoLeft;

int ledPin = 2;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the servo

void setup() {
  servoRight.attach(12);
  servoLeft.attach(13);

  servoLeft.write(90);
  servoRight.write(90);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  
  // read the value from the sensor:
  sensorValue = servoRight.read();
  Serial.print("HELLO");
  Serial.println(sensorValue);
  servoLeft.write(sensorValue);
  
  // change the value of the servo from the range (0,180) to (10, 1000);
  int LEDdelay = map(sensorValue, 0, 180, 10, 1000);
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(LEDdelay);
  
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  delay(LEDdelay);                  
}
*/

