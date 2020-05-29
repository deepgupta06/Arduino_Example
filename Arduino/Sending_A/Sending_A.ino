void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  //char rx_byte;
  if (Serial.available()>0)
  {
  rx_byte=Serial.read();
  if (rx_byte=='L')
  {
    digitalWrite(13, HIGH);
    Serial.println("Led is on");
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.println("Led is Off");
  }
}
}
  
