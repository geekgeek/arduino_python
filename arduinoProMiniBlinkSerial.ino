/*
Arduino pro mini.
New ATMEGA328 5V 16Mhz

#########################
Microcontroller  ATmega328

Operating Voltage 5V 
Input Voltage 5 - 12 V (5V model)

Digital I/O Pins  14 (of which 6 provide PWM output)
Analog Input Pins 6

DC Current per I/O Pin  40 mA

Flash Memory  32 kB (of which 0.5 kB used by bootloader)
SRAM  2 kB
EEPROM  1 kB
Clock Speed 16 MHz (5V model)
#########################
*/

void setup() {
   Serial.begin(9600);
   pinMode(13, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);

  Serial.print("Original:");
  Serial.print(sensorValue);
  Serial.print("\t");
  
  sensorValue = map(sensorValue, 200, 400, 50, 200);
  Serial.print("Mapped:");
  Serial.print(sensorValue);
  Serial.println();
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(400);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(400);              // wait for a second

}
