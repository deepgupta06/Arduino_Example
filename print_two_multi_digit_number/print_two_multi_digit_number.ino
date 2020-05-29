int count1;
int count2;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while (Serial.available()==0);
 if (Serial.available()>0)
 {
   int c = count1++;
   if ((c%2)==0)
   {   
   int a=Serial.parseInt();
 Serial.print(a);
   }
   else if((c%2)==1)
   {
     Serial.print("             ");
 long int b= Serial.parseFloat();
 Serial.println(b);
   }
 
}
}

