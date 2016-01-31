//Arduino mega pins:
// SCETCH FOR CONTROLLING 2 SERVOS WHO ARE TOWARDS EACH OTHER
//USED PINS:

//Analog pins: 
//0,1,2

//Dig.Pins: 
//22,23,24,25,26,27,28++,29,30,31,32,33,34
//PWM pins
// 3 are used
//SD Card Pins:
// cs / white : 4 / 53
// sck / orange : 13 / 52
// MOSI / blå :11 / 51
// MISO / orange : 12 / 50

#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;

//<pot>
int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer
int potpin3 = 2;  // analog pin used to connect the potentiometer
//</>

//<potRead>
int potval;
int potval2;
int potval3;
//</>

//<servos>
const int servoPin1 = 2;
const int servoPin2 = 3;
const int servoPin3 = 4;
//</>

void setup() 
{
  // put your setup code here, to run once:
 //<Open serial>
  Serial.begin(9600);
  //</>

servo1.attach(servoPin1);
servo2.attach(servoPin2);

}

void loop() 
{


potval = analogRead(potpin);
potval = map(potval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)


Serial.print(potval);
Serial.print(":::::");
Serial.print(180 - potval);
Serial.println();

int servValue2 = 180 - potval;

servo1.write(servValue2);
servo2.write(potval);
delay(100);
}
