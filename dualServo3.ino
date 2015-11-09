
#include <Servo.h>

Servo myservo;  

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
delay(2000);


}

int max = 170;
int i = 1;
int x = 1;
int pos = 0;    // variable to store the servo position 
int pos2 = 0;

void loop() 
{ 
  //Servo1
  for(pos = 0; pos <= 170; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 170; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  //Servo2
  for(pos2 = 0; pos2 <= 170; pos2 += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos2 = 170; pos2>=0; pos2-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

} 
