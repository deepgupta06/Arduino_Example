void setup()
{
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
digitalWrite(13,HIGH);
}
void loop()
{
  delay(30);
  String t;
  while (Serial.available())
  {
    t+= (char)Serial.read();
  }
  if(t=="hello mark")
  {
    Serial.print("Hello Sir");
  }
  else if(t=="are you ready")
  {
    Serial.print("yes Sir ");
    delay(200);
    Serial.println(" I am ready to except command");
  }
 
  
 else if (t=="forward")
  {
    digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  }
  else if(t=="backward")
  {
    digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  }
  else if(t=="left")
  {
    digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  
  }
  else if(t=="right")
  {
    digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  }
  else if(t=="stop")
  {
    digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  }
  
}
    


