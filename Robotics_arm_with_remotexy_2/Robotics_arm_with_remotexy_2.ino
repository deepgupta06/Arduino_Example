#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 
#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;


// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "RemoteXY" 
#define REMOTEXY_WIFI_PASSWORD "12345678" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,5,0,0,0,29,0,8,13,0,
  5,0,1,13,40,40,2,26,31,5,
  0,56,13,43,43,2,26,31,4,0,
  44,4,9,57,2,26 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 
  int8_t joystick_2_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_2_y; // =-100..100 y-coordinate joystick position 
  int8_t slider_1; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 



void setup()  
{ 
  RemoteXY_Init ();  
    myservo1.attach(D5);
  myservo2.attach(D6);
  myservo3.attach(D7);
  myservo4.attach(D8);
   
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   int pos1,pos2,pos3,pos4;
  pos1 = map(RemoteXY.joystick_1_x,-100,100,1,180);
  myservo1.write(pos1);
  pos2 = map(RemoteXY.joystick_2_x,-100,100,1,180);
  myservo2.write(pos2);  
  pos3 = map(RemoteXY.joystick_1_y,-100,100,1,180);
  myservo3.write(pos3);  
  pos4 = map(RemoteXY.slider_1,1,100,1,180);
  myservo4.write(pos4);
   
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
