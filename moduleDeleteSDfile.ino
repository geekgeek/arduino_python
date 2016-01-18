void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void deleteSDFile()
{
  // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove("test7.txt");

  if (SD.exists("test7.txt")) {
    Serial.println("test7.txt exists.");
  } else {
    Serial.println("test7.txt doesn't exist.");
  }
}
