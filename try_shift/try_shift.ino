int data =11;
int clk =12;
int lach =8;
int led[9]={B0,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};
void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(lach, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(data, LOW);
}
void loop()
{ 
  
  for(int i =0;i<=15;i++)
  { 
 digitalWrite(lach,LOW);
 digitalWrite(data, HIGH);
 digitalWrite(clk, HIGH);
 digitalWrite(clk,LOW);
 digitalWrite(lach,HIGH);

  if(digitalRead(2)==HIGH)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
   delay(1000);
 
  }
  for(int i =0;i<=15;i++)
  { 
 digitalWrite(lach,LOW);
 digitalWrite(data, LOW);
 digitalWrite(clk, HIGH);
 digitalWrite(clk,LOW);
 digitalWrite(lach,HIGH);

  }
  
 }

