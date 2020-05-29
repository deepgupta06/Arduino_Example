int Lsensor=6;
int Rsensor=7;
int RM1=4;
int RM2=5;
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
  Serial.println(digitalRead(Lsensor));
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
}
else if( digitalRead(Rsensor)==HIGH)
{
  Serial.println(digitalRead(Rsensor));
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
}
else {
  digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
digitalWrite(LM1, HIGH);
digitalWrite(LM2,LOW);
}
}


