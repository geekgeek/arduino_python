

#include <Servo.h> 
 
Servo myservo;  
 
int pos = 0;  


void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
} 
 
void loop() 
{
  delay(1000);
  Serial.println(myservo.read());

} 
