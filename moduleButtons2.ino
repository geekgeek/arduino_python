//Button plate code

const int buttonPins[] = {A1, A2, A3, A4, A5};    
int buttonStates[] = {0,0,0,0,0};

String buttonNames[] = {"button 1","button 2","button 3","button 4","button 5"};
String buttonClickMessage = " is pressed";
String noButtonIsClickedMessage = "No button is pressed";


int waitTimes[] = {10,100,1000};


void setup()
{
  Serial.begin(9600);
  pinMode(buttonPins[0], INPUT);
  pinMode(buttonPins[1], INPUT);
  pinMode(buttonPins[2], INPUT);
  pinMode(buttonPins[3], INPUT);
  pinMode(buttonPins[4], INPUT);
}

void loop() 
{
  delay(waitTimes[0]);
  
  buttonStates[0] = digitalRead(buttonPins[0]);
  buttonStates[1] = digitalRead(buttonPins[1]);
  buttonStates[2] = digitalRead(buttonPins[2]);
  buttonStates[3] = digitalRead(buttonPins[3]);
  buttonStates[4] = digitalRead(buttonPins[4]);


  if (buttonStates[0] == LOW) 
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[0]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[1] == LOW)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[1]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[2] == LOW)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[2]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[3] == LOW)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[3]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[4] == LOW)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[4]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else 
  {
    Serial.println(noButtonIsClickedMessage); 
  }
  
}
