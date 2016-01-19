//led digital input pin
const int statusLed = 10;

void setup() 
{
pinMode(statusLed, OUTPUT);
}

void loop() 
{


}

void statusLedOn()
{
digitalWrite(statusLed,HIGH);
}

void statusLedOff()
{
digitalWrite(statusLed,LOW);
}
