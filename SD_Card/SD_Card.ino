#include <SD.h>
int CS_pin =10;
void setup()
{
  Serial.begin(9600);
  Serial.println("initializing");
  pinMode(CS_pin,OUTPUT);
  if (!SD.begin(CS_pin))
  {
    Serial.println("hgfhdgfghgfh");
    return;
    
  }
  Serial.println("card ready");
  
}

void loop()
{
  String dataString =" HELLO";
  File dataFile =SD.open("log.txt",FILE_WRITE);
  if (dataFile)
  {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
  }
  else
  {
    Serial.println("could not access file");
  }
  delay(5000);
  
}
