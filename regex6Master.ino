/*
 Split string.
 substring takes from the 7 letter to the 10 letter of a string
 Subrstring contains of startswith and endswith
 
 toInt transfers the string to an integer
 
 gets the numbers after a word. Example <servo1>.
*/

String servodata =  "<servo1>170</servo1><servo2>120</servo2><servo3>130</servo3>";
String servodata2 = "<servo1>17</servo1><servo2>12</servo2><servo3>13</servo3>";
String servodata3 = "<servo1>0</servo1>0<servo2>0</servo2><servo3>0</servo3>";

int servoValue;

int val1;
int val2;
int val3;
int sum;

String part1;

void setup() {
  Serial.begin(9600);
  servoindexxoff();
}

// the loop function runs over and over again forever
void loop() 
{
  
}


void servoindexxoff()
{
  String localVar = "<servo3>";
  
  Serial.println("TEST INDEXOFF");
  part1 = servodata.substring(servodata.indexOf(localVar)+8);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val1 = servoValue;
  //<>
 
  Serial.println("TEST INDEXOFF");
  part1 = servodata2.substring(servodata2.indexOf(localVar)+8);
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  //<>
  //mathfunction:
  val2 = servoValue;
  //<>

  Serial.println("TEST INDEXOFF");
  part1 = servodata3.substring(servodata3.indexOf(localVar)+8);
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
