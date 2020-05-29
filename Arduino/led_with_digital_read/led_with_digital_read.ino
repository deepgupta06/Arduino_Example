void setup() {
  pinMode(9 ,INPUT);
  pinMode(13 ,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  if(digitalRead(9) == HIGH)
  {
    digitalWrite(13, HIGH);
  }
  else
  { 
    digitalWrite(13, LOW);
  }
  // put your main code here, to run repeatedly:

}
