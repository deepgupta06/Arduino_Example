#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(7, 8);
const byte address[6]="00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  // put your setup code here, to run once:

}

void loop() {
  const char text[]="hello world";
  radio.write(&text, sizeof(text));
  delay(1000);
  Serial.print("done");// put your main code here, to run repeatedly:

}
