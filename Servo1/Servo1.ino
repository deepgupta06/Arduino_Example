#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "RemoteXY" 
#define REMOTEXY_WIFI_PASSWORD "12345678" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,2,0,0,0,12,0,8,13,0,
  5,0,33,18,30,30,2,26,31 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#include <Servo.h>
Servo myservo;
int lastpos=0;
void setup()  
{ 
  RemoteXY_Init ();  
  myservo.attach(D5);
   Serial.begin(9600);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   int val=map(RemoteXY.joystick_1_y,-100,100,0,180);
   Serial.print("Val=");
   Serial.print(val);
   if(val>lastpos)
   {
    for(int i = lastpos;i<=val;i++)
      {
        myservo.write(i);
        delay(5);
      }
   }
 if(val<lastpos)
 {
  for(int i =lastpos;i>=val;i--)
  {
    myservo.write(i);
    delay(5);
  }
 }
 lastpos=val-1;
 Serial.print("lastpos=");
   Serial.println(lastpos);
   //delay(100);


}
