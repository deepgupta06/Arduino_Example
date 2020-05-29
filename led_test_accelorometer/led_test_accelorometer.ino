void setup()
{
  Serial.begin(9600);
pinMode(13,OUTPUT);
}
void loop()
{
  while (Serial.available()<=0);
 float a=Serial.parseFloat();
 Serial.println(a);
if(a <-2)
{
  digitalWrite(13, HIGH);
}
else if(a>-2)
{digitalWrite(13,LOW);

}

 
 
}

