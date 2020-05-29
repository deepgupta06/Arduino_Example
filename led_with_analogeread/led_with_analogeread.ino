void setup() {
  Serial.begin(9600);//Open serial port
                      // Set data rate to 9600bps  

}

void loop() 
{
    Serial.println(analogRead(0)/4);
    int v = analogRead(0)/4;
  analogWrite(9, v);
  Serial.flush();
 

}
