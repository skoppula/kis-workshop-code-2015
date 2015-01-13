// challenge 3 and 4

double moreBananas(double bananas, double multiplier) {
    return bananas * multiplier + 1;
}

void setup() {
  Serial.begin(9600);
  
  double firstTime = moreBananas(91, 17);
  double secondTime = moreBananas(firstTime, 17);

  Serial.print(firstTime);
  Serial.println(" bananas through the machine the first time");
  Serial.print(secondTime);
  Serial.println(" bananas throught the machine the second time");
}

void loop() {
  
}
