unsigned long serialdata;
int inbyte;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  getSerial();
}

long getSerial()
{
  serialdata = 0;
  while (inbyte != '/')
  {
    inbyte = Serial.read();  
    if (inbyte > 0 && inbyte != '/')
    { 
      serialdata = serialdata * 10 + inbyte - '0';
      Serial.println(serialdata);
      Serial.flush();
    }
  }
  
  return serialdata;
  inbyte = 0;
  serialdata =0;
}
