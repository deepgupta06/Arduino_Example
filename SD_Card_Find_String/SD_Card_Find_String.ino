#include <SD.h>
int CS_pin =10;
File dataFile;
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
  char t;
  while(Serial.available())
  {
    t +=(char)Serial.read();
  }
   String dataString = "BCDBCDEFGIJK";
   String dataString1 = "BCDBCDEFGI28";
   //char t ='BCDBCDEFGIJK';
   dataFile = SD.open("ABCDE.txt", FILE_WRITE);
    if(dataFile)
  {
    Serial.print("To Print-");
     Serial.println(dataString);
     dataFile.print(dataString);
     dataFile.println(dataString);
       dataFile.close();
     Serial.println("File Write is done");

  }
  dataFile=SD.open("ABCDE.txt");
  if (dataFile)
  {
  // while (dataFile.available())
   
    if (dataFile.find(t))
    {
      Serial.println("yes");
     
    }
     else
      {
        Serial.println("No");
      }
   
   dataFile.close();
    
  }
  SD.remove("ABCDE.txt");
  }
 
void loop() {
  char t;
  while(Serial.available())
  {
    t +=(char)Serial.read();
  }
   String dataString = "BCDBCDEFGIJK";
   String dataString1 = "BCDBCDEFGI28";
   //char t ='BCDBCDEFGIJK';
  
  dataFile=SD.open("ABCDE.txt");
  if (dataFile)
  {
  // while (dataFile.available())
   
    if (dataFile.find(t))
    {
      Serial.println("yes");
     
    }
     else
      {
        Serial.println("No");
      }
   
   dataFile.close();
    
  }
  SD.remove("ABCDE.txt");
  }
  
  // put your main code here, to run repeatedly:


