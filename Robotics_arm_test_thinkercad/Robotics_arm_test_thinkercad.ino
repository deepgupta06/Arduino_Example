#include <Servo.h> 
Servo servo;
int sensorPin0 = A0;
int pos[5]={10,40,80,120};
int q[180];
int count;
void setup()
{
  servo.attach(8);
  Serial.begin(9600);
  arrayint();
  Serial.print(q[180]);
  Serial.println(count+"count");
  
  delay(1000);
}
void loop()
{
  char read =Serial.read();
  if(read=='r')
   
  {
    Serial.println("R");
    record();
    print();
  }
  else if(read=='m')
  {
    Serial.println("m");
    servo.write(map(analogRead(A0),1,1023,1,180));
  }
  if (digitalRead(7)==0)
                {
                  for(int i = 0;i<=count;i++)
                  {
                    int lastpos =q[count];
                    Serial.print("lol");
                    Serial.print(i );
                    Serial.print(q[1]);
                    for(int j= q[i];j<=q[i+1];j++)
                    {
                     servo.write(j);
                      Serial.print("lol2");
                      Serial.print(count);
                      Serial.println(j);
                     delay(10);
                    }
                  }
                  
                }
  while(read=='m')
  {
    Serial.println("m");
    servo.write(map(analogRead(A0),1,1023,1,180));
    
  }
  
                  
  }

void record()
{
    Serial.print("record");
    int val =analogRead(A0);
    val = map(val,1,1023,0,180);
    q[count]=val;
    Serial.println(q[count]);
    servo.write(q[count]);
  Serial.println("count---");
  Serial.println(count);
   
    
      count++;
    
    if(count==180)
    {
      count =0;
    }
  
  
}

void arrayint()
{
  for(int i=0;i <=180;i++)
  {
    q[i]=0;
  }
}
void print()
{
  Serial.print("q[1]=");
  Serial.print(q[1]);
  Serial.print("q[2]=");
  Serial.print(q[2]);
  Serial.print("q[3]=");
  Serial.print(q[3]);
  Serial.print("q[4]=");
  Serial.print(q[4]);
  Serial.print("q[5]=");
  Serial.print(q[5]);
}
