#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "yobots" 
#define REMOTEXY_WIFI_PASSWORD "12345678" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,1,0,0,0,11,0,8,13,0,
  4,0,43,7,9,52,2,26 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t slider_1; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 
#include <Servo.h>

Servo myservo; 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 



void setup()  
{ 
  RemoteXY_Init ();  
  myservo.attach(D5);
   
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
  int val ;
  val=map(RemoteXY.slider_1,0,100,0,180);
  myservo.write(val);
   
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
