void setup() {
 Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop() {
  delay(30);
  String t;
  while(Serial.available())
  {
    t+=(char)Serial.read();
  }
  if (t=="s2on")
  {
    digitalWrite(2, HIGH);
   }
   else if(t=="s2off")
   {
    digitalWrite(2,LOW);
   }
   else if (t=="s3on")
  {
    digitalWrite(3, HIGH);
   }
   else if(t=="s3off")
   {
    digitalWrite(3,LOW);
   }
   else if (t=="s4on")
  {
    digitalWrite(4, HIGH);
   }
   else if(t=="s4off")
   {
    digitalWrite(4,LOW);
   }
   else if (t=="s5on")
  {
    digitalWrite(5, HIGH);
   }
   else if(t=="s5off")
   {
    digitalWrite(5,LOW);
   }
   
   else if (t=="s6on")
  {
    digitalWrite(6, HIGH);
   }
   else if(t=="s6off")
   {
    digitalWrite(6,LOW);
   }
   else if (t=="s7on")
  {
    digitalWrite(7, HIGH);
   }
   else if(t=="s7off")
   {
    digitalWrite(7,LOW);
   }
   else if (t=="s8on")
  {
    digitalWrite(8, HIGH);
   }
   else if(t=="s8off")
   {
    digitalWrite(8,LOW);
   }
   else if (t=="s9on")
  {
    digitalWrite(9, HIGH);
   }
   else if(t=="s9off")
   {
    digitalWrite(9,LOW);
   }
   else if (t=="s10on")
  {
    digitalWrite(10, HIGH);
   }
   else if(t=="s10off")
   {
    digitalWrite(10,LOW);
   }
   else if (t=="s11on")
  {
    digitalWrite(11, HIGH);
   }
   else if(t=="s11off")
   {
    digitalWrite(11,LOW);
   }
   else if (t=="s12on")
  {
    digitalWrite(12, HIGH);
   }
   else if(t=="s12off")
   {
    digitalWrite(12,LOW);
   }
   else if (t=="s13on")
  {
    digitalWrite(13, HIGH);
   }
   else if(t=="s13off")
   {
    digitalWrite(13,LOW);
   }
   
   
   
  }



