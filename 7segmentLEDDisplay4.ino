// 4 digit 7 segment led display
//http://www.instructables.com/id/Arduino-4-digit-7-segment-display/
//http://arduino.fisch.lu/Uploads/arduino/circuit_TYC-365GWB.png
int aPin = 2;  //                     A
int bPin = 3;  //             ________
int cPin = 4;  //           |                   |
int dPin = 5;  //       F  |                   |  B
int ePin = 6;  //           |         G       |
int fPin = 7;  //            |________|
int gPin = 8;  //           |                   |
int GND1 = 9;  //        |                   |
int GND2 = 10; //   E |                   |   C
int GND3 = 11; //       |________|
int GND4 = 12; //       
int num;       //         D
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;
int timeDelay = 1;

//Button:
const int buttonPins[] = {A6,A7};
int buttonStates[] = {0,0};
//</>

//pot
const int potpin1 = 0; 
int potval1;

//</>

//####################################################
//####################################################
//####################################################
//SETUP
void setup()
{
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT); 
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  Serial.begin(9600);

pinMode(potpin1, INPUT);

pinMode(13, OUTPUT);
}

//####################################################
//####################################################
//####################################################
//LOOP


void loop()
{
clearGround();

// Detect variation in potvalue in time
potval1 = analogRead(potpin1);
potval1 = map(potval1, 0, 1023, 0, 1009);
delay(1);
int potNew = analogRead(potpin1);
potNew = map(potNew, 0, 1023, 0, 1009);

int sum = abs(potNew - potval1);

int i;
int z;

//do 100 times every time:
for (z = 0; z < 200; z++) 
      {
        pickTheNumber3(potval1);
      }
//</>

// Do Once if:
if(sum < 20)
{
  for (i = 0; i < 1; i++) 
  {
      Serial.print("potval: ");
      delay(max((potval1 - 200)/10,1));
      Serial.print(potval1);
      Serial.println();
    }
}

}
//########################################################################################################
//########################################################################################################
//########################################################################################################
//CUSTOM FUNCTIONS
void pickNumber(int x){
   switch(x){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
}

void clearLEDs()
{  
  digitalWrite(  2, LOW); // A
  digitalWrite(  3, LOW); // B
  digitalWrite(  4, LOW); // C
  digitalWrite(  5, LOW); // D
  digitalWrite(  6, LOW); // E
  digitalWrite(  7, LOW); // F
  digitalWrite(  8, LOW); // G
}

void one()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void two()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void three()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void four()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void five()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void six()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void seven()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void eight()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void nine()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void zero()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, LOW);
}

void clearGround()
{
  digitalWrite( GND1, HIGH);

  digitalWrite( GND2, HIGH);

  digitalWrite( GND3, HIGH);
 
  digitalWrite( GND4, HIGH);

}

void turnOnGround()
{
  digitalWrite( GND1, LOW);

  digitalWrite( GND2, LOW);

  digitalWrite( GND3, LOW);
 
  digitalWrite( GND4, LOW);

}
void pickTheNumber(int x, int y , int z, int q)
{
digitalWrite( GND1, LOW);
  switch(x){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND1, HIGH);
  
    digitalWrite( GND2, LOW);
    switch(y){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND3, LOW);
    switch(z){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
 delay(timeDelay);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND4, LOW);
       switch(q){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;

       delay(timeDelay);
  digitalWrite( GND4, HIGH);
   }

   

}


void pickTheNumber2(int x)
{
String numberString = String(x);
String word1 = numberString.substring(0,1);
String word2 = numberString.substring(1,2);
String word3 = numberString.substring(2,3);
String word4 = numberString.substring(3,4);

digitalWrite( GND1, LOW);
  switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND1, HIGH);
  
    digitalWrite( GND2, LOW);
    switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND3, LOW);
    switch(word3.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
 delay(timeDelay);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND4, LOW);
       switch(word4.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;

       delay(timeDelay);
  digitalWrite( GND4, HIGH);
   }

   

}


// Pick a number for the 4 digit 7 segment LED Display
void pickTheNumber3(int x)
{
String testText = String(x);
int lengthOfInt = testText.length();

String numberString = String(x);
String word1 = numberString.substring(0,1);
String word2 = numberString.substring(1,2);
String word3 = numberString.substring(2,3);
String word4 = numberString.substring(3,4);



if(lengthOfInt == 4)
{
  digitalWrite( GND1, LOW);
  switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND1, HIGH);
  
    digitalWrite( GND2, LOW);
    switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND3, LOW);
    switch(word3.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
 delay(timeDelay);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND4, LOW);
       switch(word4.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;

       delay(timeDelay);
  digitalWrite( GND4, HIGH);
   }
}

//######################################
//######################################
//######################################
//######################################
else if (lengthOfInt == 3) 
{
    digitalWrite( GND2, LOW);
    switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  delay(timeDelay);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND3, LOW);
    switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
 delay(timeDelay);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND4, LOW);
       switch(word3.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;

       delay(timeDelay);
  digitalWrite( GND4, HIGH);
   }
}

//####################################
//####################################
//####################################
//####################################
else if (lengthOfInt == 2) 
{  

  digitalWrite( GND3, LOW);
    switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
 delay(timeDelay);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND4, LOW);
       switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;

       delay(timeDelay);
  digitalWrite( GND4, HIGH);
   }
}
else if (lengthOfInt == 1) 
{  
  digitalWrite( GND4, LOW);
       switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;

       delay(timeDelay);
  digitalWrite( GND4, HIGH);
}

}
}



// Pick a number for the 4 digit 7 segment LED Display
void pickTheNumber4(int x)
{


String testText = String(x);
int lengthOfInt = testText.length();

String numberString = String(x);
String word1 = numberString.substring(0,1);
String word2 = numberString.substring(1,2);
String word3 = numberString.substring(2,3);
String word4 = numberString.substring(3,4);


int timeForWait = 1;
int calcTime = timeForWait / (timeDelay);
int i;  
  for (i = 0; i < calcTime; i++)  
  {

if (lengthOfInt == 1) 
{  
  delay(timeDelay);
  
  digitalWrite( GND4, LOW);
       switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break; 
  digitalWrite( GND4, HIGH);

  
}
}
//####################################
//####################################
//####################################
//####################################
else if (lengthOfInt == 2) 
{  
 delay(timeDelay);
 
  digitalWrite( GND3, LOW);
    switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  digitalWrite( GND3, HIGH);


  digitalWrite( GND4, LOW);
       switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
  digitalWrite( GND4, HIGH);

  
   }
}

//######################################
//######################################
//######################################
//######################################
else if (lengthOfInt == 3) 
{
  delay(timeDelay);
    digitalWrite( GND2, LOW);
    switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  digitalWrite( GND2, HIGH);


  digitalWrite( GND3, LOW);
    switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  digitalWrite( GND3, HIGH);


  digitalWrite( GND4, LOW);
       switch(word3.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
  digitalWrite( GND4, HIGH);

  
   }
}




else if(lengthOfInt == 4)
{
  delay(timeDelay);
  
  digitalWrite( GND1, LOW);
  switch(word1.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  digitalWrite( GND1, HIGH);

  
    digitalWrite( GND2, LOW);
    switch(word2.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
  digitalWrite( GND2, HIGH);


  digitalWrite( GND3, LOW);
    switch(word3.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
 digitalWrite( GND3, HIGH);


  digitalWrite( GND4, LOW);
       switch(word4.toInt()){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
  digitalWrite( GND4, HIGH);

  
   }
}
}

}

