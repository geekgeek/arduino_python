/*
SHIFT REGISTERS.

1  output led          !  *  !   VCC
2  output led          !     !   output led
3  output led          !     !   datapin
4  output led          !     !   (GND). is connected to GND
5  output led          !     !   latchpin
6  output led          !     !   Clockpin
7  output led          !     !   (VCC). is connected to +
8  GND                 !     !

Controle shift register with binary code with arduino
*/



int latchPin = 2; // pin 12 on 595 : STCP
int dataPin = 3; // pin 14 on 595
int clockPin = 4; // pin 11 on 595

int shiftPins[] = {latchPin, dataPin, clockPin};

byte allPortsHigh = 0b11111111;
byte allPortsLow  = 0b00000000;

byte port1High = 0b10000000;
byte port2High = 0b01000000;
byte port3High = 0b00100000;
byte port4High = 0b00010000;
byte port5High = 0b00001000;
byte port6High = 0b00000100;
byte port7High = 0b00000010;
byte port8High = 0b00000001;

byte portsHigh[] = {0b10000000,0b01000000,0b00100000,0b00010000,0b00001000,0b00000100,0b00000010,0b00000001 };

//########################################################
//########################################################
//########################################################
//########################################################
//SETUP
void setup() 
{
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
sendBinaryNumber(0b00011111);
}


//########################################################
//########################################################
//########################################################
//########################################################
//LOOP
void loop() 
{


}




//########################################################
//########################################################
//########################################################
//########################################################
//CUSTOM FUNCTIONS
void selectPORTNumberOn(int number)
{
/*
 * SELECT SHIFT REGISTER PORT NUMBER TO BE HIGH
 * Choose between value 0 - 7 if 1 shift register are connected
 * 0 = 1
 * 1 = 2
 * 2 = 3
 * 3 = 4
 * 4 = 5
 * 5 = 6
 * 6 = 7
 * 7 = 8
*/

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, portsHigh[number]);
digitalWrite(latchPin, HIGH);
delay(1000);
}

void turnOffAllPorts()
{
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsLow);
digitalWrite(latchPin, HIGH);
delay(1000);
}

void turnOnAllPorts()
{
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsHigh);
digitalWrite(latchPin, HIGH);
delay(1000);
}

void sendBinaryNumber(byte binaryNumber)
{
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber);
digitalWrite(latchPin, HIGH);
delay(1000);
}

//########################################################
