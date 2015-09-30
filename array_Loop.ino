// Demonstrates how to create an array loop.

int myArray[]; //Array variable

void setup()
{

}

void loop()
{

//Start Array loop
for(x = 0; x < 85; x += 1) //loop runs from 0 and < 85
{
	myArray[x] = analogRead(0) // read value from sensor
	delay(1000) // pause 1 second
}
//End Array loop

}
