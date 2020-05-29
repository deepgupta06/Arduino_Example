void setup() {
  pinMode(0, INPUT);
  pinMode(8, OUTPUT);
 
  // put your setup code here, to run once:

}

void loop() {
 if (digitalRead(0)== HIGH)
{
 digitalWrite(8, HIGH);
}
else
{
  digitalWrite(8, LOW);
}// put your main code here, to run repeatedly:

}
