void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while (Serial.available()==0);
 int a=Serial.parseInt();
long int b= Serial.parseFloat();

 
 Serial.print(a);
 Serial.println(b);
 delay(1000);
}

