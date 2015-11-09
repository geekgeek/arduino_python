/* 
Dual servo 2. Goes to pos in steps by 1.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

//Servo2
Servo myservo2;
//<>


void setup()
{
//serial
Serial.begin(9600);
//<>
myservo2.attach(6);
myservo.attach(9);  
myservo2.write(10);
delay(2000);
/* 
//Servo2

myservo2.write(10);
delay(2000);
myservo2.write(170);
delay(2000);
myservo2.write(90);
delay(2000);
//<>

//servo1

myservo.write(10);                  
delay(2000);
myservo.write(170);
delay(2000);
myservo.write(90);
delay(2000);
//<>
*/


}

int max = 170;
int i = 1;
int x = 1;

void loop() 
{ 

while (i < max)
{
i = i + 1;
myservo2.write(i); 
delay(10);
Serial.println(i);
}

while (x < max)
{
x = x + 1;
myservo.write(x); 
delay(10);
Serial.println(x);
}

} 
