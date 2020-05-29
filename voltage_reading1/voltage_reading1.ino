float r1 = 29700;
float r2=7500;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int sensorvalue = analogRead(A0);
  float voltage = (5*sensorvalue*(r1+r2))/(1000*r2);
  Serial.print(voltage);
  Serial.print("       ");
  Serial.println(sensorvalue);
  delay(1000);
  // put your main code here, to run repeatedly:

}
