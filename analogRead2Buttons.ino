/*
  AnalogReadSerial
  Reads an analog input on pin 0.
  Good for reading 2 buttons on a breadboard.
 */

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);


  if (sensorValue > 1000) {
    // turn LED on:
    Serial.println("Button 1 is pressed");
    Serial.println(sensorValue);
    delay(1000);        // delay in between reads for stability
  }
  else if (sensorValue > 450)
  {
    // do Thing B
    Serial.println("Button 2 is pressed");
    Serial.println(sensorValue);
    delay(1000);        // delay in between reads for stability
  }
  else
  {
    Serial.println(sensorValue);
  }
  
}
