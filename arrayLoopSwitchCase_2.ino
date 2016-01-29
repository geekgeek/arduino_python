// How to loop through an array with a switch case scenario
// The loop goes on forewer
 
int pos = 0;    // variable to store the servo position 
int arrValues[] = {20, 30, 40, 50};
int arrX = 0;

int var1 = 0;

void setup() 
{ 
  Serial.begin(9600);
} 
 
void loop() 
{
 
    
   switch (arrX) 
   {
      case 0:
        Serial.println("start Array value 1");
        delay(1000);
        button1();        
        break;
      case 1:
        Serial.println("start Array value 2");
        delay(1000);
        button1();        
        break;
      case 2:
        Serial.println("start Array value 3");
        delay(1000);
        button1();      
        break;
       case 3:
        Serial.println("start Array value 4");
        delay(1000);
        button1();    
        break;
      default:
        Serial.println("finished looping");
        delay(1000);
        arrX = -1; // When the looping is finished the variable is reset
        }
   arrX = arrX +1;

} 


void button1()
{
      for(pos = 0; pos <= arrValues[arrX]; pos += 1) // goes from 0 degrees to 180 degrees 
            {                                  // in steps of 1 degree 
              Serial.println(pos);              // tell servo to go to position in variable 'pos' 
              delay(50);                       // waits 15ms for the servo to reach the position 
            } 
}
