void setup() {
  Serial.begin(9600);
  pinMode(0,INPUT);
  pinMode(13,OUTPUT);// put your setup code here, to run once:

}

void loop() 
{
  if (int digitalRead(0)==HIGH)
  {
  digitalWrite(13, HIGH);
  }// put your main code here, to run repeatedly:

}
