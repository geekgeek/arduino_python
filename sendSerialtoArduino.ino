/*
 * https://www.youtube.com/watch?v=ts81ZTdY_DQ
 * Serial send
 * Send c0 from the computer and you take off the LED on the arduino
 * send c1 from the computer and you turn on the LED on the arduino
 */
int led = 13;
int state;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.peek() == 'c') {
    Serial.read();
    state = Serial.parseInt();
    digitalWrite(led,state);
    }
  while (Serial.available() > 0 ) {
    Serial.read();
    }
}
