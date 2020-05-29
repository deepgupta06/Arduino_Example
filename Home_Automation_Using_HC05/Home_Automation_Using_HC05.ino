
#include <SoftwareSerial.h>
SoftwareSerial mySerial (11, 12); // Pin 11 is connected to Tx of HC-05
int pinNumber;                    // Pin 12 is connceted to Rx of HC-05   
void setup() {
  mySerial.begin(9600);

 ////////////////////////////////////
 /////////Change as per your///////// 
 /////////pin configuration//////////
 ////////////////////////////////////
 
 pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  }

void loop() {
  while (mySerial.available())
  {
    pinNumber = mySerial.parseInt();
    digitalWrite(pinNumber , !digitalRead(pinNumber));    
  }
  // put your main code here, to run repeatedly:

}
