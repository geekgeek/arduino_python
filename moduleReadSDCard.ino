#include <SD.h>
#include <SPI.h>

File myFile;

void setup() {
  // put your setup code here, to run once:
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
  
  readSdCard();
}

void loop() {
  // put your main code here, to run repeatedly:

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
