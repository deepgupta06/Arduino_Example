/////////////////////////////////////////////////
/////Change as per your pin configuration////////
/////////////////////////////////////////////////


#define lm1 2
#define lm2 3
#define rm1 4
#define rm2 5
#define left_sensor 7
#define right_sensor 8

void setup() 
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(left_sensor, INPUT);
  pinMode(right_sensor, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{
  if(digitalRead(left_sensor)== HIGH)
  {
    left();
  }
  else if (digitalRead(right_sensor)==HIGH)
  {
    right();
  }
  else
  {
    forward();
  }
 
}



void forward()
{
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
}

void left()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
}
void right()
{
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}

void backward()
{
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
}

