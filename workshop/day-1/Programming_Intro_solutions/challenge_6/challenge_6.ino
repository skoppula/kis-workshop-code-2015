void setup() {
  Serial.begin(9600); 
  
  evenOrOdd(1);
  evenOrOdd(2);
  evenOrOdd(4);
  evenOrOdd(13561);
}

void loop() {
  
}

void evenOrOdd(int bananas) {
  if (bananas % 2 == 0) {
    Serial.println("EVEN");
  }
  else {
    Serial.println("ODD");
  }
}
