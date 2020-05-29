/* 
   -- New project -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.3 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.1.1 or later version; 
     - for iOS 1.2.1 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 

////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ESP8266WIFI_LIB
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "Hi3d3n" 
#define REMOTEXY_WIFI_PASSWORD "janinaja" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,6,0,0,0,49,0,8,211,0,
  2,0,5,4,22,11,2,26,31,31,
  80,0,82,0,2,0,68,4,22,11,
  2,26,31,31,82,0,77,0,5,0,
  6,22,36,36,2,26,31,5,0,55,
  22,37,37,2,26,31 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t recordPlay; // =1 if switch ON and =0 if OFF 
  uint8_t mode; // =1 if switch ON and =0 if OFF 
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 
  int8_t joystick_2_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_2_y; // =-100..100 y-coordinate joystick position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_RECORDPLAY D6


void setup()  
{ 
  RemoteXY_Init ();  
   
  pinMode (PIN_RECORDPLAY, OUTPUT);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
  digitalWrite(PIN_RECORDPLAY, (RemoteXY.recordPlay==0)?LOW:HIGH);
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
