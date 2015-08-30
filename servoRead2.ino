
#include <Servo.h>

Servo myservo; 
int pos = 0;    // variable to store the servo position

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);          //  setup serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

// the loop function runs over and over again forever
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}
