const int analogPin1 = A0;
const int analogPin2 = A1;
void setup()
{
Serial.begin(9600);

}

void loop()
{   

 int  sensor1 = analogRead(analogPin1) ;
 int  sensor2 = analogRead(analogPin2) ;
 Serial.write('a');
Serial.println(sensor1);
delay(1000);
Serial.write('b');
Serial.println(sensor2);
delay(1000);
 }
