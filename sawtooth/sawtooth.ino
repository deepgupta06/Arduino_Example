float a,b,c,i,d;
void setup() {
Serial.begin(9600);
a=20;
b=3;// put your setup code here, to run once:

}

void loop() {
  a=a+1;
  for(i =0; i<=a;i++)
  {
    d = b/a;
    c=d*i;
     Serial.println(c);
    
    delay(1);
  }
  //Serial.println(2*sin(90));
  // put your main code here, to run repeatedly:

}
