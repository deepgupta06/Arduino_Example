float r1 = 29700;
float r2=7000;
int sensorvalue;
  float voltage=0 ;
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  analogWrite(9 ,150);
  // put your setup code here, to run once:

}

void loop() {
  while (Serial.available()==0);

    int a=Serial.parseInt();
   // Serial.print(a);
    analogWrite(9 ,a);

    delay(2000);
    for(int i =0; i<5; i++)
    {
 
    for (int i =0; i<999; i++)
    {
      sensorvalue = analogRead(A0);
      
 voltage =  voltage + ((5*sensorvalue*(r1+r2))/(1000*r2));
    delay(1);
    }
    
    
    voltage = voltage/999;
    Serial.println(voltage);
 /* int sensorvalue = analogRead(A0);
  float voltage = (5*sensorvalue*(r1+r2))/(1000*r2);
  Serial.print("V1=");
  Serial.print(sensorvalue);
  Serial.print("      ");*/
  
 /*  int sensorvalue1 = analogRead(A1);
  float voltage1 = (5*sensorvalue1*(r1+r2))/(1000*r2);
  Serial.print("V2=");
  Serial.println(voltage1);*/
  delay(1000);
  // put your main code here, to run repeatedly:

}
}
