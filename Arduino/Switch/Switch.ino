void setup() {
  pinMode(12, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  if(digitalRead(8)== HIGH)
  {
    digitalWrite(12, HIGH);
  }
  else
  {digitalWrite(12, LOW);
  }// put your main code here, to run repeatedly:

}
