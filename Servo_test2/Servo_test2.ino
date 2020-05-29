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
long nextmove;
int movedelay=10;
int Step=1;
int targetpos=1,currentpos=0,newpos;
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
  Serial.print(targetpos);
  Serial.print(newpos);
  Serial.println(currentpos);
  if(millis()>=nextmove)
  {
    movejoint(); 
  }
   


}
void movejoint()
{
  targetpos=map(RemoteXY.joystick_1_y,-100,100,0,2400);
  newpos=currentpos+Step;
  if(currentpos<targetpos && newpos>targetpos)
  {
    newpos=targetpos;
  }
  if(currentpos>targetpos && newpos<targetpos)
  {
    newpos=targetpos;
  }
  myservo.writeMicroseconds(newpos);
  currentpos=newpos;
  nextmove=millis()+movedelay;
  
}
