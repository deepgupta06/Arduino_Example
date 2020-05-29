//int row1=13;
//int row2=12;
//int row3=11;
//int c11=10;
//int c12=9;
//int c13=8;
//int c14=7;
//int c15=6;
//int c16=5;
//int cl7=4;
//int cl8=3;
//int cl9=2;
void setup() {
pinMode(11, OUTPUT); 
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
//pinMode(cl4, OUTPUT);
//pinMode(cl5, OUTPUT);
//pinMode(cl6, OUTPUT);
//pinMode(cl7, OUTPUT);
//pinMode(cl8, OUTPUT);
//pinMode(cl9, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  digitalWrite(11, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  delay(1000);
   digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  delay(1000);
  // put your main code here, to run repeatedly:

}
