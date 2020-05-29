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
  String dataString = "ABCD";
  String dataString1 = "EFGH";
  String dataString2 = "IJKL";
  String dataString3 = "MNOP";
  dataFile = SD.open("ABCD.php", FILE_WRITE);
  if(dataFile)
  {
    Serial.print("To Print-");
     Serial.println(dataString);
   Serial.println(dataString1);
    Serial.println(dataString2);
     Serial.println(dataString3);
    dataFile.seek(0);
     dataFile.print("    ");
  dataFile.print(dataString);
  dataFile.print("    ");
    dataFile.print(dataString1);
 dataFile.print("    ");
  dataFile.println(dataString2);
  dataFile.print("    ");
  dataFile.print(dataString3);
  
  
  
  Serial.println("File Write is done");
  dataFile.close();
  }
  String a ="ABCD.txt";
  dataFile = SD.open(a);
  if(dataFile.find("A"))
  {
    //delay(30);
    String t;
    while(dataFile.available())
    {
      
     dataFile.seek(12);
    // dataFile.peek();
      //Serial.write(dataFile.read());
      //dataFile.position();
   //  t =(char)dataFile.read();
   char a=dataFile.read();
   
     Serial.print(a);
     dataFile.seek(13);
     char b=dataFile.read();
     Serial.print(b);
      return;
     // delay(1000);
      
      // dataFile.close();
      
      
    }
    dataFile.close();
  }
  SD.remove("ABCD.txt");
  
  
  
  }
  
  


void loop() {
  // put your main code here, to run repeatedly:

}
String twoValu()
{
}



