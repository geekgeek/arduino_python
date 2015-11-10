/* 
Controlling 2 servos with potentiometer.
Shows voltage and servo position in serial.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer

int val2;
int val;    // variable to read the value from the analog pin

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 6 to the servo object
   Serial.begin(9600);
}

void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("servo1");
  Serial.print("\t");
  Serial.print(val);
  val = map(val, 0, 1023, 10, 170);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value
  
  
  Serial.print("\t");
  Serial.print(val);
  Serial.println();
  
  delay(10);                           // waits for the servo to get there 

  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("servo2");
  Serial.print("\t");
  Serial.print(val2);
  val2 = map(val2, 0, 1023, 10, 170);     // scale it to use it with the servo (value between 0 and 180) 
  myservo2.write(val2);                  // sets the servo position according to the scaled value

  
  Serial.print("\t");
  Serial.print(val2);
  Serial.print("\t");
  
  delay(10);                           // waits for the servo to get there 
} 
