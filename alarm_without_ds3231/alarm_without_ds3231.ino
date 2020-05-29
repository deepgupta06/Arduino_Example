#include <EEPROM.h>
int val,count=0;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
 
  while (Serial.available()==0);
    int val=Serial.parseInt();
    EEPROM.write(0, val);
    Serial.print(EEPROM.read(0));// put your setup code here, to run once:

}

void loop() {
 

  while(EEPROM.read(0)==count)
  {
    for(int i =0;i<=40;i++)
  {
    digitalWrite(13,1);
    delay(250);
    digitalWrite(13,0);
    delay(250);
    i=i++;
  Serial.print("alarm is on");
  
  }
  count=0;
  break;
  
  }
  delay(60000);
  
  count=count+1;
  Serial.println(count);
  //EEPROM.write(2,count);
  // put your main code here, to run repeatedly:

}
