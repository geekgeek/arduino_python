//LED & KEY Button led board
//https://www.youtube.com/watch?v=KxfhVqne1Qs

// 0x38 = L 
// 0x39 = C
// 0x40 = -
// 0x48 = =

const int stb = 8;
const int clk = 9;
const int dio = 10;

void setup() {
  pinMode(stb,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dio,OUTPUT);

  digitalWrite(stb,LOW);
  shiftOut(dio, clk, LSBFIRST, 0x8F); //Turn on display
  //shiftOut(dio, clk, LSBFIRST, 0xFF); // Turn on all
  shiftOut(dio, clk, LSBFIRST, 0x38); 
  //shiftOut(dio, clk, LSBFIRST, 0x80);// Turn off display
  digitalWrite(stb,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
