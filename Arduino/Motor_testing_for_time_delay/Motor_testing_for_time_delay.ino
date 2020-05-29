
int RM1=0;
int RM2=1;
int LM1=2;
int LM2=3;

void setup() 
{ 
  
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
}
void loop()
{digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
delay(500);
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
delay(2000);
}
