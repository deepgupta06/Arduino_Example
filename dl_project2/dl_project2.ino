#include <SD.h>              
#define SD_ChipSelectPin 8  
#include <TMRpcm.h>         
#include <SPI.h>
#define lm1 2
#define lm2 3
#define rm1 4
#define rm2 5
#define echopin 7
#define trigpin 6
int count=0;

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
   pinMode(A3, OUTPUT);
   
  tmrpcm.volume(1);
  tmrpcm.setVolume(5);
  
  
  

}

void loop() {
  float distance,duration;
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(100);
  digitalWrite(trigpin,LOW);
  duration= pulseIn(echopin, HIGH);
  distance= (duration/2)/29.1;
  
  Serial.flush();
  delay(500);
  delay(30);
  String t;
  while(Serial.available())
  {
    t +=(char)Serial.read();
  }
  if (t == "wake up")
  {
    blink();
     tmrpcm.volume(1);
  tmrpcm.setVolume(5);
    tmrpcm.play("ready.wav");
    count++;
    delay(2000);
  }
  else if (count>0 && t== "for")
  {
    forward();
  }
  else if (count >0 && distance>=1.5 && distance<=10)
  {
    stop();
     analogWrite(A0,255);
        tmrpcm.play("object.wav");
        delay(3000);
       
  }
   else if (count>0 && t =="backward")
   {
    backward();
   }
   else if (count>0 && t =="left")
   {
    left();
   }
   else if(count>0 && t =="right")
   {
    right();
   }
   else if(count>0 && t =="stop")
   {
    stop();
   }
     else if (count>0 &&  distance <=10 && t=="forward")
   {while(true)
   {
    forward();
    delay(3000);
    break;
   }
      }
           else if (count>0 &&  distance <=10 && t=="backward")
   {while(true)
   {
    backward();
    delay(3000);
    break;
   }
      }
           else if (count>0 &&  distance <=10 && t=="left")
   {while(true)
   {
    left();
    delay(3000);
    break;
   }
      }
           else if (count>0 &&  distance <=10 && t=="right")
   {while(true)
   {
    right();
    delay(3000);
    break;
   }
      }
 
  else if (t == "sleep")
  {
    blink();
  stop();
  count=0;
  
   
  }
  else
  {
    analogWrite(A0,0);
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
  analogWrite(A0, 255);
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  delay(300);
    analogWrite(A0, 0);
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  delay(300);
}
void backward()
{
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,HIGH);
  
}
void forward()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2,LOW);
  
}
void right()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,HIGH);
  delay(300);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,LOW);
}
void left()
{
   digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2,LOW);
  delay(300);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,LOW);
}
void stop()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2,LOW);
}

