/*
 wemos d1 pins:
 https://github.com/esp8266/Arduino/blob/master/variants/d1_mini/pins_arduino.h#L49-L61

 static const uint8_t LED_BUILTIN = 2;
static const uint8_t BUILTIN_LED = 2;

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t RX   = 3;
static const uint8_t TX = 1;

*/

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  if(sensorValue < 400)
  {
    Serial.println("button pressed");
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  // print out the value you read:
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability
}
