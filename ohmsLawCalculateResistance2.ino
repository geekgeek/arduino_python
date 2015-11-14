/*
http://www.ohmslawcalculator.com/ohms-law-calculator

https://www.sparkfun.com/products/9590

LED max current 20 ma ( 0,02 Amps)

Prints out the nescessary resistance values based on ohms law.
 */

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

// Resistance = Voltage / current

float voltage = 0.1;
float current = 0.02; //CAN CHANGE THIS VALUE

int counter = 0;
float pause = 10; // Can change the pause for each calculation

void loop() 
{

  while(voltage < 12) // counts until voltage = 12 volts
  { 
    
    counter = counter + 1;
    
    voltage = voltage + 0.1; // Can change the into steps for each calculation
    float resistance = voltage / current;
    
    Serial.print(counter);
    
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
