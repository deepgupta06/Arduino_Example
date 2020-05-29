int led=13;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(8, OUTPUT);
}
void loop()
{
  delay (30);
  String t;
  while(Serial.available())
  {
    t += (char)Serial.read();
  }
  if (t.length())
  {
    if(t =="light on")
    {
      digitalWrite(led, HIGH);
      Serial.write("LED is on");
    }
    else if (t== "light off")
    {
      digitalWrite(led, LOW);
      Serial.write("LED is off");
    }
  }
  if (t.length())
  {
    if(t =="fan on")
    {
      digitalWrite(8, HIGH);
      Serial.write("fan is on");
    }
    else if (t== "fan off")
    {
      digitalWrite(8, LOW);
      Serial.write("fan is off");
    }
  }
}
