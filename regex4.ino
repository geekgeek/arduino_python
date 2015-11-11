/*
 Split string.

 substring takes from the 7 letter to the 10 letter of a string
 Subrstring contains of startswith and endswith
 
 toInt transfers the string to an integer
*/

String servodata =  "170  120";
String servodata2 = "17  12";
String servodata3 = "0  0";

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
  part1 = servodata.substring(0,3);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val1 = servoValue;
  //<>

  part1 = servodata2.substring(0,3);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val2 = servoValue;
  //<>

  part1 = servodata3.substring(0,3);
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
  part1 = servodata.substring(servodata.indexOf("  "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val1 = servoValue;
  //<>

  part1 = servodata2.substring(servodata2.indexOf("  "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val2 = servoValue;
  //<>

  part1 = servodata3.substring(servodata3.indexOf("  "));
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
