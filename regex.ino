/*
 Split string.

 substring takes from the 7 letter to the 10 letter of a string

 toInt transfers the string to an integer
*/

String servodata = "servo1 171   servo2   121";
String servodata2 = "servo1 17   servo2   12";
String servodata3 = "servo1 0   servo2   3";

int servoValue;

String part1;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  part1 = servodata.substring(7,10);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  
  part1 = servodata2.substring(7,10);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>

  part1 = servodata3.substring(7,10);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  
}

// the loop function runs over and over again forever
void loop() {
  
}
