void setup() {
pinMode(15, OUTPUT); 
pinMode(13, OUTPUT);
digitalWrite(13, LOW);// put your setup code here, to run once:

}

void loop() {
  digitalWrite(15, HIGH);
  delay(1000);
  digitalWrite(15,LOW);
  delay(1000);
  // put your main code here, to run repeatedly:

}
