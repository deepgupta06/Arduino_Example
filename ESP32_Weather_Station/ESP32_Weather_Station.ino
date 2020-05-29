


#include <SPI.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


const char* ssid     = "Hi3d3n";
const char* password = "janinaja";
String CityID = "1275004"; 
String APIKEY = "1ba3812e01a8f615d2237c7279c98dd5";
#define ALTITUDE 9.14 



float temperature = 0;
String humidity;
float pressure = 0;
int weatherID = 0;


WiFiClient client;
char* servername ="api.openweathermap.org";  // remote server we will connect to
String result;

int  iterations = 1800;
String weatherDescription ="";
String weatherLocation = "";
float Temperature;
Adafruit_PCD8544 display = Adafruit_PCD8544(D5, D7, D6, D1, D2);

void setup() 
{
   
  Serial.begin(9600);
  display.begin();
  
  display.setContrast(50);
  display.display();
   WiFi.begin(ssid, password);
   
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
  }
  
  Serial.println("connected");
  delay(1000);

  
}

void loop() {
   
 
   getWeatherData();
   delay(60000);

     


}


void getWeatherData() //client function to send/receive GET request data.
{
  String result ="";
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(servername, httpPort)) {
        return;
    }
      // We now create a URI for the request
    String url = "/data/2.5/forecast?id="+CityID+"&units=metric&cnt=1&APPID="+APIKEY;
   // String url="/data/2.5/forecast?q=Kolkata,IN&appid=1ba3812e01a8f615d2237c7279c98dd5";
       // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + servername + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 5000) {
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server
    while(client.available()) {
        result = client.readStringUntil('\r');
        
    }

result.replace('[', ' ');
result.replace(']', ' ');

char jsonArray [result.length()+1];
result.toCharArray(jsonArray,sizeof(jsonArray));
jsonArray[result.length() + 1] = '\0';

StaticJsonBuffer<1024> json_buf;
JsonObject &root = json_buf.parseObject(jsonArray);
if (!root.success())
{
  Serial.println("parseObject() failed");
}

String location = root["city"]["name"];
display.clearDisplay();
  
String temperature = root["list"]["main"]["temp"];
String weather = root["list"]["weather"]["main"];
String description = root["list"]["weather"]["description"];
String idString = root["list"]["weather"]["id"];
String timeS = root["list"]["dt_txt"];
String windspeed = root["list"]["wind"]["speed"];
String humidity= root["list"]["main"]["humidity"];
weatherID = idString.toInt();
Serial.print(weatherID);
Serial.print(location);
Serial.print(temperature);
Serial.print(weather);
Serial.print(description);
Serial.print(timeS);
Serial.print(humidity);
Serial.println(windspeed);
Serial.println(result);

display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(26,2);
  display.println(temperature);
    display.drawCircle(78,4,2,BLACK);
    display.setTextSize(1);
    display.setCursor(78,8);
  display.println("C");
  display.setTextSize(1);
  display.setCursor(26,18);
  //display.println(weather);
  display.println(windspeed+"m/s");
  display.setCursor(26,26);
  display.println(humidity+"%");
   //display.println(description);
  display.display();


}






