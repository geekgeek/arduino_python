#include <Servo.h>

Servo servo1;

int potpin = 0; 

int val1 = 20;
int val2 = 100;

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

//####################################################################################
//####################################################################################
//####################################################################################
//START SETUP
void setup() 
{
 pinMode(buttonPin, INPUT);
 
 servo1.attach(3);

     // Open serial
  Serial.begin(9600);
}

//####################################################################################
//####################################################################################
//####################################################################################
//START LOOP
void loop() 
{
buttonState = digitalRead(buttonPin);

 if (buttonState == LOW) 
  {
    Serial.println("Button 1 is pressed");
    delay(1000);
    codeblock1();
  }

}

//####################################################################################
//####################################################################################
//####################################################################################
// CUSTOM FUNCTIONS
void codeblock1()
{

// goes from val1 number to val2 number with a increment of 1 if the values are not the same.
while(val1 != val2)
{
  if(val1 < val2)
  {
  val1 = val1 + 1;
  Serial.println(val1);
  delay(100);
  }

  else if(val1 > val2)
  {
  val1 = val1 - 1;
  Serial.println(val1);
  delay(100);
  }
}
