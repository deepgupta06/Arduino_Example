#include <DS3231.h>

#include <Wire.h>



DS3231  rtc(SDA, SCL);

Time  t;

#define buz 13

int Hor;

int Min;

int Sec;




void setup()

{  

  Wire.begin();

  rtc.begin();

  Serial.begin(9600);

  pinMode(buz, OUTPUT);

  

  // The following lines can be uncommented to set the date and time

  rtc.setDOW(TUESDAY);     // Set Day-of-Week to SUNDAY

  rtc.setTime(00, 56, 00);     // Set the time to 12:00:00 (24hr format)

  rtc.setDate(20, 03, 2019);   // Set the date to January 1st, 2014

  delay(2000);

}




void loop()

{
  t = rtc.getTime();

  Hor = t.hour;

  Min = t.min;

  Sec = t.sec;
  Serial.print(Hor);
  Serial.print(":");
  Serial.print(Min);
  Serial.print(":");
  Serial.println(Sec);
  

  

 



 if( Hor == 01 &&  (Min == 13 || Min == 14 || Min == 15 )) //Comparing the current time with the Alarm time

{
  Serial.print("alarm");
Buzzer();
} 

 delay(200); 

}




void Buzzer()

{

digitalWrite(buz,HIGH);

delay(500);

digitalWrite(buz, LOW);

delay(500);

}
