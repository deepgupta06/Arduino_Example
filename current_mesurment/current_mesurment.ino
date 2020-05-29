void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  float volt =0;
  int sensor;
  for (int i = 0; i<=2999; i++)
  {
    sensor = analogRead(A0);
    volt = volt +((sensor*.0048)*1000);
      }
  float voltage = volt/3000;
  float current = voltage/1.01;
  Serial.println(current);//*.0048)/1)*1000);
  delay(500);// put your main code here, to run repeatedly:

}
