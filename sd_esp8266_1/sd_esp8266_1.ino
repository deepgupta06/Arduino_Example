#include <SD.h>

#include <SoftwareSerial.h>
#define DEBUG true
String webpage;
File dataFile;
int CS_pin =10;

SoftwareSerial esp8266(6,7 );
String cipsend;
void setup() {
Serial.begin(9600);
Serial.println("Initializing card");
pinMode(CS_pin, OUTPUT);
esp8266.begin(9600);
if (!SD.begin(CS_pin))
{
  Serial.println("Card failed");
  return;// put your setup code here, to run once:
}
Serial.println("Card is ready");

sendData("AT+RST\r\n",2000,DEBUG);
sendData("AT+CWMODE=1\r\n",1000,DEBUG);

sendData("AT+CWJAP=\"DEEP\",\"1234567890\"\r\n",3000,DEBUG);
delay(20000);
sendData("AT+CIFSR\r\n",1000,DEBUG);
sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG);
String dataString = "<h1>Hello </h1><h2>World</h2><button>LED1</button>";
dataFile = SD.open("webpage2.txt",FILE_WRITE);
  if (dataFile)
  {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
    
  }// put your setup code here, to run once:

}

void loop() {
  
if (esp8266.available())
{
  if (esp8266.find("+IPD"))
  {
  delay(2000);
  dataFile = SD.open("webpage2.txt");
  if(dataFile)
  {
    while(dataFile.available())
    {
    webpage = dataFile.read();
    
   
    }
    dataFile.close();
    
  }
  cipsend = "AT+CIPSEND=0,";
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



