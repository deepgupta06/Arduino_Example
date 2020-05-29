void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(5000);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(5000);  // put your main code here, to run repeatedly:

}
