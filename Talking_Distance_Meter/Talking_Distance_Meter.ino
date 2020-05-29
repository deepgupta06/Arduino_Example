/*
 
♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣
♣♣♣♣♣♣♣♣♣♣♣Talking Distance meter ♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣
♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣

This code is in the public domain, enjoy!

If you want to help me with my all future projects please 
support me by subscribing my channel https://www.youtube.com/c/yobots

And for more project go to my youtube channel

*/


#include <SoftwareSerial.h> 

 
SoftwareSerial mySerial(11, 12); // RX, TX 



#define trigPin 6
#define echoPin 7


void setup() {

Serial.begin(9600);
mySerial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
  float distance, duration;
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(100);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= ((duration/2)/29.1/100)*39.37;
Serial.print("Distance is");
mySerial.print("Distance is");
Serial.print(distance);
mySerial.print(distance);
Serial.println("in");
mySerial.println("in");
Serial.flush();
delay(3000);

}
