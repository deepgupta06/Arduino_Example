int val;
void setup() {

  Serial.begin(9600);
  pinMode(9, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  val= 1024-analogRead(0);
  val=map(val,0,1023,0,255);
  analogWrite(9, val);
  Serial.println(val);
  delay(15);
  // put your main code here, to run repeatedly:

}
