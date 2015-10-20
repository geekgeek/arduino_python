//https://www.youtube.com/watch?v=_LCCGFSMOr4
// Led turns on when push button and holds the position on. and turns off.

int switchPin = 8;
int ledPin = 13;
boolean lastButton = LOW;
boolean ledOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH && lastButton == LOW)
  {
    ledOn = !ledOn;
    lastButton = HIGH;
  }
  else
  {
    lastButton = digitalRead(switchPin);  
  }
  digitalWrite(ledPin, ledOn);
}
