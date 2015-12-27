/*
  SD card read file
 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
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
  servo1.attach(9);  

  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test2.txt", FILE_READ);

  if (myFile) {
    Serial.println("test2.txt:");

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

void loop()
{
//pot
   val = analogRead(potpin); 
   Serial.print(val);
   
   Serial.print("\t");
   val = map(val, 0, 1023, 20, 160);     // scale it to use it with the servo (value between 0 and 180) 
   Serial.print(val);
   Serial.println();
   delay(10);

  //servo1.write(val);
//pot

}
