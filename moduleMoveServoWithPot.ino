#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
//pot
int potpin = 0; 
int potpin2 = 1;
int potpin3 = 2;

int val;
int val2;
int val3;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  servo2.attach(3);
  servo3.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
//pot
val = analogRead(potpin);
val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

val2 = analogRead(potpin2);
val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

val3 = analogRead(potpin3);
val3 = map(val3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
//pot 
servo1.write(val);
servo2.write(val2);
servo3.write(val3);
}
