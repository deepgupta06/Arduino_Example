//int sensorPin = 8;
//int ledPin = 13;
void setup() 
{
pinMode(8, INPUT);
pinMode(13, OUTPUT);
// put your setup code here, to run once:

}

void loop() {

if (digitalRead(8) == HIGH)
{
 digitalWrite(13, HIGH);

}
else
{
  digitalWrite(13, LOW);
}// put your main code here, to run repeatedly:

}
