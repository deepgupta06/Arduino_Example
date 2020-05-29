void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
   
    while(Serial.available() == 0)
int t = Serial.read()-'0';
    
    if (t == 1)
    {
      digitalWrite(13,HIGH);
    }
    else
    {
      digitalWrite(13,LOW);
    }
        }
  // put your main code here, to run repeatedly:


