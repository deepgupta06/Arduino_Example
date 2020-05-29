#include <SD.h>
#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial esp8266(6,7 );
void setup() {
Serial.begin(9600);
esp8266.begin(9600);
sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CWMODE=1\r\n",1000,DEBUG);

sendData("AT+CWJAP=\"DEEP\",\"1234567890\"\r\n",3000,DEBUG);
delay(20000);
sendData("AT+CIFSR\r\n",1000,DEBUG);
sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG);// put your setup code here, to run once:

}

void loop() {
if (esp8266.available())
{
  if (esp8266.find("+IPD"))
  {
  delay(2000);
  String webpage="<h1>Hello </h1><h2>World</h2><button>LED1</button>";
  String cipsend = "AT+CIPSEND=0,";
  cipsend+=webpage.length();
  cipsend+="\r\n";
  
  sendData(cipsend,3000,DEBUG);
  sendData(webpage,3000,DEBUG);
  
  webpage="<button>LED2</button>";
  cipsend="AT+CIPSEND=0,";
  cipsend+=webpage.length();
  cipsend+="\r\n";
  
  sendData(cipsend,3000,DEBUG);
  sendData(webpage,3000,DEBUG);
  sendData("AT+CIPCLOSE=0\r\n",3000,DEBUG);
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


