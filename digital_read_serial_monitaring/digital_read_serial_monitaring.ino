void setup() {
  Serial.begin(9600);  //Open serial port
                      // Set data rate to 9600bps
  pinMode(9 , INPUT);

}

void loop() 

{
  Serial.println(digitalRead(9));
  delay(1000);


}
