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

  SD.remove("webpage2.txt");
  }
  
  


void loop() {
  // put your main code here, to run repeatedly:

}




