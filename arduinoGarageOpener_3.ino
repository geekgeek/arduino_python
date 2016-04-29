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
int potValue2;
int potValue3;

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
  Serial.println("Begin");
}



//##################################################################################
//##################################################################################
//##################################################################################
void loop() 
{
  sensorValue = analogRead(A0);
  buttonState = digitalRead(buttonPin);
  
      //<pot3>
      potValue3 = analogRead(A3);
      int mappedPotValue3 = map(potValue3,0, 1023, 0, 1000);
      //</>

      
  if (buttonState == HIGH) 
  {
    //waiting
      //<pot1>
      potValue1 = analogRead(A1);
      int mappedPotValue1 = map(potValue1,0, 1023, 10, 3000);
      Serial.println(mappedPotValue1);
      //</>
      
      delay(mappedPotValue1);//600

      if (digitalRead(buttonPin) == HIGH) 
      {
       turnOnLed();
       setRelay();
       Serial.println(buttonState);
       }
  }
  
  else if(sensorValue < mappedPotValue3) //50
  {
   //waiting
   Serial.println(mappedPotValue3);
  Serial.println(sensorValue);
    delay(5);
    
    if(analogRead(A0) < mappedPotValue3) //50
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

    //<pot2>
  potValue2 = analogRead(A2);
  int mappedPotValue2 = map(potValue2,0, 1023, 20, 2000);
  Serial.println(mappedPotValue2);
  //</>

  
  turnOnLed();
  digitalWrite(12, HIGH);  
  delay(mappedPotValue2);            //600
  digitalWrite(12, LOW);  
  delay(mappedPotValue2);           //900
}
