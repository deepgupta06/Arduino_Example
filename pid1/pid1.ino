double kp = .01, ki = 0.0000001, dt = 0.001;
double userinputcurrent = 400; 
double pController,iController,Output,Input, Setpoint, Error,voltage,userinputvoltage;
float current;      


void setup() {
Serial.begin(9600);
pinMode(3 ,OUTPUT);
Setpoint = ((2.5 - ((userinputcurrent/100)*0.065))/0.0048);

}

void loop() {
  unsigned int x=0;
  float currentsensorvalue = 0.0;
  float avgsensorvalue =0.0;
  float sample =0.0;

   for(int x =0; x < 150; x++)
   {
    currentsensorvalue = analogRead(A0);
    sample = sample + currentsensorvalue; 
   }
   avgsensorvalue = sample/150;
   current = (((2.5 - (avgsensorvalue * (5.0/1024.0)))/0.065)*1000)-90;
   Input = analogRead(A0);
   Error = abs(Setpoint - Input);
   pController = kp*dt;
   iController += iController + Error;
   Output = (pController + (ki*iController*dt));
   
   if (Output > 255)
   {
    Output =255;
   }
   else  if (Output <0)
   {
    Output = 0 ;
   }
   analogWrite(3, Output);
   Serial.println(Output);
   delay(1);
   
   
   
   

}
