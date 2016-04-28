/*Garage opener
 *
 *pot:
 *1 = 5v
 *2 = signal
 *3 = gnd
 */

const int buttonPin = 7;
const int ledPin =  13;   
int buttonState = 0;
int sensorValue;
int potValue1;

//##################################################################################
//##################################################################################
//##################################################################################
void setup() 
{
  // initialize digital pin 13 as an output.
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("begin");
}



//##################################################################################
//##################################################################################
//##################################################################################
void loop() 
{
  sensorValue = analogRead(A0);
  buttonState = digitalRead(buttonPin);
  

  if (buttonState == HIGH) 
  {
    //waiting
    delay(600);

      if (digitalRead(buttonPin) == HIGH) 
      {
       turnOnLed();
       setRelay();
       Serial.println(buttonState);
       }
  }
  
  else if(sensorValue < 50)
  {
   //waiting
  Serial.println(sensorValue);
    delay(5);
    
    if(analogRead(A0) < 50)
    {
  
      setRelay();
    }
  }
  else
  {
    turnOffLed();
  }
  
}


//##################################################################################
//##################################################################################
//##################################################################################
//CUSTOM FUNCTIONS START 
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
  potValue1 = analogRead(A1);
  int mappedPotValue1 = map(potValue1,0, 1023, 10, 2000);
  Serial.println(mappedPotValue1);
  turnOnLed();
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(10);              // wait for a second
  delay(mappedPotValue1);//900
}
