void setup() {
  Serial.begin(9600);  //Open serial port
                      // Set data rate to 9600bps
  pinMode(9 , INPUT);

}

void loop() 
{if (digitalRead(9)== LOW)
{
  Serial.println(digitalRead(9));
  delay(1000);
}
else
{

  Serial.println(digitalRead(9));
  delay(1000);
  Serial.flush();
 
}

}
