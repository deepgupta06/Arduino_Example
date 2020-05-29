#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#define LATCH D2
#define CLK D3
#define DATA D1



const char* ssid     = "xxx";       
const char* password = "yyy";   
String apiKey = "api";            // https://console.developers.google.com
String channelId = "UC4d1tybdUQJN3HfaNX9tiuw";

const char *host = "www.googleapis.com";
long subscribers,subscribersBefore = 0;
long int sub;
byte digit[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void setup()  
{
  Serial.begin(9600);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);  
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
  }
  
  Serial.println("connected");
  delay(1000);
}

void loop() 
{
  sub = getSubscribers();
  digitPrint(ExtractDigit(sub, 6), ExtractDigit(sub, 5), ExtractDigit(sub, 4), ExtractDigit(sub, 3), ExtractDigit(sub, 2), ExtractDigit(sub, 1));     
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



int ExtractDigit(long int V, int P)
{
  return int(V/(pow(10,P-1))) % 10; 
}

void digitPrint(int firstdigit, int seconddigit, int thirddigit, int fourthdigit, int fivethdigit, int sixthdigit)  
{
   digitalWrite(LATCH, LOW);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[firstdigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[seconddigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[thirddigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[fourthdigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[fivethdigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[sixthdigit]);
   digitalWrite(LATCH, HIGH);
  
}



