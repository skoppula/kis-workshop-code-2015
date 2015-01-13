// teach functions

void setup() {
  Serial.begin(9600);
  sayHello();
  sayHello();
  sayHello();
  
  multiplyByTwo(1);
  multiplyByTwo(4);
  multiplyByTwo(90);

}

void loop() {
  
}

void sayHello() {
  Serial.println("Hello, world!");
}

void multiplyByTwo(int a) {
  Serial.println(a * 2);
}
