#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);
int  x,y,z;
void setup()
{
  
  Serial.begin(9600);
   mySerial.begin(9600);
}
void loop()
{
  if (mySerial.available())
  {
     x =mySerial.read();    
    Serial.print(x);
    Serial.print("         ");
    delay(100);
    
    y =mySerial.read();
 Serial.print(y);
 Serial.print("         ");
    delay(100);
    
    z =mySerial.read();
 Serial.println(z);
 }
}
