int datapin = 2; 
int clockpin = 3;
int latchpin = 4;

void setup()
{
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT); 
  pinMode(latchpin, OUTPUT);
}

void loop()
{
  writeByte(255);
  delay(500);
  writeByte(0);
  delay(500);
}

void writeByte(byte data)
{
  shiftOut(datapin, clockpin, MSBFIRST, data);
  // toggle the latch pin so that the data appears as an output
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}
