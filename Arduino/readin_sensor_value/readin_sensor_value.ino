#include <IRremote.h>
int sensor = 0;
void setup() {
 pinMode(sensor, INPUT);
 pinMode(13,OUTPUT);
 Serial.begin(9600);
}

void loop(){
Serial.println(analogRead(sensor));
delay(2000);
}
  
