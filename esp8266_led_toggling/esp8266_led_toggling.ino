#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial esp8266(10,11);
void setup() {
Serial.begin(9600);
esp8266.begin(9600);
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CWMODE=3\r\n",1000,DEBUG);

sendData("AT+CWJAP=\"lol\",\"lol12345\"\r\n",3000,DEBUG);
delay(5000);
sendData("AT+CIFSR\r\n",1000,DEBUG);
sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG);// put your setup code here, to run once:

}

void loop() {
if (esp8266.available())
{
  if (esp8266.find("+IPD,"))
  {
  delay(1000);
  int connectionId = esp8266.read()-48;
  int a = esp8266.read();
  
  esp8266.find("pin=");
  int pinNumber = (esp8266.read()-48)*10;
  pinNumber +=(esp8266.read()-48);
  Serial.println(connectionId);
  Serial.println(pinNumber);
  digitalWrite(pinNumber, !digitalRead(pinNumber));
  String closeCommand ="AT+CIPCLOSE=";
  closeCommand+=connectionId;
  sendData(closeCommand, 1000, DEBUG);
     }
  }
}
String sendData(String command,const int timeout,boolean debug)
{
  String response="";
  esp8266.print(command);
  long int time =millis();
  while((time+timeout)>millis())
  {
    while(esp8266.available())
    {
      char c=esp8266.read();
    response+=c;
  }
}
if(debug)
{
  Serial.print(response);
}
return response;
}


