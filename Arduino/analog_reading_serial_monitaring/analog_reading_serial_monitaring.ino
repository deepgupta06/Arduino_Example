void setup() {
  Serial.begin(9600);//Open serial port
                      // Set data rate to 9600bps  

}

void loop() 
{
    Serial.println(analogRead(0)/4);
  delay(1000);
  Serial.flush();
 

}
