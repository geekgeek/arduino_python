
#include <SPI.h>
#include <SD.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

File myFile;
//pot
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
int val2;
int val3;
//pot

//regex
String part1;
String part2;
String part3;

//BUTTON
const int buttonPin = 8;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
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

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    sdReadServos();
    delay(100);
  }
  else {
   Serial.println("button is not pressed");
   delay(100);
   
  }
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
  myFile = SD.open("test5.txt", FILE_READ);

  if (myFile) 
  {
    Serial.println("test5.txt:");

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
