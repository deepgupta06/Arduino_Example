void setup() {
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);// put your setup code here, to run once:

}


void loop() {
  digitalWrite(13, HIGH);
   digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(2000);
   digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  delay(2000);
  // put your main code here, to run repeatedly:

}
