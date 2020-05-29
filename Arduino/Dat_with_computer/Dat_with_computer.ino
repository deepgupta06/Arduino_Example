const int redpin=13;
const int greenpin=5;
const int bluepin=6;
void setup() {
Serial.begin(9600);
pinMode(redpin,OUTPUT);
pinMode(greenpin,OUTPUT);
pinMode(bluepin,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  while(Serial.available()>0)
  
    int red=Serial.parseInt();
    int green=Serial.parseInt();
    int blu=Serial.parseInt();
if(Serial.read()=='red\n')
{
  digitalWrite(redpin, HIGH);// put your main code here, to run repeatedly:

}
else 
{digitalWrite(redpin, LOW);
}
}
