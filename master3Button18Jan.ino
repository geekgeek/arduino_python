//https://www.youtube.com/watch?v=XUuXq4J4u14
//http://www.electroschematics.com/8964/turn-on-led-button-arduino/

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
const int buttonPin = 8;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

const int buttonPin2 = 7;     // the number of the pushbutton pin
int buttonState2 = 0;         // variable for reading the pushbutton status

const int buttonPin3 = 2;     // the number of the pushbutton pin
int buttonState3 = 0;         // variable for reading the pushbutton status

//STATEBUTTON:
int LED = 2;
int stateLED = LOW;
int previous = LOW;
long time = 0;
long debounce = 200;

void setup() 
{

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
    // Open serial
  Serial.begin(9600);
  
  //SD CARD INITIALIZING
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) 
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
  servo1.attach(9);  
  servo2.attach(3);
  servo3.attach(6);
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
     
      //<Servo>
      val = map(convLine,0,180,20,160);
      val2 = map(convLine2,0,180,20,160);
      val3 = map(convLine3,0,180,20,160);
      Serial.print(convLine);
      Serial.print("--");
      Serial.print(val);
      Serial.print("--");
      Serial.print("--");
      Serial.print(convLine2);
      Serial.print("--");
      Serial.print(val2);
      Serial.print("--");
      Serial.print("--");
      Serial.print(convLine3);
      Serial.print("--");
      Serial.print(val3);
      
      servo1.write(val);
      servo2.write(val2);
      servo3.write(val3);

      Serial.println();
      //<>
      
      delay(200);
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
  }
}

void sdWriteServoValue()
{
   myFile = SD.open("test7.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
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
servo1.attach(9);  
servo2.attach(3);
servo3.attach(6);
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
        }
}

void moveServosWithPotOff()
{
  servo1.detach();  
  servo2.detach();
  servo3.detach();
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
  } else {
    Serial.println("test7.txt doesn't exist.");
  }
}
