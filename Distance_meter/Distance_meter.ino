#define echoPin 6
#define trigPin 7

#include <Servo.h>
Servo myservo;
void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
myservo.attach(9);
  myservo.write(180);
}

void loop() {
  float distance, duration;
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(100);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (((duration/2)/29.1/100)*39.37);
int angle = map( distance, 0,12,180,0);
myservo.write(angle);

/*Serial.print("Distance is");                //////////////////////////////
Serial.print(distance);                       //////Use this to check///////
Serial.println("in");                         //////every thing is ok///////
Serial.flush();                               //////////////////////////////
delay(1000);*/ 

}
