int lsensor=8;
int rsensor=9;
int fsensor=10;
int lm1=0;
int lm2=1;
int rm1=2;
int rm2=3;
void setup()
{
  pinMode(lsensor, INPUT);
  pinMode(rsensor, INPUT);
  pinMode(fsensor, INPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
}
void loop()
{
  if (digitalRead(lsensor)== LOW)
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
   
  }
  else if (digitalRead(rsensor)== LOW)
  {
     digitalWrite(lm1,LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
   
  }
  else if (digitalRead(fsensor)==LOW)
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    delay(100);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
  else
  {
   digitalWrite(lm1,HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
   }
}
