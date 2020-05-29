
void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  while (Serial.available()==0);
  while
  {
 int a=Serial.read()-'0';
  Serial.print("a =");
  Serial.println(a);}
  
 int b= Serial.read()-'0';
  Serial.print("b =");
  Serial.println(b);
  int c= a+b;
  Serial.print("c =");
  Serial.println(c);
  delay(1000);
  // put your main code here, to run repeatedly:

}
