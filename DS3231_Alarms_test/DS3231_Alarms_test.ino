
// CONNECTIONS:
// DS3231 SDA --> SDA
// DS3231 SCL --> SCL
// DS3231 VCC --> 3.3v or 5v
// DS3231 GND --> GND
// SQW --->  (Pin19) Don't forget to pullup (4.7k to 10k to VCC)

/* for software wire use below
#include <SoftwareWire.h>  // must be included here so that Arduino library object file references work
#include <RtcDS3231.h>

SoftwareWire myWire(SDA, SCL);
RtcDS3231<SoftwareWire> Rtc(myWire);
 for software wire use above */

/* for normal hardware wire use below */
#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS3231.h>
RtcDS3231<TwoWire> Rtc(Wire);

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
int m=al.Minute();
int s= al.Second();
Serial.print(h);
Serial.print(":");
Serial.print(m);
Serial.print(":");
Serial.println(s);
if(h== 00 && (m==41 || m == 42))
{
 buz();  
}
    
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
