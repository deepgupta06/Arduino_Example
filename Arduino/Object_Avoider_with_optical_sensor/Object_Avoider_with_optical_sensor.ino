int sensor=8;
int RM1 = 2;
int RM2 = 3;
int LM1 = 4;
int LM2 = 5;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
 if (digitalRead(sensor)==LOW)
{ 
  digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5  , LOW);
delay(500);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5  , LOW);
delay(300); 
}
else
{
  digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5  , HIGH);
}

}
