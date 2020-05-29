boolean ledon1=false;
int count3=0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
   delay(30);
  String t;
  while(Serial.available()>0)
  {
    t+=(char)Serial.read();
  }
     if(t=="s")
  {
    count3= count3++;
   if((count3%2)== 1)
    {
     digitalWrite(13,HIGH);
   }
    else if((count3%2)==0)
   {
      digitalWrite(13,LOW);
    }
   
 
  }
  }
