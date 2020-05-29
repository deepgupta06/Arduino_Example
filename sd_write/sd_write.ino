#include <SD.h>
int CS_pin =10;
int powpin =8;

void setup() {
Serial.begin(9600);
Serial.println("Initializing card");
pinMode(CS_pin, OUTPUT);
pinMode(powpin, HIGH);
if (!SD.begin(CS_pin))
{
  Serial.println("Card failed");
  return;// put your setup code here, to run once:
}
Serial.println("Card is ready");
}

void loop() {
  String dataString = "<h1>Hello </h1><h2>World</h2><button>LED1</button>";
  File dataFile = SD.open("log.xml",FILE_WRITE);
  if (dataFile)
  {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
    
  }
  else
  {
    Serial.println("Couldn't access file");
    
  }
   }
  // put your main code here, to run repeatedly:


