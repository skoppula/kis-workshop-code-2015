// teach loops

void setup() {
  Serial.begin(9600);

  int count = 1;
  for (int i=0; i<10; i++) {
    Serial.print("Hello, I am a for and count is: ");
    Serial.println(count);
    count = count + 1;
  }  
  
  count = 1;
  while (count <= 10) {
    Serial.print("Hello, I am a while and count is: ");
    Serial.println(count);
    count = count + 1;
  }
}

void loop() {
  
}
