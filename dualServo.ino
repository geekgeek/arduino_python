/* 
2 servos connected to arduino.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

//Servo2
Servo myservo2;
//<>


void setup()
{


//Servo2
myservo2.attach(6); // attaches the servo on pin 6 to the servo object
myservo2.write(10);
delay(2000);
myservo2.write(170);
delay(2000);
myservo2.write(90);
delay(2000);
myservo2.detach();
//<>

//servo1
myservo.attach(9);  // attaches the servo on pin 9 to the servo object
myservo.write(10);                  // sets the servo position according to the scaled value 
delay(2000);
myservo.write(170);
delay(2000);
myservo.write(90);
delay(2000);
myservo.detach();
//<>

}

void loop() 
{ 
} 
