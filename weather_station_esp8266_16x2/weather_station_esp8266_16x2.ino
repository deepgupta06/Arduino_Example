#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);
const char* ssid     = "Hi3d3n";
const char* password = "janinaja";
String CityID = "1275004"; 
String APIKEY = "1ba3812e01a8f615d2237c7279c98dd5";
#define ALTITUDE 9.14 

WiFiClient client;
char* servername ="api.openweathermap.org";
String result;

/*int  iterations = 1800;
String weatherDescription ="";
String weatherLocation = "";
float Temperature;
*/




void setup() {
  Serial.begin(9600);
  lcd.begin();
  WiFi.begin(ssid, password);
  lcd.clear();
  lcd.print("Connecting Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    for(int i=0; i<=14; i++)
    {
    lcd.setCursor(i,1);
    lcd.println(".");
    delay(200);
    }
    
  }
  
  Serial.println("connected");
  lcd.clear();
  lcd.print("Connected"); 
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {
   String result ="";
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(servername, httpPort)) {
        return;
    }
      // We now create a URI for the request
    String url = "/data/2.5/forecast?id="+CityID+"&units=metric&cnt=1&APPID="+APIKEY;
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

String temperature = root["list"]["main"]["temp"];
String weather = root["list"]["weather"]["main"];
String description = root["list"]["weather"]["description"];
String idString = root["list"]["weather"]["id"];
String timeS = root["list"]["dt_txt"];
String windspeed = root["list"]["wind"]["speed"];
String humidity= root["list"]["main"]["humidity"];
int weatherID = idString.toInt();

Serial.print(weatherID);
Serial.print(location);
Serial.print(temperature);
Serial.print(weather);
Serial.print(description);
Serial.println(timeS);
Serial.println(windspeed);
Serial.println(result);
String text = location + "; " + description  ;
Serial.println(text);
printtolcd(location, temperature, weather, windspeed, humidity);
}

void printtolcd(String lcdcity, String lcdtemp, String lcdweather,String lcdwindspeed, String lcdhumidity)
{
  lcd.clear();
  lcd.print(lcdcity);
  lcd.print("  ");
  lcd.print(lcdweather);
  lcd.setCursor(0,1);
  lcd.print(lcdtemp);
  lcd.print("C");
  delay(5000);
  lcd.clear();
  lcd.print(lcdcity);
  lcd.print("  ");
  lcd.print(lcdweather);
  lcd.setCursor(0,1);
  lcd.print("H=");
  lcd.print(lcdhumidity);
  lcd.print("%");
  lcd.print("  ");
  lcd.print("W=");
  lcd.print(lcdwindspeed);
  lcd.print("m/s");
  delay(5000);
}



