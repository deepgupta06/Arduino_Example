void setup() {
  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
 if ( digitalRead == HIGH)
 {
  digitalWrite(13 , HIGH);
 }
  else 
  {
    digitalWrite(13, LOW);
  }
}
