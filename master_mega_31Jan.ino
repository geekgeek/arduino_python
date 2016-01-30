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

//<LED>
// 3 digital input ports
// 32,33,34
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
File myFile2;

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

//<SD Write>
int valWrite;
int valWrite2;
int valWrite3;
//</>

//<SD READ>
int val;
int val2;
int val3;
//</>

//<regex>
String part1;
String part2;
String part3;
//</>

//<BUTTONS>
//<button plate 1>
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
//</>

//<button plate 2:>
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
//</>

//<STATEBUTTON:>
int LED = 2;
int stateLED = LOW;
int previous = LOW;
long time = 0;
long debounce = 200;
//</>

//<led>
const int statusLed = 32;
const int errorLed = 33;
const int greenLed = 34;
//</>

//<sd card>
const int sdCSPin = 53;
//</>

//<servos>
const int servoPin1 = 2;
const int servoPin2 = 3;
const int servoPin3 = 4;
//</>

//#########################################################################
//#########################################################################
//#########################################################################
//#########################################################################
//<START SETUP>
void setup() 
{

  // <initialize the pushbutton pin as an input:>
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
  //</>
  
  //<initialise LED Pin as output>
  pinMode(statusLed, OUTPUT);
  pinMode(errorLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  //</>
  
  //<Open serial>
  Serial.begin(9600);
  //</>
  
  //<SD CARD INITIALIZING>
  Serial.print("Initializing SD card...");
  if (!SD.begin(sdCSPin)) 
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  //</>
}
//#########################################################################
//#########################################################################
//#########################################################################
//#########################################################################
//<START LOOP>
void loop() 
{
  // <read the state of the pushbutton value:>
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
  //</>
  
  //<statusLed>
  greenLedOff();
  statusLedOff();
  errorLedOff();
  //</>
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:

  //<BUTTONS BEGIN>
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
    continusRecording();
    Serial.println("Button 6 is pressed");
    delay(1000);
  }
  else if (buttonState7 == HIGH) 
  {
    statusLedOn();
    moveServosWithPotOff();
    Serial.println("Button 7 is pressed");
    delay(1000);
  }
  else if (buttonState8 == HIGH) 
  {
    deleteSDFile2();
    statusLedOn();
    Serial.println("Button 8 is pressed");
    delay(1000);
  }
  else if (buttonState9 == HIGH) 
  {
    
    continusRecordingRead();
    statusLedOn();
    Serial.println("Button 9 is pressed");
    delay(1000);
  }
  else if (buttonState10 == HIGH) 
  {
    myFile2.close();
    statusLedOn();
    Serial.println("Button 10 is pressed");
    Serial.println("file is closed");
    delay(1000);
  }
  else 
  {
   greenLedOn();
   Serial.println("button is not pressed");
   delay(100);
  }
  
//<stores value of previous state of buttonpin3>
previous == buttonState3;
//</>

//</BUTTONS END/>
}

//#########################################################################
//#########################################################################
//#########################################################################
//#########################################################################
//<START CUSTOM FUNCTIONS>
void sdReadServos()
{
  //<Servo>
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
      
      //<calculate variable time. Get the max value from the servos for the 3 servos.>
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
  //<open file on sd card>
   myFile = SD.open("test7.txt", FILE_WRITE);
  //</>
  
  // <if the file opened okay, write to it:>
  if (myFile) 
  {
    //<Serial message>
    Serial.print("Writing to test2.txt...");
    //</>
    
    //<Convert pot values from 0 - 1023 to 0 - 180>
   valWrite = analogRead(potpin);
   valWrite = map(valWrite, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 

   valWrite2 = analogRead(potpin2);
   valWrite2 = map(valWrite2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

   valWrite3 = analogRead(potpin3);
   valWrite3 = map(valWrite3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
   //</>
   
   //<write to file:> 
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
    //</>
    
    // <close the file:>
    myFile.close();
    //</>

    //<Serial message>
    Serial.println("done.");
    //</>
    
    //<Turn Status led on>
    statusLedOn();
    //</>
  } else {
    // <if the file didn't open, print an error:>
    Serial.println("error opening test2.txt");
    //</>
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
//<MOVE SERVOS FREELY WHILE MOVING THE POT>

//<Servo attach>
servo1.attach(servoPin1);  
servo2.attach(servoPin2);
servo3.attach(servoPin3);
//<>

      //<Move servos while button2 is not pressed>
      while (digitalRead(buttonPin2) == LOW) 
      {
          //<Convert pot values from 0 - 1023 to 0 - 180>
          potval = analogRead(potpin);
          potval = map(potval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
          
          potval2 = analogRead(potpin2);
          potval2 = map(potval2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
          
          potval3 = analogRead(potpin3);
          potval3 = map(potval3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
          //</>

         //<Move servos to the pot values>
          servo1.write(potval);
          servo2.write(potval2);
          servo3.write(potval3);  
          //</>

          //<Serial message>
          Serial.print(potval);
          Serial.print("--");
          Serial.print(potval2);
          Serial.print("--");
          Serial.print(potval3);
          Serial.println();
          //</>

          //<Delay time>
          delay(10);
          //</>

          //<Turn Status led on>
          statusLedOn();
          //</>
        }
}

void moveServosWithPotOff()
{
  //TURNS OFF THE POWER TO THE SERVOS
  
  //<Turn off servos>
  servo1.detach();  
  servo2.detach();
  servo3.detach();
  //</>
  
  //<Turn Status led on>
  statusLedOn();
  //</>
  
  //<Wait>
  delay(500);
  //</>
}

void readSdCard()
{
// <READ WHAT IS IN THE SD CARD SELECTED FILE>
  
 // <open file for reading:>
  myFile = SD.open("test7.txt");
  //</>
  
  if (myFile) 
  {
    Serial.println("test7.txt:");

    // <read from the file until there's nothing else in it:>
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    //</>
    
    // <close the file:>
    myFile.close();
    //</>
  } else 
  {
    //<if the file didn't open, print an error:>
    Serial.println("error opening test.txt");
    //</>
  }
  //</END>
}

void deleteSDFile()
{
  // <DELETE FILE ON SD CARD>
  
  //<Serial message>
  Serial.println("Removing example.txt...");
  //</>

  //<file on sd to be removed>
  SD.remove("test7.txt");
  //</>

  //<If SD Exists:>
  if (SD.exists("test7.txt")) 
  {
    //<Do this if SD FileExists>
    Serial.println("test7.txt exists.");
    delay(1000);
    statusLedOn();
    //</>
  } else 
  {
    //<Do this if SD Does Not Exist:>
    Serial.println("test7.txt doesn't exist.");
    delay(1000);
    errorLedOn();
    //</>
  }
  //</END>
}

void deleteSDFile2()
{
 
  // <DELETE FILE ON SD CARD>
  
  //<Serial message>
  Serial.println("Removing example.txt...");
  //</>
  
  //<file on sd to be removed>
  SD.remove("test8.txt");
  //</>
  
  //<If SD Exists:>
  if (SD.exists("test8.txt")) 
  {
    //<Do this if SD FileExists>
    Serial.println("test8.txt exists.");
    delay(1000);
    statusLedOn();
    //</>
  } else 
  {
    //<Do this if SD Does Not Exist:>
    Serial.println("test8.txt doesn't exist.");
    delay(1000);
    errorLedOn();
    //</>
  }
}

void statusLedOn()
{
//<YELLOW LED ON>
digitalWrite(statusLed,HIGH);
//</>
}

void statusLedOff()
{
//<YELLOW LED OFF>
digitalWrite(statusLed,LOW);
//</>
}

void errorLedOn()
{
//<RED LED ON>
digitalWrite(errorLed,HIGH);
//</>
}

void errorLedOff()
{
//<RED LED OFF>
digitalWrite(errorLed,LOW);
//</>
}

void greenLedOn()
{
  digitalWrite(greenLed,HIGH);
}

void greenLedOff()
{
  digitalWrite(greenLed,LOW);
}
void continusRecording()
{
// CONTINOUS RECORDING START

//<Servo attach>
servo1.attach(servoPin1);  
servo2.attach(servoPin2);
servo3.attach(servoPin3);
//</>

//<OPEN SD FILE FOR WRITING>
myFile2 = SD.open("test8.txt", FILE_WRITE);
//</>

//<If sd file is available:>
   if (myFile2) 
        {
          //<When button 10 is not clicked>
          while (digitalRead(buttonPin10) == LOW) 
            {
               //<When button 10 is not clicked, do this:>

               //<Serial message>
                Serial.print("Writing to test8.txt...");
               //</>
               
               //<Convert pot values from 0 - 1023 to 0 - 180>
               valWrite = analogRead(potpin);
               valWrite = map(valWrite, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
            
               valWrite2 = analogRead(potpin2);
               valWrite2 = map(valWrite2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
            
               valWrite3 = analogRead(potpin3);
               valWrite3 = map(valWrite3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
               //</>
                
                //<write to file:> 
                myFile2.print("<servo1>");
                myFile2.print(String(valWrite));
                myFile2.print("</servo1>");
            
                myFile2.print("<servo2>");
                myFile2.print(String(valWrite2));
                myFile2.print("</servo2>");
            
                myFile2.print("<servo3>");
                myFile2.print(String(valWrite3));
                myFile2.print("</servo3>");
            
                myFile2.println();
                //</>
                
                //<Serial message>
                Serial.println("done.");
                //</>
                
                //<Move servos to the pot values>
                servo1.write(valWrite);
                servo2.write(valWrite2);
                servo3.write(valWrite3);  
                //</>
                
                //<Serial message>
                Serial.print(valWrite);
                Serial.print("--");
                Serial.print(valWrite2);
                Serial.print("--");
                Serial.print(valWrite3);
                Serial.println();
                //</>

                //<Turn yellow led on>
                statusLedOn();
                //</>
                
                //<Wait time for each recording>
                delay(10);
                //</>
      
              }
        }
        else 
        {
          // <if the file didn't open, print an error:>
          
          //<Serial message>
          Serial.println("error opening test8.txt");
          //</>
          //<Error LED On>
          errorLedOn();
          //</>
        }
      }

void continusRecordingRead()
{
  // CONTINOUS RECORDING READ START

 //Servo
  servo1.attach(servoPin1);  
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  //<>

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile2 = SD.open("test8.txt", FILE_READ);

  if (myFile2) 
  {
    Serial.println("test8.txt:");

    // read from the file until there's nothing else in it:
    while (myFile2.available()) 
    {
      //<READ LINE BY LINE>
      String line = myFile2.readStringUntil('\n');
      
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
      delay(10);
      //<READ LINE BY LINE STOP>
    }
    // close the file:
  myFile2.close();
  servo1.detach();  
  servo2.detach();
  servo3.detach();
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
    myFile2.close();
    errorLedOn();
    delay(1000);
  }
}
