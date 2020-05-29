void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 for(int i=0; i<=255; i++)
  {
    analogWrite(10, i);
    delay(5);
   // for (int j=0; j<=255;j++)
    ///{analogWrite(8, j);
  //delay(5);
//}
  }
 
 for( int i=255;i>=0;i--)
  {
  analogWrite(10, i);
delay(5);
}
 
  // put your main code here, to run repeatedly:

}
