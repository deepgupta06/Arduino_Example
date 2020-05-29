void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  //char rx_byte;
  if (Serial.available()>0)
  {
  char rx_byte=Serial.read();
  if (rx_byte=='L')
  {
    digitalWrite(13, HIGH);
   Serial.println(rx_byte);
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.println(rx_byte);
  }
}
//Serial.println(rx_byte);
//delay(500);
}
  
