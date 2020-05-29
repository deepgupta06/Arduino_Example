#include <SD.h>
int CS_pin =10;
int powpin =8;

void setup() {
Serial.begin(9600);
Serial.println("Initializing card");
pinMode(CS_pin, OUTPUT);
pinMode(powpin, HIGH);
while(!Serial)
{
  ;
}
if (!SD.begin(CS_pin))
{
  Serial.println("Card failed");
  return;// put your setup code here, to run once:
}
Serial.println("Card is ready");
 File dataFile = SD.open("string.txt");
  if (dataFile)
  {
      int p;
      String a;
       String t;
    while(dataFile.available())
    {
     
      t += (char)dataFile.read();
      a = t;
      p = a.indexOf("B2345678");
   }
     Serial.println("The index of 9 in" + t + "is" +p);
    }
  
  
  else
  {
    Serial.println("Couldn't access file");
    
  }
   dataFile.close();
}

void loop() {
  
  
   }
  // put your main code here, to run repeatedly:


