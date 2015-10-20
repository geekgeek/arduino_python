//https://www.youtube.com/watch?v=_LCCGFSMOr4
// in video 18:50
//Button 1 final
// Incrementing light from LED when pushing the button

int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
int ledLevel = 0;
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
    ledLevel = ledLevel + 51;
  }
    lastButton = currentButton;

  if(ledLevel > 255) ledLevel = 0;
  analogWrite(ledPin, ledLevel);
}
