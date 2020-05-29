#include <MFRC522.h>

#include <SPI.h>

/**   * mfrc522.PICC_IsNewCardPresent() should be checked before    * @return the card UID   */ 
void setup()
{
if(mfrc522.PICC_IsNewCardPresent())
 {  
 unsigned long uid = getID(); 
  if(uid != ‐1)
{    
 Serial.print("Card detected, UID: "); 
Serial.println(uid); 
  }
}
}
void loop()
{

}
 unsigned long getID()
{
    if ( ! mfrc522.PICC_ReadCardSerial()) 
  { //Since a PICC placed get Serial and continue     
  return ‐1;
    }   
  unsigned long hex_num; 
    hex_num =  mfrc522.uid.uidByte[0] << 24;   
  hex_num += mfrc522.uid.uidByte[1] << 16; 
    hex_num += mfrc522.uid.uidByte[2] <<  8;
    hex_num += mfrc522.uid.uidByte[3];
    mfrc522.PICC_HaltA(); // Stop reading
// return hex_num;
}

