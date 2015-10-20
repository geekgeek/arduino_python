// https://www.youtube.com/watch?v=_LCCGFSMOr4
// Button holds light on ore off. Working. Before 16 minutes on video.

int switchPin = 8;
int ledPin = 13;
boolean lastButton = LOW;
boolean ledOn = false;
boolean currentButton = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last)
{
  //custom function
  boolean current = digitalRead(switchPin);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);  
  }
  return current;
    
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;
  }
    lastButton = currentButton;
  digitalWrite(ledPin, ledOn);
}
