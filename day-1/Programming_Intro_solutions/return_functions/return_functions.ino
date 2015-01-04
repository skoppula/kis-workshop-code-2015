// teach return statement

void setup() {
  Serial.begin(9600);
  double one = multiplyandDivide(1,2);   // 1
  double two = multiplyandDivide(3,4);   // 6
  double output = multiplyandDivide(one, two);
  
  Serial.println(output);
}

void loop() {
  
}

double multiplyandDivide(double a, double b) {
    return a * b / 2;
}
