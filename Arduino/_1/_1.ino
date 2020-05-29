void setup() {
Serial.begin(9600);  // put your setup code here, to run once:

}

void loop() {
  while (Serial.available()== 0);
  int val = Serial.read() - '0';
  Serial.println(lED IS oN);
  // put your main code here, to run repeatedly:

}
