void setup() {
  pinMode(10, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
 int a;
 while(Serial.available()==0);
 a=Serial.parseInt();
 
 //Serial.println(a);
 analogWrite(10, a);
 Serial.println(analogRead(A1));
  // put your main code here, to run repeatedly:

}
