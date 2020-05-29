//pass
#include <SD.h>
#include <SoftwareSerial.h>
#define DEBUG true
String cipsend;
SoftwareSerial esp8266(6,7 );
int CS_pin =10;
File dataFile;
File jquery;
void setup() {
   Serial.begin(9600);
   esp8266.begin(9600);
    Serial.println("initializing");
  pinMode(CS_pin,OUTPUT);
  if (!SD.begin(CS_pin))
  {
    Serial.println("error");
    return;
      }
 sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CWMODE=3\r\n",1000,DEBUG);

sendData("AT+CWJAP=\"ILLUMINI\",\"embryo_mozambique1234\"\r\n",3000,DEBUG);
delay(5000);
sendData("AT+CIFSR\r\n",1000,DEBUG);
sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG);// put your setup code here, to run once:

      
  // put your setup code here, to run once:

}

void loop() {
  if (esp8266.available())
  {
   if (esp8266.find("+IPD"))
   {
     delay(2000);
     sendData("AT+CIPSEND=0,1000\r\n",4000,DEBUG);
     dataFile = SD.open("index.htm");
     jquery = SD.open("jquery.min.js");
     if (dataFile)
     {
     while(dataFile.available())
     {
      esp8266.print(+(char)dataFile.read());
     }
     delay(5000);
     }
     dataFile.close();
     jquery.close();
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

