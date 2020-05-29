#define trigPin 6
#define echoPin 7
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
distance= ((duration/2)/29.1/100)*39.37;
Serial.print("Distance is");
Serial.print(distance);
Serial.println("in");
Serial.flush();
delay(1000);

}
