#include <SoftwareSerial.h>
SoftwareSerial esp8266(6,7 );
#define DEBUG true

void setup() {
  Serial.begin(9600);
esp8266.begin(9600);

sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CWMODE=1\r\n",1000,DEBUG);

sendData("AT+CWJAP=\"DEEP\",\"1234567890\"\r\n",3000,DEBUG);
delay(5000);
sendData("AT+CIFSR\r\n",1000,DEBUG);
sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG);
}

void loop() {
  if (esp8266.available())
  {
    if (esp8266.find("+IPD"))
    {
       String webpage="<h1>Hello </h1><h2>World</h2><button>LED1</button>";
      String cipsend = "AT+CIPSEND=0,";
  cipsend+=webpage.length();
  cipsend+="\r\n";
  
  sendData(cipsend,3000,DEBUG);
  sendData(webpage,10000,DEBUG);
  // esp8266.print(webpage);
  delay(5000);    
    }
    
  }
  }
  // put your main code here, to run repeatedly:


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
