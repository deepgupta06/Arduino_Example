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
{ digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  digitalWrite(latchpin, HIGH);
  delay(1000);
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, B10101010);
  digitalWrite(latchpin, HIGH);
  delay(1000);
}


