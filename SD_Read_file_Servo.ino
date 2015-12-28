/*
  SD card read file and transfer data to servo

 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4


//Servo attached to pin 9
 */

#include <SPI.h>
#include <SD.h>

#include <Servo.h>
Servo servo1;

File myFile;
//pot
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
//pot

void setup()
{
  //Servo
  servo1.attach(9);  
  //<>
  
  // Open serial
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) 
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test2.txt", FILE_READ);

  if (myFile) 
  {
    Serial.println("test2.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) 
    {
      //<READ LINE BY LINE>
      String line = myFile.readStringUntil('\n');
      int convLine = line.toInt();
      
      Serial.print(convLine);
      //<Servo>
      val = map(convLine,0,180,20,160);
      Serial.print("--");
      Serial.print(val);
      Serial.println();
      servo1.write(val);
      //<>
      
      delay(200);
      //<READ LINE BY LINE STOP>
    }
    // close the file:
    myFile.close();
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}


void loop()
{

  

}
