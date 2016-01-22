//SHIFT REGISTER
//http://staticjolt.com/shift-registers-arduino-tutorial/
//https://www.youtube.com/watch?v=bqfPZXEuyuc

int DS_pin = 8; //inputting register values with this pin / serial input binary information
int STCP_pin = 9; // clock pin
int SHCP_pin = 10;

void setup()
{
pinMode(DS_pin,OUTPUT);
pinMode(STCP_pin,OUTPUT);
pinMode(SHCP_pin,OUTPUT);

pin1Low();
pin3Low();

pin1High();
pin3High();
pin2High();
}

void loop()
{
pin2Low();
pin1Low();
pin3Low();
delay(1000);
pin1High();
pin3High();
pin2High();

}

void pin1High()
{
  digitalWrite(DS_pin, HIGH);
}

void pin1Low()
{
  digitalWrite(DS_pin, LOW);
}

void pin2High()
{
  digitalWrite(STCP_pin, HIGH);
}

void pin2Low()
{
  digitalWrite(STCP_pin, LOW);
}

void pin3High()
{
  digitalWrite(SHCP_pin, HIGH);
}

void pin3Low()
{
  digitalWrite(SHCP_pin, LOW);
}
