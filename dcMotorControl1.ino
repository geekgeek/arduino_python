/*
  Control DC motor with l293d
  http://www.ti.com/lit/ds/symlink/l293.pdf
  https://www.youtube.com/watch?v=4mJrTe6fBVw

  pin 11 = pin 1 / 1,2EN
  pin 12 = pin 7 / 2A
  pin 13 = pin 2 / 1 A

  pin 11 high = chip enabled

  motor goes one way = {pin 12 = low && pin 13 = high}
  motor goes one other way = {pin 12 = high && pin 13 = low} 
 */


// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin 13 as an output.
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(11,HIGH);

}

// the loop function runs over and over again forever
void loop() 
{

  delay(3000);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(3000);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH );
  
}
