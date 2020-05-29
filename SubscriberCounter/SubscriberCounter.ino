

   //////////////////////////////////////////////
  //   20x4 Subscriber Counter for YouTube    //
 //                                          //
//           http://www.educ8s.tv           //
/////////////////////////////////////////////

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>



const char* ssid     = "Hi3d3n";       // SSID of local network
const char* password = "janinaja";   // Password on network
String apiKey = "AIzaSyAhJFs3z2cZM5zXs04oNcDOCmKfllLXyh8";            // YouTube Data API v3 key generated here: https://console.developers.google.com
String channelId = "UC4d1tybdUQJN3HfaNX9tiuw";   // YouTube channel id

const char *host = "www.googleapis.com";
long subscribers,subscribersBefore = 0;

  // Set the LCD I2C address

void setup()  
{
  Serial.begin(9600);


  
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
  }
  
  Serial.println("connected");
  delay(1000);
}

void loop() 
{
  int length;
  String subscribersString = String(getSubscribers());
  int subscribersString1 = int(getSubscribers());
  Serial.print(subscribersString);
  Serial.print("______");
  Serial.print(subscribersString1);
  Serial.println(subscribersString.length());
  delay(30000);
}




int getSubscribers()
{
  WiFiClientSecure client;
  Serial.print("connecting to "); Serial.println(host);
  if (!client.connect(host, 443)) {
    Serial.println("connection failed");
    return -1;
  }
  String cmd = String("GET /youtube/v3/channels?part=statistics&id=") + channelId + "&key=" + apiKey+ " HTTP/1.1\r\n" +
                "Host: " + host + "\r\nUser-Agent: ESP8266/1.1\r\nConnection: close\r\n\r\n";
  client.print(cmd);

  int repeatCounter = 10;
  while (!client.available() && repeatCounter--) {
    delay(500);
  }
  String line,buf="";
  int startJson=0;
  
  while (client.connected() && client.available()) {
    line = client.readStringUntil('\n');
    if(line[0]=='{') startJson=1;
    if(startJson) 
    {
      for(int i=0;i<line.length();i++)
        if(line[i]=='[' || line[i]==']') line[i]=' ';
      buf+=line+"\n";
    }
  }
  client.stop();

  DynamicJsonBuffer jsonBuf;
  JsonObject &root = jsonBuf.parseObject(buf);
  if (!root.success()) {
    Serial.println("parseObject() failed");
    delay(10);
    return -1;
  }
  
  subscribers = root["items"]["statistics"]["subscriberCount"];
  Serial.println(subscribers);
  return subscribers;
}



