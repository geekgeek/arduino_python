
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "ssid";
const char* password = "password";
 
void setup () 
{
   pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
   pinMode(13, OUTPUT); //breadboard
   
   Serial.begin(115200);
   
   WiFi.begin(ssid, password);
 
   while (WiFi.status() != WL_CONNECTED) 
   {
     delay(1000);
     Serial.print("Connecting..");
   }
   
   blinking(4);

}


void loop() 
{
 
mainApp();
 
}


/**
 * Main app
 * 
 * 
 * */
void mainApp()
{ 
    String theMessage =  gotowebsite("website.com");
     
    if(theMessage == "update")
    {
      //action A
      blinking(7);
      Serial.print("Found update. Updating ..............");
      gotowebsite("http://website.com"); //reset update message
      Serial.print("Update complete");
      delay(3000);
    }
    else
    {
      //action B
      Serial.print("NO update");
    }

  // print out the value you read:
  Serial.print("_website checked");
  Serial.println("");
  delay(5000);        // delay in between reads for stability
  
}
/* go to website
 * @param char theWebsite
 * @return String websitedata
 */
String gotowebsite(char theWebsite[])
{
    String getWebsiteData = "";
    if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient

    http.begin(theWebsite);  //Specify request destination
    int httpCode = http.GET(); //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
      
      getWebsiteData = payload;
    }
 
    http.end();   //Close connection
 
  }

  return getWebsiteData;
}

/*
 * Repeat blinking
 * @param int blinkRepeatTimes
 */
void blinking(int blinkRepeatTimes)
{
   int waitTime = 100;
   for (int i=0; i < blinkRepeatTimes; i++)
   {
     digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
     delay(waitTime);     
     digitalWrite(LED_BUILTIN, LOW); 
     delay(waitTime);                      // Wait for a second
   } 
}
