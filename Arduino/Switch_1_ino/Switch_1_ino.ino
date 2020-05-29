int switchpin =8;
int ledpin =13;
boolean lastbutton =LOW;
boolean currentbutton=LOW;
boolean ledon= false;
void setup()
{
  pinMode(switchpin, INPUT);
  pinMode(ledpin, OUTPUT);
}
boolean debounce(boolean last)
{
  boolean current = digitalRead(switchpin);
if (last != current)
{
  delay(10);
  current=digitalRead(switchpin);
}
return current;
}

void loop()
{
  currentbutton = debounce(lastbutton);
  if (digitalRead(switchpin)==HIGH &&lastbutton ==LOW)
  {
    ledon =!ledon;
    //lastbutton =HIGH;
  }
  lastbutton = digitalRead(switchpin);
digitalWrite(ledpin, ledon);
}
