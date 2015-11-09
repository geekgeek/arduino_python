// Runs 2 servos simulataneusly

#include <Servo.h>

Servo servo2;  

//Servo2
Servo servo1;
//<>


void setup()
{
//serial
Serial.begin(9600);
//<>
servo2.attach(6);
servo1.attach(9);  
delay(2000);


}


#define SERVO_SPEED 25  //(minimum number of milliseconds per degree)

int servo1_pos = 45;  // desired angle for servo1
int servo2_pos = 45;  // desired angle for servo2


void loop() 
{ 
  
static unsigned long servo_time;
 
 // check time since last servo position update
 if ((millis()-servo_time) >= SERVO_SPEED) {
   servo_time = millis(); // save time reference for next position update
   
   // update servo1 position
   // if desired position is different from current position move one step left or right
   if (servo1_pos > servo1.read()) servo1.write(servo1.read() + 1);
   else if (servo1_pos < servo1.read()) servo1.write(servo1.read() - 1);

   // update servo2 position
   // if desired position is different from current position move one step left or right
   if (servo2_pos > servo2.read()) servo2.write(servo2.read() + 1);
   else if (servo2_pos < servo2.read()) servo2.write(servo2.read() - 1);
 }
  

} 
