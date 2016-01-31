
// How to loop through 2 arrays
 
int pos = 0;    // variable to store the servo position 
int arrValues[] = {45, 90, 180};
int arrX = 0;

int var1 = 0;

//Array 2
int startVa[] = {10,120,40};
int startX = 0;
//</>

void setup() 
{ 
  Serial.begin(9600);
} 
 
void loop() 
{
  button10();
} 

void button10()
{
  // Goes from one array value to the next with increment of one
    while(arrValues[0] != startVa[0])
    {
      if(arrValues[0] < startVa[0])
      {
      arrValues[0] = arrValues[0] + 1;
      Serial.print(arrValues[0]);
      Serial.print("val1:::");
      delay(10);
      }
    
      else if(arrValues[0] > startVa[0])
      {
      arrValues[0] = arrValues[0] - 1;
      Serial.print(arrValues[0]);
      Serial.print("val1:::");
      delay(10);
      }

      if(arrValues[1] < startVa[1])
      {
      arrValues[1] = arrValues[1] + 1;
      Serial.print(arrValues[1]);
      Serial.print("val2:::");
      delay(10);
      }
    
      else if(arrValues[1] > startVa[1])
      {
      arrValues[1] = arrValues[1] - 1;
      Serial.print(arrValues[1]);
      Serial.print("val2:::");
      delay(10);
      }

      if(arrValues[2] < startVa[2])
      {
      arrValues[2] = arrValues[2] + 1;
      Serial.print(arrValues[2]);
      Serial.print("val3:::");
      delay(10);
      }
    
      else if(arrValues[2] > startVa[2])
      {
      arrValues[2] = arrValues[2] - 1;
      Serial.print(arrValues[2]);
      Serial.print("val3:::");
      delay(10);
      }
    Serial.println();
      
    }
}
