/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int state; 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  myservo.write(10);
} 
 
void loop() 
{ 
  if (Serial.peek() == 'c') {
    Serial.read();
    state = Serial.parseInt();
    myservo.write(180);
    delay(1000);
    }
  if (Serial.peek() == 'd') {
    Serial.read();
    state = Serial.parseInt();
    myservo.write(0);
    delay(1000);
    }
  while (Serial.available() > 0 ) {
    Serial.read();
    }
} 
