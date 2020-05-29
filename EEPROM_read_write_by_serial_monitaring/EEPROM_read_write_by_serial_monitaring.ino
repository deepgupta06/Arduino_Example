#include <EEPROM.h>
byte value;
 int address;
void setup() {
Serial.begin(9600);
}


void loop() {
  String t;
  while(Serial.available())
  {
    t +=(char)Serial.read();
  }
  Serial.println(t);
  delay(1010);
  if (t =="read")
  {
    Serial.println("Please Enter address");
     delay(3000);
     address = Serial.parseInt();
   
   
   
    if (address>=0 && address<=1023)
    {
      value= EEPROM.read(address);
      
      Serial.print("The Address is"  );
      Serial.println( address);
      Serial.print("The value is");
      Serial.print(value, DEC);
    }
    else
    {
      Serial.println("Invalied address");
    }
  }
  if (t == "write")
  {
    Serial.println("Enter the address where You want to Write");
    delay(3000);
    
    address =Serial.parseInt();
    if (address>=0 && address<=1023)
    {
      Serial.println("Enter the value You want to write");
      delay(3000);
      value = Serial.parseInt();
      if (value>=0 && value <=255)
      {
        EEPROM.write(address , value);
        Serial.print(value);
        Serial.print("is written on -");
        Serial.print(address);
      }
      else
      {
        Serial.print("Wrong Value");
      }
    }
    else
    {
      Serial.println("Invalied address");
    }
    
  }
// put your setup code here, to run once:

}
  
  // put your main code here, to run repeatedly:


