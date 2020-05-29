#define trigPin1 8
#define echoPin1 9
#define trigPin2 10
#define echoPin2 11
#define trigPin3 12
#define echoPin3 13
void setup() {
Serial.begin(9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

}

void loop() {
  float distance1, duration1, distance2, duration2, distance3, duration3;
  digitalWrite(trigPin1 , HIGH);
  delayMicroseconds(100);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= (duration1/2)/29.1;
Serial.print(distance1);
Serial.print("cm      ");
delay(1);
digitalWrite(trigPin2 , HIGH);
  delayMicroseconds(1000);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= (duration2/2)/29.1;
//Serial.print(distance2);
//Serial.println("cm ");
delay(1);
digitalWrite(trigPin3 , HIGH);
  delayMicroseconds(100);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distance3= (duration3/2)/29.1;
delay(1);
if (distance1 <=7)
{
  digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5  , LOW);
}
else if (distance3 <=7)
{
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5  , HIGH);
}
else if(distance2 <= 10)
{
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5  , LOW);
delay(600);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5  , LOW);
delay(600);
}
else
{digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5  , HIGH);
}
}
