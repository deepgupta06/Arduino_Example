int state=LOW;
int lastState=LOW;
int count=0;
int remainder=0;
int lastPin=5;
void setup(){
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7,OUTPUT);
pinMode(3, INPUT);
state=digitalRead(3);
digitalWrite(lastPin,HIGH);
}
void loop(){
if (state==HIGH & lastState==LOW){
count++;
remainder=count%3;
digitalWrite(lastPin, LOW);
digitalWrite(5+remainder, HIGH);
lastPin=5+remainder;
}
lastState=state;
state=digitalRead(3);
}
