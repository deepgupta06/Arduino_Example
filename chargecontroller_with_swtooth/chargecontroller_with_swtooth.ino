
#include <PID_v1.h>
#define PIN_INPUT_current 0
#define PIN_INPUT_voltage 1
float r1 =30000;
float r2 = 7500;
float userinputvoltage;
double userinputcurrent;
double Setpoint, Input, Output;
float aggKp = .11, aggKi = .01, aggKd=0;
float consKp = .1, consKi = 0.01, consKd=0;
float Switch;
PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);
int pinout =3;
float amp,frq,c,i,d;


void setup() 
{
  Serial.begin(9600);
 while(Serial.available()==0);
  aggKp = Serial.parseFloat();
  aggKi = Serial.parseFloat();
  consKp = Serial.parseFloat();
  consKi = Serial.parseFloat();
  userinputcurrent = Serial.parseFloat();
  Switch =Serial.parseFloat();
  amp = Serial.parseFloat();
  frq = Serial.parseFloat();
  Input = analogRead(PIN_INPUT_current);
  pinMode(pinout, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Setpoint = ((2.5 - (( userinputcurrent/1000.0)*.085))/0.0048);
   myPID.SetMode(AUTOMATIC);
  
}

void loop() {
  amp = amp+1;
  for ( i =0; i<amp; i++)
  {
    d = frq/amp;
    c = d*i;
  unsigned int x=0;
float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;

  for (int x = 0; x < 150; x++)
  { //Get 150 samples
  AcsValue = analogRead(A0);     
  Samples = Samples + AcsValue; 
 }
AvgAcs=Samples/150;
AcsValueF = ((2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.085)*1000;
 Input = analogRead(PIN_INPUT_current);
  double gap = abs(Setpoint-Input); //distance away from setpoint
  if (gap < 10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID.SetTunings(consKp, consKi, consKd);
  }
  else
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID.SetTunings(aggKp, aggKi, aggKd);
  }
    myPID.Compute();
    int finalvalue = c - Output;
    
    if(finalvalue < 0)
    {
      digitalWrite(pinout, HIGH);
    }
    else if(finalvalue > 0)
    {
      digitalWrite(pinout, LOW);
    }
    
    Serial.println(finalvalue);
        
    //Serial.println(Output);//Serial.println(gap);
    //delay(1000);

}
}
