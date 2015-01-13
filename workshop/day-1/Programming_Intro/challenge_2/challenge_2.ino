// teach return functions

void setup() {
  Serial.begin(9600);
  calculateMinionTax(4.20);
  calculateMinionTax(100);
  calculateMinionTax(5.6);
}

void loop() {
  
}

void calculateMinionTax(double price) {
    double tax = // TODO;
    double total = // TODO;
    
    Serial.print("The tax is: $");
    Serial.println(tax);
    Serial.print("The total is: $");
    Serial.println(total);
}
