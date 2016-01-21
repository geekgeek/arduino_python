//https://www.youtube.com/watch?v=XUuXq4J4u14
//http://www.electroschematics.com/8964/turn-on-led-button-arduino/
//http://waihung.net/arduino-tip-turn-your-analog-pins-into-digital-io/
//https://www.arduino.cc/en/Main/arduinoBoardMega

//INPUTS:

//<analog inputs:>
// potmeter1 : 0 / 0
// potmeter2 : 1 / 1
// potmeter3 : 2 / 2
//</>

//<buttons>
// 7 digital input ports
// 22,23,24,25,26,27,28++,29,30,31
//</>

//<status Led>
// 1 digital input port
// 32
//</>

//<servos>
// 3 digital PWM ports
//</>

//< SD CARD>
// Ardunio uno:
// cs / white : 4 / 53
// sck / orange : 13 / 52
// MOSI / blå :11 / 51
// MISO / orange : 12 / 50
// VCC / rød : 5 v
// GND / svart : ground

//</>
//</>

#include <SPI.h>
#include <SD.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

File myFile;
//pot
int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer
int potpin3 = 2;  // analog pin used to connect the potentiometer
//pot

//potRead
int potval;
int potval2;
int potval3;
//</>

//SD Write
int valWrite;
int valWrite2;
int valWrite3;


//SD READ
int val;
int val2;
int val3;


//regex
String part1;
String part2;
String part3;

//BUTTONS
const int buttonPin = 22;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

const int buttonPin2 = 23;     // the number of the pushbutton pin
int buttonState2 = 0;         // variable for reading the pushbutton status

const int buttonPin3 = 24;     // the number of the pushbutton pin
int buttonState3 = 0;         // variable for reading the pushbutton status

const int buttonPin4 = 25;     // the number of the pushbutton pin
int buttonState4 = 0;         // variable for reading the pushbutton status

const int buttonPin5 = 26;     // the number of the pushbutton pin
int buttonState5 = 0;         // variable for reading the pushbutton status
//Button plate 2:
const int buttonPin6 = 27;     // the number of the pushbutton pin
int buttonState6 = 0;         // variable for reading the pushbutton status

const int buttonPin7 = 28;     // the number of the pushbutton pin
int buttonState7 = 0;         // variable for reading the pushbutton status

const int buttonPin8 = 29;     // the number of the pushbutton pin
int buttonState8 = 0;         // variable for reading the pushbutton status

const int buttonPin9 = 30;     // the number of the pushbutton pin
int buttonState9 = 0;         // variable for reading the pushbutton status

const int buttonPin10 = 31;     // the number of the pushbutton pin
int buttonState10 = 0;         // variable for reading the pushbutton status
//</>

//STATEBUTTON:
int LED = 2;
int stateLED = LOW;
int previous = LOW;
long time = 0;
long debounce = 200;
//</>

//led
const int statusLed = 32;
const int errorLed = 33;

//sd card
const int sdCSPin = 53;

// servos
const int servoPin1 = 2;
const int servoPin2 = 3;
const int servoPin3 = 4;
//</>
void setup() 
{

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
  pinMode(buttonPin9, INPUT);
  pinMode(buttonPin10, INPUT);

  pinMode(statusLed, OUTPUT);
    // Open serial
  Serial.begin(9600);
  
  //SD CARD INITIALIZING
  Serial.print("Initializing SD card...");
  if (!SD.begin(sdCSPin)) 
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  //</>
}

void loop() 
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);
  buttonState9 = digitalRead(buttonPin9);
  buttonState10 = digitalRead(buttonPin10);
  
  //<statusLed>
  statusLedOff();
  errorLedOff();
  //</>
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    Serial.println("Button 1 is pressed");
    sdWriteServoValue();
    delay(1000);
  }
  else if (buttonState2 == HIGH) 
  {
    statusLedOn();
    Serial.println("Button 2 is pressed");
    delay(1000);
  }
  else if(buttonState3 == HIGH && previous == LOW && millis() - time > debounce) //BUTTONSTATE
      {
        if(stateLED == HIGH){
          stateLED = LOW; 
          moveServosWithPotOff();
          Serial.println("low");
        } else {
           stateLED = HIGH;
           moveServosWithPotOn();
           Serial.println("High"); 
        }
        time = millis();
      }
  else if (buttonState4 == HIGH) 
  {
    sdReadServos();
    Serial.println("Button 4 is pressed");
    delay(1000);
  }
  else if (buttonState5 == HIGH) 
  {
    deleteSDFile();
    Serial.println("Button 5 is pressed");
    delay(1000);
  }
  else if (buttonState6 == HIGH) 
  {
    statusLedOn();
    Serial.println("Button 6 is pressed");
    delay(1000);
  }
  else if (buttonState7 == HIGH) 
  {
    statusLedOn();
    Serial.println("Button 7 is pressed");
    delay(1000);
  }
  else if (buttonState8 == HIGH) 
  {
    statusLedOn();
    Serial.println("Button 8 is pressed");
    delay(1000);
  }
  else if (buttonState9 == HIGH) 
  {
    statusLedOn();
    Serial.println("Button 9 is pressed");
    delay(1000);
  }
  else if (buttonState10 == HIGH) 
  {
    statusLedOn();
    Serial.println("Button 10 is pressed");
    delay(1000);
  }
  else 
  {
    
   Serial.println("button is not pressed");
   delay(100);

  }

previous == buttonState3;
}

void sdReadServos()
{
   //Servo
  servo1.attach(servoPin1);  
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  //<>

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test7.txt", FILE_READ);

  if (myFile) 
  {
    Serial.println("test7.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) 
    {
      //<READ LINE BY LINE>
      String line = myFile.readStringUntil('\n');
      
      part1 = line.substring(line.indexOf("<servo1>")+8);
      part2 = line.substring(line.indexOf("<servo2>")+8);
      part3 = line.substring(line.indexOf("<servo3>")+8);
      int convLine = part1.toInt();
      int convLine2 = part2.toInt();
      int convLine3 = part3.toInt();

      int readServo1 = servo1.read();
      int readServo2 = servo2.read();
      int readServo3 = servo3.read();
      
      //calculate variable time. Get the max value from the servos for the 3 servos.
      int sum1 = max(convLine, readServo1) - min(convLine, readServo1);
      int sum2 = max(convLine2, readServo2) - min(convLine2, readServo2);
      int sum3 = max(convLine3, readServo3) - min(convLine3, readServo3);

      int waitExtra = max(max(sum1, sum2), sum3);
      //</>
      //<Servo>
      Serial.print(convLine);
      Serial.print("--");
      Serial.print(servo1.read());
      Serial.print("--");
      Serial.print(waitExtra);
      Serial.print("--");
      Serial.print("--");
      Serial.print(convLine2);
      Serial.print("--");
      Serial.print(servo2.read());
      Serial.print("--");
      Serial.print("--");
      Serial.print(convLine3);
      Serial.print("--");
      Serial.print(servo3.read());

      servo1.write(convLine);
      servo2.write(convLine2);
      servo3.write(convLine3);

      Serial.println();
      //<>
      statusLedOn();
      delay(100);
      delay(6*waitExtra);
      //<READ LINE BY LINE STOP>
    }
    // close the file:
    myFile.close();
  servo1.detach();  
  servo2.detach();
  servo3.detach();
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
    myFile.close();
    errorLedOn();
    delay(1000);
  }
}

void sdWriteServoValue()
{
   myFile = SD.open("test7.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) 
  {
    Serial.print("Writing to test2.txt...");
    //pot
   valWrite = analogRead(potpin);
   valWrite = map(valWrite, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 

   valWrite2 = analogRead(potpin2);
   valWrite2 = map(valWrite2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

   valWrite3 = analogRead(potpin3);
   valWrite3 = map(valWrite3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
   // write 
    
    
    myFile.print("<servo1>");
    myFile.print(String(valWrite));
    myFile.print("</servo1>");

    myFile.print("<servo2>");
    myFile.print(String(valWrite2));
    myFile.print("</servo2>");

    myFile.print("<servo3>");
    myFile.print(String(valWrite3));
    myFile.print("</servo3>");

    myFile.println();
    // close the file:
    myFile.close();
    Serial.println("done.");
    statusLedOn();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test2.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test7.txt");
  if (myFile) {
    Serial.println("test7.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void moveServosWithPotOn()
{
//Servo
servo1.attach(servoPin1);  
servo2.attach(servoPin2);
servo3.attach(servoPin3);
//<>
    // read from the file until there's nothing else in it:
 
      while (digitalRead(buttonPin2) == LOW) 
      {
          potval = analogRead(potpin);
          potval = map(potval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
          
          potval2 = analogRead(potpin2);
          potval2 = map(potval2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
          
          potval3 = analogRead(potpin3);
          potval3 = map(potval3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
          //pot 
         
          servo1.write(potval);
          servo2.write(potval2);
          servo3.write(potval3);  
  
          Serial.print(potval);
          Serial.print("--");
          Serial.print(potval2);
          Serial.print("--");
          Serial.print(potval3);
          Serial.println();
          delay(10);
          //<READ LINE BY LINE STOP>
          statusLedOn();
        }
}

void moveServosWithPotOff()
{
  
  servo1.detach();  
  servo2.detach();
  servo3.detach();
  statusLedOn();
  delay(500);
}

void readSdCard()
{

  
 // re-open the file for reading:
  myFile = SD.open("test7.txt");
  if (myFile) {
    Serial.println("test7.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void deleteSDFile()
{
 
  // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove("test7.txt");
  
  if (SD.exists("test7.txt")) {
    Serial.println("test7.txt exists.");
    delay(1000);
    statusLedOn();
  } else {
    Serial.println("test7.txt doesn't exist.");
    delay(1000);
    errorLedOn();
  }
}

void statusLedOn()
{
digitalWrite(statusLed,HIGH);
}

void statusLedOff()
{
digitalWrite(statusLed,LOW);
}

void errorLedOn()
{
digitalWrite(errorLed,HIGH);
}

void errorLedOff()
{
digitalWrite(errorLed,LOW);
}
