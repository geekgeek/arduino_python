
#include <SPI.h>
#include <SD.h>

File myFile;
//pot
int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer
int potpin3 = 2;  // analog pin used to connect the potentiometer
//pot

//SD Write
int valWrite;
int valWrite2;
int valWrite3;


void setup() {
  // put your setup code here, to run once:
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
sdWriteServoValue();
}

void loop() {
  // put your main code here, to run repeatedly:

}


void sdWriteServoValue()
{
   myFile = SD.open("test6.txt", FILE_WRITE);

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
    myFile.println();
    
    myFile.print("<servo1>");
    myFile.print(String(valWrite));
    myFile.print("</servo1>");

    myFile.print("<servo2>");
    myFile.print(String(valWrite2));
    myFile.print("</servo2>");

    myFile.print("<servo3>");
    myFile.print(String(valWrite3));
    myFile.print("</servo3>");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test2.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test6.txt");
  if (myFile) {
    Serial.println("test6.txt:");

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
