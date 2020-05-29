#include <IRremote.h>
const int RECV_PIN = 12;

IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
Serial.begin(9600) ;

irrecv.enableIRIn();

}

void loop() {
if (irrecv.decode(&results))
{
 
  Serial.println(results.value);

   irrecv.resume();
 
}
Serial.flush();
delay(1000);

}
