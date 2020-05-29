#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial esp8266(10,11);
void setup() {
Serial.begin(9600);
esp8266.begin(9600);
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CWMODE=1\r\n",1000,DEBUG);
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
  String a;
  
  esp8266.find("pin=");
  String x;
  for(int i=0;i<=20;i++) {
    x +=(char)esp8266.read();
  }
  
  //Serial.println(x);

  char data[1024];
  strcpy(data, x.c_str());

  int len = strlen(data);

  String finalresult;
  for (int i = 0; i < len; i++)
  {
    char chr = data[i];
    if(chr==' ') break;
    finalresult +=(char)chr;
   if (finalresult == "ledon")
   {
    digitalWrite(13,HIGH);//do something....
   }
   else if(finalresult == "ledoff")
   {
    digitalWrite(13,LOW);
   }
  }

  Serial.println(finalresult);
  sendData("AT\r\n",2000,DEBUG);
  
  
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


