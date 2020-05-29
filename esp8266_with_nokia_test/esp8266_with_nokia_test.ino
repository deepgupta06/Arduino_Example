#include <SPI.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "Hi3d3n"
#define WLAN_PASS       "janinaja"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883               
#define AIO_USERNAME    "yobots"
#define AIO_KEY         "83a80786ecc642919bcff59eb15548c2"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe covid_19 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/covid-19");
void MQTT_connect();
Adafruit_PCD8544 display = Adafruit_PCD8544(D5, D7, D6, D1, D2);

String intro = "COVID-19";
String country1[9],country2[9],country3[9],country4[9],country5[9],country6[9],country7[9],country8[9],country9[9],country10[9],country11[9];

void setup() 
{
  Serial.begin(9600);
  display.begin();
  display.setContrast(50);
  display.clearDisplay();
  display.setTextWrap(false);
  display.display();
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());
  mqtt.subscribe(&covid_19);

}

uint32_t x=0;

void loop() 
{
  String country_data;
  MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) 
  {
    if (subscription == &covid_19) 
    {
      country_data = ((char *)covid_19.lastread);
      Serial.println(a);
      Serial.println((char *)covid_19.lastread);
      int underscore_position[9];
      underscore_position[0]=0;
      int underscore = 0;
      
      for (int i=1; i<=8; i++)
      {
        underscore_position[i] = country_data.indexOf("_", underscore+1)+1;
        underscore = underscore_position[i];
        Serial.println(underscore_position[i]);
      }
      for (int i=0; i<=8; i++)
      {
        data[i] = country_data.substring(underscore_position[i],underscore_position[i+1]-1);
        Serial.println(data[i]);
      }
      
    }
  display.clearDisplay();
  display.drawRect(0, 0, 84, 48, BLACK);
  display.drawLine(38,0,38,48, BLACK);
  display.drawLine(0,10,84,10, BLACK);
  display.drawLine(0,20,84,20, BLACK);
  display.drawLine(0,30,84,30, BLACK);
  display.drawLine(0,39,84,39, BLACK); 
  display.setTextSize(1);
  display.setCursor(42,2);
  display.println("Global");
  display.setCursor(42,12);
  display.println("9999999");
  display.setCursor(2,12);
  display.println("Total");
  display.setCursor(2,22);
  display.println("Active");
  display.setCursor(2,32);
  display.println("Rcvrd");
  display.setCursor(2,41);
  display.println("Death");
  display.display();
  }

}

void textscroll(String text)
{
  int textWidth = text.length()*17+90;
  for(int i=0; i<textWidth; i+=1) 
  {
    display.clearDisplay();
    display.drawRect(0, 0, 84, 48, BLACK);
    display.fillRect(0, 0, 84, 48, BLACK);
    for(int j=0; j<text.length(); j++) 
    {
      display.drawChar((j*17)+90-i,map(j,-100,100,20,20), text[j], WHITE, WHITE, 3);
    }
    display.display();
    delay(20);    
  }  
}

void MQTT_connect() 
{
  int8_t ret;
  if (mqtt.connected()) 
  {
    return;
  }
  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) 
  { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");

}
