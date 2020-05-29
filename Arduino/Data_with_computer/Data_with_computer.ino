
int ledpin=12;
void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}
void loop()
{
  while (Serial.available()==0);
const char val = Serial.read()-'0';
  if(val==1) 
  //(Serial.read.String("ledon")
  {
    Serial.println("Led is on");
    digitalWrite(ledpin,HIGH);
  }
  else if(val== 0)
  {
    Serial.println("Led is off");
    digitalWrite(ledpin, LOW);
  }
  else
  {
    Serial.println("INVALID INPUT");
  }
  Serial.flush();
}
