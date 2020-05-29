#include <Servo.h>
Servo servo_0;
Servo servo_1;
Servo servo_2;
Servo servo_3;
int pos[18]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,179}  ;
void setup() 
{
   servo_0.attach(D5); // attaches the servo
  servo_1.attach(D6);
  servo_2.attach(D7);
  servo_3.attach(D8);
  Serial.begin(115200); 
  
  // put your setup code here, to run once:

}

void loop() 
{
  Serial.println("Loop Start");
  for(int i=0;i<=18;i++)
  {
    servo_0.write(pos[i]);
    Serial.println(i);
    delay(250);
  }
}
