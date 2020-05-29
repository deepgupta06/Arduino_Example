/*First Check Your Polarity Of your motors, edit this
code with your motor's polarity ,  */
#define trigPin 10
#define echoPin 11
int RM1=2;
int RM2=3;
int LM1=4;
int LM2=5;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);

}
void loop() {
  int distance, duration;
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1;
if (distance <= 4)
{
  digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
digitalWrite(LM1, LOW);
digitalWrite(LM2  , HIGH);
delay(300);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
  delay(300);
}
else
{
  digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
}
}
