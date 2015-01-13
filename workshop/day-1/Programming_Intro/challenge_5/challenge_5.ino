// challenge 5

void setup() {
  Serial.begin(9600);
  
  int bananas = 91;
  for ( /* TODO */ ) {
    bananas = moreBananas( /* TODO */);
  }
  
  Serial.print("After four machine runs, there are ");
  Serial.println(bananas);
}

void loop() {
  
}

double moreBananas(double bananas, double multiplier) {
    return bananas * multiplier + 1;
}