// scetch for getting input on a tip 120 darlington transistor
// Send volt value 1 - 255 to the serial

int incomingVal;
// Define which pin to be used to communicate with Base pin of TIP120 transistor
int TIP120pin = 5; //for this project, I pick Arduino's PMW pin 5


void setup()
{
Serial.begin(9600); 

pinMode(TIP120pin, OUTPUT); // Set pin for output to control TIP120 Base pin
analogWrite(TIP120pin, 0); // By changing values from 0 to 255 you can control motor speed
}


void loop()
{
    incomingVal = Serial.parseInt();
    Serial.println(incomingVal);
    if (incomingVal > 0)
    {
       analogWrite(TIP120pin, incomingVal);

    }
}
