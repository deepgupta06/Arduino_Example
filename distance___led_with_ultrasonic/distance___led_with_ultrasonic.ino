#define trigPin 7
#define echoPin 6
void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(13,OUTPUT);
}

void loop() {
  float distance, duration;
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(100);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1;
Serial.print("Distance is");
Serial.print(distance);
Serial.println("cm");
Serial.flush();
delay(1000);
if(distance<=10)
{
  digitalWrite(13,HIGH);
}
else
{
  digitalWrite(13,LOW);
}
}
