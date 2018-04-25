/*
HEADER FILE
*/
/*
  Traffic.h - library
*/
#ifndef Traffic_h
#define Traffic_h

#include "Arduino.h"

class Traffic
{
 public:
  Traffic(int pin);
   void blinkonce();
   void isbelow(int theval);
   int getNumber(int num);
   void blinkdelay(int delaytime);
  private:
   int _pin;

};

#endif






/*
###############################################################################
###############################################################################
###############################################################################
###############################################################################
CPP FILE
*/
/*
  Traffic.cpp - library
*/

#include "Arduino.h"
#include "Traffic.h"

/*
CONSTRUCTOR
*/
Traffic::Traffic(int pin)
{
  pinMode(pin, OUTPUT);
 _pin = pin;
}


/*
random function
*/
void Traffic::blinkonce()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(1000);
}


/*
if function
*/
void Traffic::isbelow(int theval)
{
if(theval > 10)
{

  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(1000);
}
else
{

  digitalWrite(_pin, HIGH);
  delay(300);
  digitalWrite(_pin, LOW);
  delay(300);
}
}


/*
return the number
*/
int Traffic::getNumber(int num)
{
return num;
}


/*
blink in specified milliseconds
*/
void Traffic::blinkdelay(int delaytime)
{

  digitalWrite(_pin, HIGH);
  delay(delaytime);
  digitalWrite(_pin, LOW);
  delay(delaytime);
}


