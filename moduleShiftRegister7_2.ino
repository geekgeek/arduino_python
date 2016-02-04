/*
CONTROL 3 SHIFT REGISTERS.

MASTER SHIFT REGISTER:
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


SLAVE SHIFT REGISTER:
1  output led          !  *  !   VCC
2  output led          !     !   output led
3  output led          !     !   datapin Connection from pin 8 right side on master register          
4  output led          !     !   (GND). is connected to GND
5  output led          !     !   latchpin // DUAL PIN must be connected to 3 shift register
6  output led          !     !   Clockpin // DUAL PIN must be connected to 3 shift register
7  output led          !     !   (VCC). is connected to +
8  GND                 !     !    //ONLY USED FOR CONNECTING to slave shift register. Connection from this pin to datapin on slave register.


*/



int latchPin = 2; // pin 12 on 595 : STCP
int dataPin = 3; // pin 14 on 595
int clockPin = 4; // pin 11 on 595


byte allPortsHigh[] = {0b11111111,0b11111111, 0b11111111};
byte allPortsLow[]  = {0b00000000,0b00000000,0b00000000};

byte redLightsOn[]    = {0b11110000,0b11110000,0b00000000};
byte greenLightsOn[]  = {0b00000011,0b00001111,0b00000001};
byte yellowLightsOn[] = {0b00001100,0b00000000,0b11111110};


byte port1High[] = {0b10000000,0b00000000,0b00000000};
byte port2High[] = {0b01000000,0b00000000,0b00000000};
byte port3High[] = {0b00100000,0b00000000,0b00000000};
byte port4High[] = {0b00010000,0b00000000,0b00000000};
byte port5High[] = {0b00001000,0b00000000,0b00000000};
byte port6High[] = {0b00000100,0b00000000,0b00000000};
byte port7High[] = {0b00000010,0b00000000,0b00000000};
byte port8High[] = {0b00000001,0b00000000,0b00000000};

byte port9High[]  = {0b00000000,0b10000000,0b00000000};
byte port10High[] = {0b00000000,0b01000000,0b00000000};
byte port11High[] = {0b00000000,0b00100000,0b00000000};
byte port12High[] = {0b00000000,0b00010000,0b00000000};
byte port13High[] = {0b00000000,0b00001000,0b00000000};
byte port14High[] = {0b00000000,0b00000100,0b00000000};
byte port15High[] = {0b00000000,0b00000010,0b00000000};
byte port16High[] = {0b00000000,0b00000001,0b00000000};

byte port17High[] = {0b00000000,0b00000000,0b10000000};
byte port18High[] = {0b00000000,0b00000000,0b01000000};
byte port19High[] = {0b00000000,0b00000000,0b00100000};
byte port20High[] = {0b00000000,0b00000000,0b00010000};
byte port21High[] = {0b00000000,0b00000000,0b00001000};
byte port22High[] = {0b00000000,0b00000000,0b00000100};
byte port23High[] = {0b00000000,0b00000000,0b00000010};
byte port24High[] = {0b00000000,0b00000000,0b00000001};



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
SetBinaryNumber(redLightsOn[0],redLightsOn[1],redLightsOn[2]);


}


//########################################################
//########################################################
//########################################################
//########################################################
// 1 2 4 8 16 32 64 128      256 512 1024 2048 4096  8192  16384  32768       65536  131072  262144  524288  1048576  2097152  4194304  8388608
//LOOP
void loop() 
{

}




//########################################################
//########################################################
//########################################################
//########################################################
//CUSTOM FUNCTIONS

/* BINARY SET FOR 3 SHIFT REGISTERS:
 * Set binary numbers for 3 shift registers
 * 
*/
void SetBinaryNumber(byte binary1, byte bynary2, byte binary3)
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin,MSBFIRST , binary3);
shiftOut(dataPin, clockPin, MSBFIRST, bynary2);
shiftOut(dataPin, clockPin,MSBFIRST , binary1);





digitalWrite(latchPin, HIGH);
}


void turnOffAllPorts()
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, allPortsLow[0]);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsLow[1]);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsLow[2]);

digitalWrite(latchPin, HIGH);

delay(1000);
}



void turnOnAllPorts()
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, allPortsHigh[0]);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsHigh[1]);
shiftOut(dataPin, clockPin, MSBFIRST, allPortsHigh[2]);

digitalWrite(latchPin, HIGH);

delay(1000);
}

void codeSample1(int waitTime)
{
int waitForIt = waitTime;

SetBinaryNumber(port1High[0], port1High[1],port1High[2]);
delay(waitForIt);
SetBinaryNumber(port2High[0], port2High[1],port2High[2]);
delay(waitForIt);
SetBinaryNumber(port3High[0], port3High[1],port3High[2]);
delay(waitForIt);
SetBinaryNumber(port4High[0], port4High[1],port4High[2]);
delay(waitForIt);
SetBinaryNumber(port5High[0], port5High[1],port5High[2]);
delay(waitForIt);
SetBinaryNumber(port6High[0], port6High[1],port6High[2]);
delay(waitForIt);
SetBinaryNumber(port7High[0], port7High[1],port7High[2]);
delay(waitForIt);
SetBinaryNumber(port8High[0], port8High[1],port8High[2]);
delay(waitForIt);

SetBinaryNumber(port9High[0], port9High[1],port9High[2]);
delay(waitForIt);
SetBinaryNumber(port10High[0], port10High[1],port10High[2]);
delay(waitForIt);
SetBinaryNumber(port11High[0], port11High[1],port11High[2]);
delay(waitForIt);
SetBinaryNumber(port12High[0], port12High[1],port12High[2]);
delay(waitForIt);
SetBinaryNumber(port13High[0], port13High[1],port13High[2]);
delay(waitForIt);
SetBinaryNumber(port14High[0], port14High[1],port14High[2]);
delay(waitForIt);
SetBinaryNumber(port15High[0], port15High[1],port15High[2]);
delay(waitForIt);
SetBinaryNumber(port16High[0], port16High[1],port16High[2]);
delay(waitForIt);

SetBinaryNumber(port17High[0], port17High[1],port17High[2]);
delay(waitForIt);
SetBinaryNumber(port18High[0], port18High[1],port18High[2]);
delay(waitForIt);
SetBinaryNumber(port19High[0], port19High[1],port19High[2]);
delay(waitForIt);
SetBinaryNumber(port20High[0], port20High[1],port20High[2]);
delay(waitForIt);
SetBinaryNumber(port21High[0], port21High[1],port21High[2]);
delay(waitForIt);
SetBinaryNumber(port22High[0], port22High[1],port22High[2]);
delay(waitForIt);
SetBinaryNumber(port23High[0], port23High[1],port23High[2]);
delay(waitForIt);
SetBinaryNumber(port24High[0], port24High[1],port24High[2]);
delay(waitForIt);

}

//########################################################
