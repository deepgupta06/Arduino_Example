int potpin = 0;

void setup() {
  pinMode (potpin , INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(analogRead(potpin));
 
  // put your main code here, to run repeatedly:

}
