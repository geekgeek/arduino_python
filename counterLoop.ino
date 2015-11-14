/*
Simple counter who counts how many times an LED has blinked.
 */

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}


int counter = 0;

void loop() {
    Serial.print("pin has blinked:");
    Serial.print(counter);
    Serial.println();
    counter = counter + 1;
    
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
  
}
