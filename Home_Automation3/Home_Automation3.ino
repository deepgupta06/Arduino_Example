int a;
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}
void loop()
{
  while(Serial.available())
  {
    a = Serial.parseInt();
    if (a>1){
   digitalWrite(a , !digitalRead(a));
    }
    if(a==255 || a==0)
  analogWrite(A0, a);
   if(a==254 || a==1)
  analogWrite(A1, a);
   if(a==253 || a==2)
  analogWrite(A2, a);
   if(a==252 || a==3)
  analogWrite(A3, a);
   if(a==251 || a==4)
  analogWrite(A4, a);
   if(a==250 || a==5)
  analogWrite(A5, a);
      Serial.println(a);
  }
  }

