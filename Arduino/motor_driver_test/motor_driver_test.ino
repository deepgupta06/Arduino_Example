void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(5000);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(5000);  // put your main code here, to run repeatedly:

}
