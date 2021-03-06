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

void setup()
{
  //Servo
  servo1.attach(9);  
  servo2.attach(3);
  servo3.attach(6);
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

      Serial.println(); 0
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


void servoindexxoff()
{
  /*
  //SECOND SERVO
  Serial.println("TEST INDEXOFF");
  part1 = servodata.substring(servodata.indexOf(" "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);

 
  Serial.println("TEST INDEXOFF");
  part1 = servodata2.substring(servodata2.indexOf(" "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);


  Serial.println("TEST INDEXOFF");
  part1 = servodata3.substring(servodata3.indexOf(" "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  */
}

void servoEndsWith()
{
  /*
  //FIRST SERVO
  Serial.println("TEST ENDSWITH");
  part1 = servodata.substring(servodata.endsWith(" "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);

    Serial.println("TEST ENDSWITH");
  part1 = servodata2.substring(servodata2.endsWith(" "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);

    Serial.println("TEST ENDSWITH");
  part1 = servodata3.substring(servodata3.endsWith(" "));
  Serial.println(part1);
  //convert to int
  servoValue = part1.toInt();
  Serial.print("integer value: ");
  Serial.println(servoValue);
  */
}
