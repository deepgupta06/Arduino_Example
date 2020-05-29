
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
  { 255,6,0,0,0,49,0,8,13,0,
  5,0,5,20,41,41,2,26,31,5,
  0,55,19,43,43,2,26,31,2,0,
  4,4,22,11,2,26,31,31,80,0,
  82,0,2,0,34,4,22,11,2,26,
  31,31,77,0,65,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 
  int8_t joystick_2_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_2_y; // =-100..100 y-coordinate joystick position 
  uint8_t record; // =1 if switch ON and =0 if OFF 
  uint8_t mode1; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

#include <Servo.h>

///////////////////////////////////////////////////////////
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
Servo servo3;  // create servo object to control a servo
Servo servo4;  // create servo object to control a servo



int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
int val3;    // variable to read the value from the analog pin
int val4;    // variable to read the value from the analog pin

 int last_pos1=0;
 int last_pos2=0;
 int last_pos3=0;
 int last_pos4=0;
///////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
int q1[240];
int q2[240];
int q3[240];
int q4[240];
///////////////////////////////////////////////////////////////
int cnt1=0;
int cnt2=0;
int cnt3=0;
int cnt4=0;
//////////////////////////////////////////////////////////////
int record_led=12;
int manual_led=13;
//////////////////////////////////////////////////////////////
void setup() {
   RemoteXY_Init ();  
  servo1.attach(D5);  // attaches the servo on pin 9 to the servo object
  servo2.attach(D6);  // attaches the servo on pin 9 to the servo object
  servo3.attach(D7);  // attaches the servo on pin 9 to the servo object
  servo4.attach(D8);  // attaches the servo on pin 9 to the servo object 
 
  
  Serial.begin(9600);
  array_ini();
}
// replace standard delay with busy wait

void loop() {
  RemoteXY_Handler (); 
  
  int value=RemoteXY.mode1;
  if(value==1){
      Serial.println("------------------------------------------------Record Mode On");
      int value1=RemoteXY.record;
      if(value1==1){
        Serial.println("----------------------------------------------Recording the Postion :");
       // digitalWrite(record_led,HIGH);
        record(1);
        record(2);
        record(3);   
        record(4);
        delay(50);
       // digitalWrite(record_led,LOW);
      }else if(value1==0){
        Serial.println("----------------------------------------------Playing Recorded Postions");
        
        play_record();
  
       
      }
  }else{
    RemoteXY_Handler (); 
      Serial.println("------------------------------------------------Manual Mode");
      //digitalWrite(manual_led,HIGH);
      val1 = RemoteXY.joystick_1_x;        
      val1 = map(val1, -100, 100, 0, 180);
      servo_write(1,last_pos1);
      servo_write(1,val1);
      val2 = RemoteXY.joystick_1_y;  
      val2 = map(val2, -100, 100, 0, 180);
      servo_write(2,last_pos2);
      servo_write(2,val2);
      val3 = RemoteXY.joystick_2_x;
      val3 = map(val3, -100, 100, 0, 180);
      servo_write(3,last_pos3);
      servo_write(3,val3);
      val4 = RemoteXY.joystick_2_y;
      val4 = map(val4, -100, 100, 0, 180);
      servo_write(4,last_pos4);
      servo_write(4,val4);                     
      last_pos1=val1;
      last_pos2=val2;
      last_pos3=val3;
      last_pos4=val4;
     // digitalWrite(manual_led,LOW);
      delay(15);                                              
  }
}

int analog_read(int pin){
  int value=analogRead(pin);
  //Serial.print("Analog Read [");
  //Serial.print(pin);
  //Serial.print("] :");
  //Serial.print(value);
  //Serial.println("");
  //Serial.println("....................");
  return value;
}
void servo_write(int x,int y){
  switch(x){    
    case 1:
    servo1.write(y); 
    break;
    
    case 2:
    servo2.write(y);
    break;
    
    case 3:
    servo3.write(y);
    break;
    
    case 4:
    servo4.write(y);
    break;
  }
      //Serial.print("Servo ");
      //Serial.print(x);
      //Serial.print(" postion :");
      //Serial.print(y);
      //Serial.println("");
}
void array_ini(){
   for(int i=0;i<240;i++){
    q1[i]=-1;
    q2[i]=-1;
    q3[i]=-1;
    q4[i]=-1;
  }  
}
void record(int x){
  switch(x){
    case 1:
        val1 = RemoteXY.joystick_1_x;            // reads the value of the potentiometer (value between 0 and 1023)
        val1 = map(val1, -100, 100, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
        servo1.write(val1);                  // sets the servo position according to the scaled value
        last_pos1=val1;
        q1[cnt1]=val1;
        cnt1++;
      Serial.print("Postion servo1 :");
        Serial.print(val1);
        Serial.println();         
    break;
    case 2:
        
        val2 = RemoteXY.joystick_1_y;            // reads the value of the potentiometer (value between 0 and 1023)
        val2 = map(val2, -100, 100, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    
        servo2.write(val2);                  // sets the servo position according to the scaled value
        last_pos2=val2;
        q2[cnt2]=val2;
        cnt2++;
        //Serial.print("Postion Servo2 :");
        //Serial.print(val2);
        //Serial.println();          
    break;
    case 3:
   
        val3 = RemoteXY.joystick_2_x;           // reads the value of the potentiometer (value between 0 and 1023)
        val3 = map(val3, -100, 100, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
        
        servo3.write(val3);                  // sets the servo position according to the scaled value
        last_pos3=val3;
        q3[cnt3]=val3;
        cnt3++;
        //Serial.print("Postion Servo3 :");
        //Serial.print(val3);
        //Serial.println();          
    break;
    case 4:
       
        val4 = RemoteXY.joystick_2_y;           // reads the value of the potentiometer (value between 0 and 1023)
        val4 = map(val4, -100, 100, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
       
        servo4.write(val4);                  // sets the servo position according to the scaled value
        last_pos4=val4;
        q4[cnt4]=val4;
        cnt4++;
        //Serial.print("Postion Servo4 :");
        //Serial.print(val4);
        //Serial.println();         
    break;
  }
}
void play_record(){
        int i=0;
        //Serial.print("Position:");
        while(i<cnt1){
         // digitalWrite(record_led,HIGH);
          if(q1[i]!=-1){      
            servo1.write(q1[i]);
            last_pos1=q1[i];
            //Serial.print("[S1 =>");
            //Serial.print(last_pos1);
            //Serial.print("]");
            //Serial.println("");
          }
          if(q2[i]!=-1){
            servo2.write(q2[i]);
            last_pos2=q1[i];
            //Serial.print("[S2 =>");
            //Serial.print(last_pos2);
            //Serial.print("]");
            //Serial.println("");
          }
          if(q3[i]!=-1){
            
            servo3.write(q3[i]);
            last_pos3=q3[i];
            //Serial.print("[S3 =>");
            //Serial.print(last_pos3);
            //.print("]");
            //Serial.println("");
             delay(15);
          }
          if(q4[i]!=-1){
            
            servo4.write(q4[i]);
            last_pos4=q4[i];
            //Serial.print("[S4 =>");
            //Serial.print(last_pos4);
            //Serial.print("]");
            //Serial.println("");
          }
          i++;
         //digitalWrite(record_led,LOW);
          //delay(15);
          Serial.print("end0");
          RemoteXY_Handler ();
          
          
        }
        Serial.print("end1");
}
