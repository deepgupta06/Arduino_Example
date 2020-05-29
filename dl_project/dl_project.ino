
#include <SD.h>              
#define SD_ChipSelectPin 8  
#include <TMRpcm.h>         
#include <SPI.h>
#define lm1 2
#define lm2 3
#define rm1 4
#define rm2 5
#define echopin 6
#define trigpin 7

TMRpcm tmrpcm;  
unsigned long time = 0;
void setup() {
  if (!SD.begin(SD_ChipSelectPin)) { 
    Serial.println("SD fail");  
    return;
  }
   tmrpcm.speakerPin = 9;
   Serial.begin(9600);
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  tmrpcm.volume(1);
  tmrpcm.setVolume(5);
  
  

}

void loop()
{
  delay(30);
  String t;
  while(Serial.available())
  {
    t +=(char)Serial.read();
  }
  if(t =="wake up")
  {
    blink();
     tmrpcm.volume(1);
  tmrpcm.setVolume(5);
    tmrpcm.play("ready.wav");
    delay(2000);
    while(true)
    {
      float distance,duration;
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(100);
  digitalWrite(trigpin,LOW);
  duration= pulseIn(echopin, HIGH);
  distance= (duration/2)/29.1;
  Serial.flush();
  delay(500);
      String a;
      while(Serial.available());
      {
        a +=(char)Serial.read();
      }
      if(a =="forward")
      {
        digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,HIGH);
        delay(2000);
      }
      else if(a =="backward")
      {
        backward();
        
      }
      else if(a =="stop")
      {
        stop();
      }
      else if(a =="left")
      {
        left();
      }
      else if (a== "right")
      {
        right();
      }
      else if( distance <=10)
      {
        stop();
        tmrpcm.play("object.wav");
        delay(2000);
        analogWrite(A0,255);
      }
      else if (distance <=10 && a=="go forward")
      {
        tmrpcm.play("warning.wav");
        forward();
      }
      else if (distance <=10 && a=="backward")
      {
        backward();
       
      }
       else if (distance <=10 && a=="left")
      {
        left();
       
      }
      else if (distance <=10 && a=="right")
      {
        right();
       
      }
      else if(a == "sleep")
      {
        break;
      }
      else
      {
        analogWrite(A0,0);
      }
      
    }
    
    
  }
  else if (t == "forward")
  {
   forward();
 
  }
   
  
  
  
  

}


void blink()
{
  analogWrite(A0, 255);
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  delay(300);
    analogWrite(A0, 0);
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  delay(300);
}
void forward()
{
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,HIGH);
}
void backward()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2,LOW);
}
void left()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,HIGH);
  delay(700);
}
void right()
{
   digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2,LOW);
  delay(700);
}
void stop()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,LOW);
}

