// teach if/else

void setup() {
  Serial.begin(9600);
  
  greaterThanThree(1);
  greaterThanThree(3);
  greaterThanThree(6);
  
}

void loop() {
  
}

void greaterThanThree(int count) {
    if (count < 3) {
        Serial.println("less than 3");
    }
    else if (count == 3) {
        Serial.println("equal to 3");
    }
    else {
        Serial.println("greater than 3");
    }
}
