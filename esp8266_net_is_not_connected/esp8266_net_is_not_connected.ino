#include <SoftwareSerial.h>
#define DEBUG true
SoftwareSerial esp8266(6,7);
String response;
void setup() {
Serial.begin(9600);
esp8266.begin(9600);
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CIPMODE=0\r\n",1000,DEBUG);
sendData("AT+CIPMUX=1\r\n",1000,DEBUG);

sendData("AT+CWMODE=3\r\n",1000,DEBUG);

sendData("AT+CWJAP=\"lol\",\"poiuytrewq\"\r\n",3000,DEBUG);
delay(5000);

sendData("AT+CIFSR\r\n",1000,DEBUG);
sendData("AT+CIPSTART=0,\"TCP\",\"planahost.com\",80\r\n",1000,DEBUG);
//sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
//sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG);// put your setup code here, to run once:
if (response = "DNS Fail")
{
  Serial.print("No");
}
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
    //do something....
  }

  Serial.println(finalresult);
  
  char pinNumber = (esp8266.read()-48)*10;
  pinNumber +=(esp8266.read()-48);
  if(pinNumber==11) Serial.println("lol");

  String closeCommand ="AT+CIPCLOSE=";
  closeCommand+=connectionId;
  sendData(closeCommand, 1000, DEBUG);
     }
  }
}
String sendData(String command,const int timeout,boolean debug)
{
  response="";
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


