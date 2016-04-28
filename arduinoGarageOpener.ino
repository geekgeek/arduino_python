/*Garage opener
 */

const int buttonPin = 7;
const int ledPin =  13;   
int buttonState = 0;



void setup() 
{
  // initialize digital pin 13 as an output.
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}




void loop() 
{

  buttonState = digitalRead(buttonPin);
  int sensorValue = analogRead(A0);
  turnOffLed();


  if (buttonState == HIGH) 
  {
   turnOnLed();
   setRelay();
   Serial.println(buttonState);
  }
  
  else 
  {
    turnOffLed();
  }
  
  if(sensorValue < 500)
  {
  
  Serial.println(sensorValue);
  
  setRelay();
  
  }
  
}


//##################################################################################
//##################################################################################
//##################################################################################
//CUSTOM FUNCTIONS START ###########################################################
void turnOnLed()
{
  digitalWrite(8, HIGH);  
}

void turnOffLed()
{
  digitalWrite(8, LOW);  
}

void setRelay()
{
  turnOnLed();
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(10);              // wait for a second
  delay(900);

}
