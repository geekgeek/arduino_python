/*
http://www.ohmslawcalculator.com/ohms-law-calculator

LED max current 20 ma ( 0,02 Amps)

Prints out the nescessary resistance values based on ohms law.

Resistance = Voltage / current

DO an array loop

int sizeOfArray = sizeof(yourArray)/sizeof(int)
 */

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
//##############################
// GUI:
//###############################
float voltage = 0; //Start voltage
float current = 0.02; //CAN CHANGE THIS VALUE

int counter = 0; //Start counter
float pause = 10; // Can change the pause for each calculation

float maxVoltageMessurement = 12; //Can change value for max voltage measure

int voltageArray[] = {5,7,9,11,15,20,30,40}; // Array


int arraysize = sizeof(voltageArray)/sizeof(int); // Gets the size of the array

//##########################################################
//Start loop
//##########################################################

void loop() 
{
  
  for (int i = 0; i <= arraysize; i++) //counts number of array values
  {
    while(voltage < voltageArray[i]) // counts until voltage max inside array
    { 
      
      counter = counter + 1;
      
      voltage = voltage + 0.1; // Can change the into steps for each calculation
      float resistance = voltage / current;

      
      Serial.print(counter);
      Serial.print("\t");

      Serial.print(arraysize);
      Serial.print("\t");
      
      Serial.print("arrSteps:");
      Serial.print(i);
      Serial.print("\t");
      
      Serial.print("Current:");
      Serial.print(current);
      Serial.print("\t");
      Serial.print("Voltage:");
      Serial.print(voltage);
      Serial.print("\t");
      Serial.print("Resistance:");
      Serial.print(resistance);
      
      Serial.println();
      
      delay(pause);
      
    }
  }
}
