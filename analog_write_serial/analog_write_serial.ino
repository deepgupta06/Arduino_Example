
  void setup()
{
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
}
  // put your setup code here, to run once:



void loop() {
   while (Serial.available()==0);
    int a=Serial.parseInt();
    Serial.print(a);
    
    analogWrite(D0 ,a);
    delay(200);
    
   
  
  // put your main code here, to run repeatedly:

}
