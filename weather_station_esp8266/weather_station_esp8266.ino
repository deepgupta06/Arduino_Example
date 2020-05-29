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

WiFiClient client;
char* servername ="api.openweathermap.org";
String result;

int  iterations = 1800;
String weatherDescription ="";
String weatherLocation = "";
float Temperature;
Adafruit_PCD8544 display = Adafruit_PCD8544(D5, D7, D6, D1, D2);

static const unsigned char PROGMEM thunderstrom[] =
{
0x00, 0xFF, 0xF0, 0x3F, 0x10, 0x0E, 0xC0, 0x00, 0x02, 0x00, 0x00, 0x07, 0x80, 0x00, 0x32, 0x80,
0x00, 0x1C, 0x7F, 0xF3, 0xE0, 0x1C, 0x7C, 0x7F, 0x08, 0x20, 0x41, 0x10, 0xC0, 0x82, 0x11, 0x01,
0x0C, 0x21, 0xF1, 0x10, 0x40, 0x0A, 0x1F, 0xF4, 0x14, 0x00, 0x0C, 0x2F, 0x41, 0x08, 0xC0, 0xC2,
0x09, 0x00, 0x8C, 0x12, 0x00, 0x90, 0x14, 0x01, 0x20, 0x28, 0x01, 0x40, 0x30, 0x02, 0x80, 0x40,
0x03, 0x00, 0xC0, 0x04, 0x00, 0x00, 0x0C, 0x00};

static const unsigned char PROGMEM clearsky[] =
{
0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x08, 0x00, 0x10, 0x04,
0x00, 0x20, 0x02, 0x3C, 0x40, 0x00, 0xE7, 0x00, 0x01, 0x81, 0x80, 0x01, 0x00, 0x80, 0x03, 0x00,
0xC0, 0x72, 0x00, 0x4E, 0x72, 0x00, 0x4E, 0x03, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x01, 0x81, 0x80,
0x00, 0xE7, 0x00, 0x02, 0x3C, 0x40, 0x04, 0x00, 0x20, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x00,
0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00};

static const unsigned char PROGMEM fewcloud[] =
{
0x00, 0x83, 0x04, 0x00, 0x40, 0x08, 0x00, 0x27, 0x90, 0x00, 0x18, 0x60, 0x00, 0x10, 0x20, 0x00,
0x20, 0x10, 0x01, 0xA0, 0x16, 0x01, 0xED, 0xD6, 0x0D, 0xBA, 0x30, 0x33, 0x00, 0x30, 0x40, 0x00,
0x08, 0x40, 0x00, 0x0C, 0x80, 0x00, 0x08, 0x00, 0x00, 0x04, 0x80, 0x00, 0x04, 0xC0, 0x00, 0x28,
0x80, 0x00, 0x30, 0xC0, 0x00, 0x20, 0x21, 0x03, 0xC0, 0x1F, 0x84, 0x00, 0x00, 0x78, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const unsigned char PROGMEM clouds[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x60, 0x03, 0x59, 0x90, 0x0C,
0x80, 0x0C, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x70, 0x00, 0x02, 0x40, 0x1B, 0x06, 0x4D, 0xE4,
0xA2, 0x72, 0x00, 0x52, 0x60, 0x00, 0x3C, 0x60, 0x00, 0x10, 0xF0, 0x00, 0x10, 0x80, 0x00, 0x10,
0xC0, 0x00, 0x10, 0x60, 0x00, 0xA0, 0x50, 0x00, 0xC0, 0x70, 0x00, 0x80, 0x30, 0x07, 0x00, 0x1F,
0x88, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00};

static const unsigned char PROGMEM lightrain[] =
{
0x00, 0x00, 0x00, 0x00, 0x27, 0x60, 0x03, 0xC8, 0x98, 0x04, 0x00, 0x04, 0x08, 0x00, 0x04, 0x38,
0x00, 0x04, 0x20, 0x00, 0x02, 0x18, 0x00, 0x34, 0x10, 0x00, 0x18, 0x1C, 0x00, 0x10, 0x06, 0x61,
0xE0, 0x03, 0xFE, 0x20, 0x04, 0x84, 0x40, 0x09, 0x08, 0x80, 0x10, 0x50, 0x00, 0x00, 0x81, 0x00,
0x25, 0x02, 0x00, 0x48, 0x24, 0x00, 0x90, 0x48, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const unsigned char PROGMEM heavyrain[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFC, 0x00, 0x1E, 0x82, 0x00, 0x20, 0x03, 0xF8, 0x40,
0x7F, 0x06, 0x60, 0xC0, 0x03, 0x33, 0x00, 0x03, 0x1D, 0x80, 0x02, 0x22, 0x80, 0x04, 0x44, 0x7C,
0x38, 0x80, 0x27, 0xD0, 0x12, 0x48, 0x20, 0x24, 0x92, 0x40, 0x49, 0x04, 0x80, 0x90, 0x49, 0x00,
0x04, 0x90, 0x00, 0x49, 0x24, 0x00, 0x90, 0x08, 0x00, 0x04, 0x90, 0x00, 0x49, 0x00, 0x00, 0x92,
0x40, 0x00, 0x24, 0x80, 0x00, 0x49, 0x00, 0x00};


void setup() {
  Serial.begin(9600);
  display.begin();
  
  display.setContrast(50);
  display.clearDisplay(); 
  
  
  display.setTextWrap(false);
   /*display.setTextColor(WHITE,BLACK);
      display.setTextSize(1);
   display.println("yobots");
   display.println("Prsents");
   display.println("Online weather station");
    display.println("station");
     display.println("Sponsored by");
     display.setTextColor(WHITE,BLACK);
     display.println("JLCPCB.com");*/
     String intro = "yobots Present Online weather station Sponsored by JLCPCB";
     textscroll(intro);
     
   
  
  display.display();
  WiFi.begin(ssid, password);
   
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("not connected");
    
  }
  
  Serial.println("connected");
  display.clearDisplay(); 
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {
  display.clearDisplay();
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
String text = location + "; " + description + "; " + timeS;
Serial.println(text);

/*display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(26,2);
  display.println(temperature);
    display.drawCircle(78,4,2,BLACK);
    display.setTextSize(1);
    display.setCursor(76,8);
  display.println("C");
  display.setTextSize(1);
  display.setCursor(26,18);
  //display.println(weather);
  display.println(windspeed+"m/s");
  //display.setCursor(26,26);
  //display.println(humidity+"%");*/

      int textWidth = text.length()*12+85;
    for(int i=0; i<textWidth; i+=1) 
    {
      display.clearDisplay();
      display.drawRect(0, 0, 84, 48, BLACK);
      display.fillRect(0, 30, 84, 48, BLACK);
      display.drawLine(28,0,28,30, BLACK);
      display.setTextColor(BLACK);
      display.setTextSize(1);
  display.setCursor(32,2);
  display.println(temperature);
    display.drawCircle(63,4,1,BLACK);
    display.setCursor(67,2);
    
    
  display.println("C");
  display.setTextSize(1);
  display.setCursor(32,11);
  //display.println(weather);
  display.println(windspeed+"m/s");
  display.setCursor(32,20);
  display.println(humidity+"%");
      drawicon(weatherID);
      for(int j=0; j<text.length(); j++) 
      {
        display.drawChar((j*12)+85-i,map(j,-100,100,20,40), text[j], WHITE, WHITE, 2);
      }

      display.display();
      delay(50);    
    
  }
  
  
display.display();
//delay(1000);
}



void iconclearsky()
{
  display.drawBitmap(1, 1,  clearsky, 24, 24, 1);
}

void iconthunderstrom()
{
  display.drawBitmap(1, 1,  thunderstrom, 24, 24, 1);
}

void iconfewclouds()
{
  display.drawBitmap(1, 1,  fewcloud, 24, 24, 1);
}

void iconclouds()
{
  display.drawBitmap(1, 1,  clouds, 24, 24, 1);
}

void iconlightrain()
{
  display.drawBitmap(1, 1,  lightrain, 24, 24, 1);
}

void iconheavyrain()
{
  display.drawBitmap(1, 1,  heavyrain, 24, 24, 1);
}

void drawicon(int i)
{
  switch(i)
  {
    case 800: iconclearsky(); break;
    case 801: iconfewclouds(); break;
    case 802: iconfewclouds(); break;
    case 803: iconclouds(); break;
    case 804: iconclouds(); break;

    case 200: iconthunderstrom(); break;
    case 201: iconthunderstrom(); break;
    case 202: iconthunderstrom(); break;
    case 210: iconthunderstrom(); break;
    case 211: iconthunderstrom(); break;
    case 212: iconthunderstrom(); break;
    case 221: iconthunderstrom(); break;
    case 230: iconthunderstrom(); break;
    case 231: iconthunderstrom(); break;
    case 232: iconthunderstrom(); break;

    case 300: iconlightrain(); break;
    case 301: iconlightrain(); break;
    case 302: iconlightrain(); break;
    case 310: iconlightrain(); break;
    case 311: iconlightrain(); break;
    case 312: iconlightrain(); break;
    case 313: iconlightrain(); break;
    case 314: iconlightrain(); break;
    case 321: iconlightrain(); break;
    
    case 500: iconlightrain(); break;
    case 501: iconlightrain(); break;
    case 502: iconlightrain(); break;
    case 503: iconlightrain(); break;
    case 504: iconlightrain(); break;
    case 511: iconlightrain(); break;
    case 520: iconlightrain(); break;
    case 521: iconlightrain(); break;
    case 522: iconheavyrain(); break;
    case 531: iconheavyrain(); break;

    default: break;     
  }
}

void textscroll(String text)
{
    int textWidth = text.length()*12+85;
    for(int i=0; i<textWidth; i+=1) 
    {
      display.clearDisplay();
      display.drawRect(0, 0, 84, 48, BLACK);
      display.fillRect(0, 0, 84, 48, BLACK);
      display.drawBitmap(1, 1,  thunderstrom, 24, 24, 1);
      for(int j=0; j<text.length(); j++) 
      {
        display.drawChar((j*12)+85-i,map(j,-100,100,20,20), text[j], WHITE, WHITE, 2);
      }

      display.display();
      delay(20);    
    
  }
  
}
