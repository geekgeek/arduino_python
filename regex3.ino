/*
 Split string.

 substring takes from the 7 letter to the 10 letter of a string

 toInt transfers the string to an integer
*/

String servodata =  "servo1 170   servo2   120   ";
String servodata2 = "servo1 17   servo2   12   ";
String servodata3 = "servo1 2   servo2   2   ";

int servoValue;

int val1;
int val2;
int val3;
int sum;

String part1;

void setup() {
  Serial.begin(9600);
  servovalue1();
  servovalue2();

  
}

// the loop function runs over and over again forever
void loop() {
  
}

void servovalue1(){
  Serial.println("SERVO1 INITIADED:");
  
  part1 = servodata.substring(7,10);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val1 = servoValue;
  //<>
  
  part1 = servodata2.substring(7,10);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val2 = servoValue;
  //<>

  part1 = servodata3.substring(7,10);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val3 = servoValue;
  //<>

  //main math function
  sum = val1 + val2 + val3;
  Serial.print("sum value:");
  Serial.println(sum);
  //<>

  }

void servovalue2(){
  Serial.println("SERVO2 INITIADED:");
  
  part1 = servodata.substring(20,25);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val1 = servoValue;
  //<>

  part1 = servodata2.substring(20,25);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val2 = servoValue;
  //<>

  part1 = servodata3.substring(20,25);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val3 = servoValue;
  //<>

  //main math function
  sum = val1 + val2 + val3;
  Serial.print("sum value:");
  Serial.println(sum);
  //<>
  }
