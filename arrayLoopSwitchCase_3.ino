
// How to loop through 2 arrays with switch scenario
 
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
   switch (arrX) 
   {
      case 0:
      Serial.println("start Array value 0");
        delay(1000);
        button10();        
        break;
      case 1:
        Serial.println("start Array value 1");
        delay(1000);
        button10();        
        break;
      case 2:
        Serial.println("start Array value 2");
        delay(1000);
        button10();      
        break;
      default:
        Serial.println("finished looping");
        delay(1000);
        }
   arrX = arrX +1;
   startX = startX +1;
} 


void button1()
{
      for(pos = 0; pos <= arrValues[arrX]; pos += 1) // goes from 0 degrees to 180 degrees 
            {                                  // in steps of 1 degree 
              Serial.println(pos);              // tell servo to go to position in variable 'pos' 
              delay(50);                       // waits 15ms for the servo to reach the position 
            } 
}

void button10()
{
  // Goes from one array value to the next with increment of one
    while(arrValues[arrX] != startVa[startX])
    {
      if(arrValues[arrX] < startVa[startX])
      {
      arrValues[arrX] = arrValues[arrX] + 1;
      Serial.println(arrValues[arrX]);
      delay(100);
      }
    
      else if(arrValues[arrX] > startVa[startX])
      {
      arrValues[arrX] = arrValues[arrX] - 1;
      Serial.println(arrValues[arrX]);
      delay(100);
      }
    }
}
