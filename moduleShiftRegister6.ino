/*
CONTROL 2 SHIFT REGISTERS.

1  output led          !  *  !   VCC
2  output led          !     !   output led
3  output led          !     !   datapin ( Only for master shift register)            
4  output led          !     !   (GND). is connected to GND
5  output led          !     !   latchpin // DUAL PIN must be connected to 2 shift register
6  output led          !     !   Clockpin // DUAL PIN must be connected to 2 shift register
7  output led          !     !   (VCC). is connected to +
8  GND                 !     !    //ONLY USED FOR CONNECTING to 2 shift register. Connection from this pin to datapin on slave register.



Controle shift register with binary code with arduino

Latchpin low  = receiving data enabled
Latchpin high = sending data out in the real world
*/



int latchPin = 2; // pin 12 on 595 : STCP
int dataPin = 3; // pin 14 on 595
int clockPin = 4; // pin 11 on 595


byte allPortsHigh[] = {0b11111111,0b11111111};
byte allPortsLow[]  = {0b00000000,0b00000000};

byte port1High[] = {0b10000000,0b00000000};
byte port2High[] = {0b01000000,0b00000000};
byte port3High[] = {0b00100000,0b00000000};
byte port4High[] = {0b00010000,0b00000000};
byte port5High[] = {0b00001000,0b00000000};
byte port6High[] = {0b00000100,0b00000000};
byte port7High[] = {0b00000010,0b00000000};
byte port8High[] = {0b00000001,0b00000000};

byte port9High[]  = {0b00000000,0b10000000};
byte port10High[] = {0b00000000,0b01000000};
byte port11High[] = {0b00000000,0b00100000};
byte port12High[] = {0b00000000,0b00010000};
byte port13High[] = {0b00000000,0b00001000};
byte port14High[] = {0b00000000,0b00000100};
byte port15High[] = {0b00000000,0b00000010};
byte port16High[] = {0b00000000,0b00000001};


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



}


//########################################################
//########################################################
//########################################################
//########################################################
// 1 2 4 8 16 32 64 128    256 512 1024 2048 4096  8192  16384  32768
//LOOP
void loop() 
{
codeSample1(1000);
}




//########################################################
//########################################################
//########################################################
//########################################################
//CUSTOM FUNCTIONS

/* BINARY SET FOR 2 SHIFT REGISTERS:
 * Set binary numbers for 2 shift registers
 * 
*/
void SetBinaryNumber(byte binary1, byte bynary2)
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, bynary2);
shiftOut(dataPin, clockPin,MSBFIRST , binary1);

digitalWrite(latchPin, HIGH);

//delay(1000);
}


void turnOffAllPorts()
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, allPortsLow[0]);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsLow[1]);

digitalWrite(latchPin, HIGH);

delay(1000);
}



void turnOnAllPorts()
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, allPortsHigh[0]);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsHigh[1]);

digitalWrite(latchPin, HIGH);

delay(1000);
}

void codeSample1(int waitTime)
{
int waitForIt = waitTime;

SetBinaryNumber(port1High[0], port1High[1]);
delay(waitForIt);
SetBinaryNumber(port2High[0], port2High[1]);
delay(waitForIt);
SetBinaryNumber(port3High[0], port3High[1]);
delay(waitForIt);
SetBinaryNumber(port4High[0], port4High[1]);
delay(waitForIt);
SetBinaryNumber(port5High[0], port5High[1]);
delay(waitForIt);
SetBinaryNumber(port6High[0], port6High[1]);
delay(waitForIt);
SetBinaryNumber(port7High[0], port7High[1]);
delay(waitForIt);
SetBinaryNumber(port8High[0], port8High[1]);
delay(waitForIt);

SetBinaryNumber(port9High[0], port9High[1]);
delay(waitForIt);
SetBinaryNumber(port10High[0], port10High[1]);
delay(waitForIt);
SetBinaryNumber(port11High[0], port11High[1]);
delay(waitForIt);
SetBinaryNumber(port12High[0], port12High[1]);
delay(waitForIt);
SetBinaryNumber(port13High[0], port13High[1]);
delay(waitForIt);
SetBinaryNumber(port14High[0], port14High[1]);
delay(waitForIt);
SetBinaryNumber(port15High[0], port15High[1]);
delay(waitForIt);
SetBinaryNumber(port16High[0], port16High[1]);
delay(waitForIt);

}

//########################################################
