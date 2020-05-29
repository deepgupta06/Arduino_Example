int Lsensor=8;
int Rsensor=9;
int RM1=0;
int RM2=1;
int LM1=2;
int LM2=3;
void setup() {
  Serial.begin(9600);
  pinMode(Rsensor, INPUT);
  pinMode(Lsensor,INPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
}
void loop() {
  if ( digitalRead(Lsensor)== HIGH)
{
  digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
}
else if( digitalRead(Rsensor)==HIGH)
{
  digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
}
else {
  digitalWrite(0, HIGH);
digitalWrite(1, LOW);
digitalWrite(2, HIGH);
digitalWrite(3  , LOW);
}
}
