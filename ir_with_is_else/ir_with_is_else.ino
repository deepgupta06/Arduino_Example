#include <IRremote.h>
const int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
Serial.begin(9600) ;

irrecv.enableIRIn();
pinMode(12, OUTPUT);

}

void loop() {
if (irrecv.decode(&results))
{
 
  Serial.println(results.value);
//  translateIR();
   irrecv.resume();
 
}// put your main code here, to run repeatedly:
Serial.flush();
if (results.value==33444015)
{
  digitalWrite(12, HIGH);
}
else
{
  digitalWrite(12, LOW);
}
delay(1000);

}
