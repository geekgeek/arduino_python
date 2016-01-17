//https://www.youtube.com/watch?v=XUuXq4J4u14
//BUTTONS
const int buttonPin = 8;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

const int buttonPin2 = 7;     // the number of the pushbutton pin
int buttonState2 = 0;         // variable for reading the pushbutton status

const int buttonPin3 = 2;     // the number of the pushbutton pin
int buttonState3 = 0;         // variable for reading the pushbutton status
//</>

void setup() 
{
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  Serial.begin(9600);
  
}

void loop() 
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    Serial.println("Button 1 is pressed");
    delay(1000);
  }
  else if (buttonState2 == HIGH) 
  {
    Serial.println("Button 2 is pressed");
    delay(1000);
  }
  else if (buttonState3 == HIGH) 
  {
    Serial.println("Button 3 is pressed");
    delay(1000);
  }
  else 
  {
   Serial.println("button is not pressed");
   delay(100);
   
  }


}
