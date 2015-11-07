/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified 2015
 by geekgeek
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <EEPROM.h>

Servo myservo;  // create servo object to control a servo
int addr = 0; 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

int address = 0;
byte value;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object


}

int a = 0;

void loop() 
{
 if(a < 1024) {
    a ++;
    //Serial.print(a);
    //Serial.print("+");



 /***
    Need to divide by 4 because analog inputs range from
    0 to 1023 and each byte of the EEPROM can only hold a
    value from 0 to 255.
  ***/
  
  int val = analogRead(0) / 4;

  /***
    Write the value to the appropriate byte of the EEPROM.
    these values will remain there when the board is
    turned off.
  ***/
  
  EEPROM.write(addr, val);
  Serial.print(addr);
  Serial.print("\t");
  Serial.print(val);
  Serial.println();

  /***
    Advance to the next address, when at the end restart at the beginning.    
    
    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.
    
    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.    
  ***/
  addr = addr + 1; 
  if(addr == EEPROM.length())
    addr = 0;
    
    
  /***
    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an 
    EEPROM address is also doable by a bitwise and of the length - 1.
    
    ++addr &= EEPROM.length() - 1;
  ***/


  delay(100);

}

} 
