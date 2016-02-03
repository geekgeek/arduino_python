//Button plate code.
// Connected 10 buttons

const int buttonPins[] = {4,5,6,7,8,9,10,11,12,13}; 
int buttonStates[] = {0,0,0,0,0,0,0,0,0,0};

String buttonNames[] = {"button 1","button 2","button 3","button 4","button 5","button 6","button 7","button 8","button 9","button 10"};
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
  buttonStates[5] = digitalRead(buttonPins[5]);
  buttonStates[6] = digitalRead(buttonPins[6]);
  buttonStates[7] = digitalRead(buttonPins[7]);
  buttonStates[8] = digitalRead(buttonPins[8]);
  buttonStates[9] = digitalRead(buttonPins[9]);


  if (buttonStates[0] == HIGH) 
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[0]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[1] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[1]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[2] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[2]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[3] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[3]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[4] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[4]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[5] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[5]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[6] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[6]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[7] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[7]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[8] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[8]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[9] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[9]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else if(buttonStates[10] == HIGH)
  {
    delay(waitTimes[1]);
    Serial.print(buttonNames[10]);
    Serial.print(buttonClickMessage);
    Serial.println();
  }
  else 
  {
    Serial.println(noButtonIsClickedMessage); 
  }
  
}
