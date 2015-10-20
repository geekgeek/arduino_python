//https://www.youtube.com/watch?v=_LCCGFSMOr4
//Incrementing led + read serial.

int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
int ledLevel = 0;
boolean currentButton = LOW;

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  
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
    //<WHAT GOING TO HAPPEN WHEN PUSH THE BUTTON>
      ledLevel = ledLevel + 51;
      //<SERIAL>
      Serial.println(ledLevel);
      Serial.println("button pushed");
      //<>
    //<>
  }
    lastButton = currentButton;

  if(ledLevel > 255) ledLevel = 0;
  analogWrite(ledPin, ledLevel);
}
