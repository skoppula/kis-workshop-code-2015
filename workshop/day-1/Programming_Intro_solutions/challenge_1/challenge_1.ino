// challenge 1

void setup() {
  Serial.begin(9600);

  int george = 10412;
  int minions = george/7;
  int leftover = george % 7;
  
  Serial.print(minions);
  Serial.println(" Minions got 7 bananas");
  Serial.print("George is left with: ");
  Serial.println(leftover);
}

void loop() {
  
}
