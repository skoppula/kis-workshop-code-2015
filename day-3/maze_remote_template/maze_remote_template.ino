const int irReceiverPin = 10;

Servo servoRight;                           
Servo servoLeft;

void setup() {
  pinMode(irReceiverPin, INPUT);
  Serial.begin(9600);
}  
 
void loop() {
  int irPresent = digitalRead(irReceiverPin);
  Serial.println(irPresent);
  delay(100);
}



