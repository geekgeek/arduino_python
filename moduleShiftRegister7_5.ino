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



SLAVE SHIFT REGISTER:
1  output led          !  *  !   VCC
2  output led          !     !   output led
3  output led          !     !   datapin Connection from pin 8 right side on master register          
4  output led          !     !   (GND). is connected to GND
5  output led          !     !   latchpin // DUAL PIN must be connected to 3 shift register
6  output led          !     !   Clockpin // DUAL PIN must be connected to 3 shift register
7  output led          !     !   (VCC). is connected to +
8  GND                 !     !    //ONLY USED FOR CONNECTING to slave shift register. Connection from this pin to datapin on slave register.



Control shift register with binary code with arduino
Latchpin low  = receiving data enabled
Latchpin high = sending data out in the real world
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

  int x;
byte portInitState[7];
int portArrHigh[] =   {1,1,1,1,1,1,1,1};
int portArrLow[] =    {0,0,0,0,0,0,0,0};

//########################################################
//########################################################
//########################################################
//########################################################
//SETUP
void setup() 
{
Serial.begin(9600);
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
setBinaryValues();
//setBinaryPort(allPortsLow);
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
void setBinaryValues()
{

for(x = 0; x < 25; x += 1)
{
  Serial.println(x);
  delay(500) ;


digitalWrite(latchPin, LOW);

digitalWrite(clockPin, HIGH);
digitalWrite(dataPin, 0 ); // LOW = 0 HIGH = 1

digitalWrite(clockPin, LOW);

digitalWrite(latchPin, HIGH);
}

}



void setBinaryPort(byte binary1[])
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin,MSBFIRST , binary1[2]);
shiftOut(dataPin, clockPin, MSBFIRST, binary1[1]);
shiftOut(dataPin, clockPin,MSBFIRST , binary1[0]);

digitalWrite(latchPin, HIGH);
}

/* BINARY SET FOR 3 SHIFT REGISTERS:
 * Set binary numbers for 3 shift registers
 * 
*/
void setBinaryNumber(byte binary1, byte bynary2, byte binary3)
{
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin,MSBFIRST , binary3);
shiftOut(dataPin, clockPin, MSBFIRST, bynary2);
shiftOut(dataPin, clockPin,MSBFIRST , binary1);

digitalWrite(latchPin, HIGH);
}





void codeSample1(int waitTime)
{
int waitForIt = waitTime;

setBinaryPort(allPortsHigh);
delay(waitForIt);
setBinaryPort(allPortsLow);

delay(waitForIt);
setBinaryPort(redLightsOn);
delay(waitForIt);
setBinaryPort(yellowLightsOn);
delay(waitForIt);
setBinaryPort(greenLightsOn);
delay(waitForIt);


setBinaryPort(port1High);
delay(waitForIt);
setBinaryPort(port2High);
delay(waitForIt);
setBinaryPort(port3High);
delay(waitForIt);
setBinaryPort(port4High);
delay(waitForIt);
setBinaryPort(port5High);
delay(waitForIt);
setBinaryPort(port6High);
delay(waitForIt);
setBinaryPort(port7High);
delay(waitForIt);
setBinaryPort(port8High);
delay(waitForIt);

setBinaryPort(port9High);
delay(waitForIt);
setBinaryPort(port10High);
delay(waitForIt);
setBinaryPort(port11High);
delay(waitForIt);
setBinaryPort(port12High);
delay(waitForIt);
setBinaryPort(port13High);
delay(waitForIt);
setBinaryPort(port14High);
delay(waitForIt);
setBinaryPort(port15High);
delay(waitForIt);
setBinaryPort(port16High);
delay(waitForIt);

setBinaryPort(port17High);
delay(waitForIt);
setBinaryPort(port18High);
delay(waitForIt);
setBinaryPort(port19High);
delay(waitForIt);
setBinaryPort(port20High);
delay(waitForIt);
setBinaryPort(port21High);
delay(waitForIt);
setBinaryPort(port22High);
delay(waitForIt);
setBinaryPort(port23High);
delay(waitForIt);
setBinaryPort(port24High);
delay(waitForIt);

}

//########################################################
