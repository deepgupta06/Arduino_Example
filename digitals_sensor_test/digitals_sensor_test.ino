int sensor=12;
int sensorpower=13;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(sensorpower, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(sensorpower, HIGH);
  Serial.println(digitalRead(sensor));
  delay(500);
  // put your main code here, to run repeatedly:

}
