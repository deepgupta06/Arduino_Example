#define REMOTEXY_MODE__ESP8266WIFI_LIB
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "hieden" 
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
  uint8_t mode1; // =1 if switch ON and =0 if OFF 
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 
  int8_t joystick_2_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_2_y; // =-100..100 y-coordinate joystick position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop)
#include <Servo.h> 
Servo servo;
boolean mode_1=false,recordplay=false;
int val1=0,val=0;

void setup() {
  RemoteXY_Init ();
Serial.begin(9600);
servo.attach(D5);
RemoteXY.recordPlay=1;
  // put your setup code here, to run once:

}

void loop() 
{
  RemoteXY_Handler (); 
  if( RemoteXY.recordPlay==0 && RemoteXY.mode1==0)
  {
    manual1();
    RemoteXY_Handler (); 
  }

}

void manual1()
{
  Serial.println("Manual Mode Activeted");
  val=map(RemoteXY.joystick_1_x,-100,100,0,180);
  if(val1<val)
  {
  for(int i=val1;i<=val;i++)
  {
    Serial.println(i);
    servo.write(i);
    //delay(1);
    val1=map(RemoteXY.joystick_1_x,-100,100,1,180);
    
  }
  }
  else if(val1>val)
  {
    for(int i=val1;i>=val;i--)
  {
    Serial.println(i);
    servo.write(i);
    //delay(1);
    val1=map(RemoteXY.joystick_1_x,-100,100,1,180);
    
  } 
  }
   RemoteXY_Handler ();
}
