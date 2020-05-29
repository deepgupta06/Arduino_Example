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
  while (Serial.available()<=0);
 float a=Serial.parseFloat();
 Serial.println(a);
if(a <-3)
{digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}
else if(a>=-3 )
{
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  
}
else if(a>-1)
{
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  
}

 
 
}
