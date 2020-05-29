#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "hieden" 
#define REMOTEXY_WIFI_PASSWORD "janinaja" 
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com" 
#define REMOTEXY_CLOUD_PORT 6376 
#define REMOTEXY_CLOUD_TOKEN "00688827a81d88cb86e4341c5dc06a23" 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,1,0,11,0,42,0,8,13,0,
  1,0,36,15,24,24,2,31,79,0,
  129,0,4,6,16,6,17,84,105,109,
  101,0,129,0,22,6,18,6,17,0,
  67,4,21,7,20,5,2,26,11 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t button_1; // =1 if button pressed, else =0 

    // output variable
  char time1[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop)  
#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS3231.h>
RtcDS3231<TwoWire> Rtc(Wire);
#define PIN_BUTTON_1 D3

/* for normal hardware wire use above */


// Interrupt Pin Lookup Table
// (copied from Arduino Docs)
//
// CAUTION:  The interrupts are Arduino numbers NOT Atmel numbers
//   and may not match (example, Mega2560 int.4 is actually Atmel Int2)
//   this is only an issue if you plan to use the lower level interupt features
//
// Board           int.0    int.1   int.2   int.3   int.4   int.5
// ---------------------------------------------------------------
// Uno, Ethernet    2       3
// Mega2560         2       3       21      20     [19]      18 
// Leonardo         3       2       0       1       7






void setup () 
{
  
    Serial.begin(57600);
    pinMode(D3, OUTPUT); 
    pinMode(D4, OUTPUT);

    // set the interupt pin to input mode
  

    //--------RTC SETUP ------------
    // if you are using ESP-01 then uncomment the line below to reset the pins to
    // the available pins for SDA, SCL
    // Wire.begin(0, 2); // due to limited pins, use pin 0 and 2 for SDA, SCL
    
    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

    if (!Rtc.IsDateTimeValid()) 
    {
        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    
     

    // Alarm 1 set to trigger every day when 
    // the hours, minutes, and seconds match
     RemoteXY_Init ();  
     delay(5000);
   
}

void loop () 
{
    if (!Rtc.IsDateTimeValid()) 
    {
        Serial.println("RTC lost confidence in the DateTime!");
    }

    RtcDateTime now = Rtc.GetDateTime();
RtcDateTime al =now;
Serial.println("-------------");
int h= al.Hour();
double h1=al.Minute();
int m=al.Minute();
int s= al.Second();
Serial.print(h);
Serial.print(":");
Serial.print(m);
Serial.print(":");
Serial.println(s);
char rxtime;
rxtime = char(h);
if(h== 06 && (m==30 || m == 45))
{
 buz();  
}
    RemoteXY_Handler (); 
   digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
dtostrf(h1,0,1,RemoteXY.time1);
    
}


void buz()
{
   digitalWrite(D4, HIGH);  
   digitalWrite(D3, HIGH);    
  delay(500);                      
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);     
  delay(500); 
  
}
