boolean ledon1=false;
boolean ledon2=false;
boolean ledon3=false;
boolean ledon4=false;
boolean ledon5=false;
boolean ledon6=false;
boolean ledon7=false;
boolean ledon8=false;
boolean ledon9=false;
boolean ledon10=false;
boolean ledon11=false;
boolean ledon12=false;
boolean ledon13=false;
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;
int count6=0;
int count7=0;
int count8=0;


void setup()
{
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
void loop()
{
  delay(30);
  String t;
  while(Serial.available())
  {
    t+=(char)Serial.read();
  }
  if (t=="s1")
  {
    ledon1 = !ledon1;
    digitalWrite(2, ledon1);
  }
  if (t=="s2")
  {
    ledon2 = !ledon2;
    digitalWrite(3, ledon2);
  }
  if (t=="s3")
  {
    ledon3 = !ledon3;
    digitalWrite(4, ledon3);
  }

 if (t=="s4")
  {
    ledon4 = !ledon4;
    digitalWrite(5, ledon4);
  }
  if (t=="s5")
  {
    ledon5 = !ledon5;
    digitalWrite(6, ledon5);
  }
  if (t=="s6")
  {
    ledon6 = !ledon6;
    digitalWrite(7, ledon6);
  }
  if (t=="s7")
  {
    ledon7 = !ledon7;
    digitalWrite(8, ledon7);
  }
  if (t=="s8")
  {
    ledon8 = !ledon8;
    digitalWrite(9, ledon8);
  }
  if (t=="s9")
  {
    ledon9 = !ledon9;
    digitalWrite(10, ledon9);
  }
  if (t=="s10")
  {
    ledon10 = !ledon10;
    digitalWrite(11, ledon10);
  }
  if (t=="s11")
  {
    ledon11 = !ledon11;
    digitalWrite(12, ledon11);
  }
  if (t=="s12")
  {
    ledon12 = !ledon12;
    digitalWrite(13, ledon12);
  }
  if(t=="s13")
  {
    count1= count1++;
   if((count1%2)== 1)
    {
     analogWrite(A0, 255);
   }
    else if((count1%2)==0)
   {
      analogWrite(A0,0);
    }
   }
   if(t=="s14")
  {
    count2= count2++;
   if((count2%2)== 1)
    {
     analogWrite(A1, 255);
   }
    else if((count2%2)==0)
   {
      analogWrite(A1,0);
    }
   }
   if(t=="s15")
  {
    count3= count3++;
   if((count3%2)== 1)
    {
     analogWrite(A2, 255);
   }
    else if((count3%2)==0)
   {
      analogWrite(A2,0);
    }
   }
  if(t=="s16")
  {
    count4= count4++;
   if((count4%2)== 1)
    {
     analogWrite(A3, 255);
   }
    else if((count4%2)==0)
   {
      analogWrite(A3,0);
    }
   }
   if(t=="s17")
  {
    count5= count5++;
   if((count5%2)== 1)
    {
     analogWrite(A4, 255);
   }
    else if((count5%2)==0)
   {
      analogWrite(A4,0);
    }
   }
   if(t=="s18")
  {
    count6= count6++;
   if((count6%2)== 1)
    {
     analogWrite(A5, 255);
   }
    else if((count6%2)==0)
   {
      analogWrite(A5,0);
    }
   }
}

