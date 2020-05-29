#include <IRremote.h>
 
int RECV_PIN = 3; 
int led1 = 2;
int led2 = 4;
int led3 = 7;
int led4 = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led1,OUTPUT);
  pinMode(RECV_PIN, INPUT);
}
void loop()
{unsigned int value = results.value;
  if (irrecv.decode(&results) == 33444015)
  {
    digitalWrite(led1, HIGH);
  }
  else {
    digitalWrite(led1, LOW);
  }
}
