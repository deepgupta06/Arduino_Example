#include <EEPROM.h>
#include <stdio.h>

String command;


uint8_t addrWrite, 
    valueWrite, 
    addrRead, 
    valueRead;
                  
void setup() {
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
  Serial.print("Enter command( in small letters only): \n");
}

void loop() {
    if(Serial.available() > 0){
        // read the incoming string:
        command = Serial.readStringUntil(' ');
        
          // write to EEPROM ... 8bits numbers[0:255]
        if (command == "write") {
            // get addr and value
            addrWrite = Serial.parseInt();
            valueWrite = Serial.parseInt();

            // Write to EEPROM:
            EEPROM.write(addrWrite, valueWrite);
            Serial.print("Done.\n");  
        }

        // read from EEPROM
        else if (command == "read") {

            // get addr and fetch the value from eeprom
            addrRead = Serial.parseInt();
            valueRead = EEPROM.read(addrRead);

            Serial.print("Value in this address: ");
            Serial.println(valueRead, DEC);  
            Serial.print("\n");    
        } 
        
        // in case of idiot user :3 
        else {
            Serial.print("\n");  
            Serial.print("Handling for such request is not set\n");
        }        
    } 
}
