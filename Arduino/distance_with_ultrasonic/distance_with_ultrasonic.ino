#define trigPin 8
#define echoPin 9
void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
  float distance, duration;
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(100);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1/100;
Serial.print("Distance is");
Serial.print(distance);
Serial.println("meters");
Serial.flush();
delay(10000);

}
