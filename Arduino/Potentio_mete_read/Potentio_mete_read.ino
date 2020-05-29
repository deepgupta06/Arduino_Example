int potpin =0 ;
int led =13;

void setup() {
  pinMode (potpin , INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(analogRead(potpin));
  analogWrite(led , potpin);
  delay(1000); 
 
  // put your main code here, to run repeatedly:

}
