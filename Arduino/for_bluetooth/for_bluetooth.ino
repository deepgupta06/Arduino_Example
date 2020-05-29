int ledpin = 13;
int state=0;
int flag =0;
void setup()
{
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    state = Serial.read();
    flag=0;
    
  }
  if (state == '0')
  {
    digitalWrite(ledpin, LOW);
    if (flag == 0)
    {
      Serial.println("LED Off");
    flag = 1;
  }
}
else if (state =='1')
{
  digitalWrite(ledpin , HIGH);
  if(flag == 0)
  {
    Serial.print("led on");
    flag =1;
  }
}
}

