/*
 * Driver ch340g
http://www.electrodragon.com/product/arduino-compatible-visduino-uno-r3/
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
Serial.println("hello world");
}
