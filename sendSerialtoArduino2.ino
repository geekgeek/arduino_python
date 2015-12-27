//Turn off or on an led on the arduino with serial
// c = on
// d = off

int led = 10;
int state;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  while (Serial.available() > 0 ) 
  {
     if (Serial.peek() == 'c') {
    Serial.read();
    state = Serial.parseInt();
    digitalWrite(led,HIGH);
    }

    if (Serial.peek() == 'd') {
    Serial.read();
    state = Serial.parseInt();
    digitalWrite(led,LOW);
    }
    
    Serial.read();
    }
}
