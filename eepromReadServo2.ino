/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <EEPROM.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

int address = 0;
byte value;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object


}

void loop() 
{ 
  // read a byte from the current address of the EEPROM
  value = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
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
  address = address + 1;
  if(address == EEPROM.length())
    address = 0;
    
  /***
    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an 
    EEPROM address is also doable by a bitwise and of the length - 1.
    
    ++address &= EEPROM.length() - 1;
  ***/
  value = map(value, 0, 255, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(value);    

  delay(50);

//BUTTON SERIAL
 if (Serial.peek() == 'c') {
     val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
     val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
     myservo.write(val);                  // sets the servo position according to the scaled value
     Serial.println(val); 
     delay(15);                           // waits for the servo to get there
    }
    else if (Serial.peek() == 'd')  
    {
    Serial.read();
    delay(5000); 
    }
    else if (Serial.peek() == 'a')
    {
    Serial.read();
    delay(5000); 
    }
  while (Serial.available() > 0 ) {
    Serial.read();
    }
} 
