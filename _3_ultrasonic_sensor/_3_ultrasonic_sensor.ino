#define trigPinf 8
#define echoPinf 9
#define trigPinl 10
#define echoPinl 11
#define trigPinr 12
#define echoPinr 13
void setup()
{
  Serial.begin(9600);
 pinMode(trigPinf, OUTPUT);
 pinMode(echoPinf, INPUT);
 pinMode(trigPinl, OUTPUT);
 pinMode(echoPinl, INPUT);
 pinMode(trigPinr, OUTPUT);
 pinMode(echoPinr, INPUT);
}
void loop()
{
int distancef, durationf ,distancel, durationl ,distancer, durationr;
digitalWrite(trigPinf, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPinl, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPinr, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPinf, LOW);
digitalWrite(trigPinl, LOW);
digitalWrite(trigPinr, LOW);
durationf = pulseIn(echoPinf, HIGH);
durationl = pulseIn(echoPinl, HIGH);
durationr = pulseIn(echoPinr, HIGH);
distancef= (durationf/2)/29.1;
distancel= (durationl/2)/29.1;
distancer= (durationr/2)/29.1;
Serial.print(distancef);
Serial.print("cm");
Serial.print(distancel);
Serial.print("cm");
Serial.print(distancer);
Serial.println("cm");
delay(1000);
}


