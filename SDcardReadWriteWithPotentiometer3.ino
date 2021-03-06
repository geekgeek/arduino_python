/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

Write potentiometer value line for line when opening serial connection
 */

#include <SPI.h>
#include <SD.h>

File myFile;
//pot
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
//pot

void setup()
{
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test2.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    //pot
   val = analogRead(potpin);
   val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
   //pot 
    Serial.print("Writing to test2.txt...");
    myFile.println(val);
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test2.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test2.txt");
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
   val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
   Serial.print(val);
   Serial.println();
  delay(300);
//pot
  
}
