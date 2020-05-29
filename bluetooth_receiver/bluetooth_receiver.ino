int sensor1=0;
int sensor2=0;

int inByte = -1;
char inString[6];
int stringPos = 0; 

void setup() {
Serial.begin(9600);


delay(1000);

}

void loop() {
if(Serial.available() > 0)
{
char inChar = Serial.read();


if (inChar == 'a')
{
sensor1 = Serial.parseInt() ;
Serial.println(sensor1);
}

if (inChar == 'b')
{
sensor2 = Serial.parseInt() ;
Serial.println(sensor2);
}
}
delay(100);
}
