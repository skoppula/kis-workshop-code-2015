int x = 5;
const int y = 2;
// double y = 2.5;

boolean r = true;
boolean f = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial.println( x + y );
  Serial.println( x - y );
  Serial.println( x * y );
  Serial.println( x / y );
  Serial.println( x % y );
  Serial.println( r && f );
  Serial.println( r || f );
}


void loop()
{
  //Add code that repeats automatically here.
}
