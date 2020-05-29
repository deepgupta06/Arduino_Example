int nowhour=20,nowminuts=41;
int alarmhour=20, alarmminuts=42;
long int afteralarm;

void setup() {
  Serial.begin(9600);
  afteralarm = ((nowhour - alarmhour)*3600000)+((nowminuts-alarmminuts)*60000);
  Serial.println(abs(afteralarm));
  // put your setup code here, to run once:

}

void loop() {
  delay(1000);
  int count=0;
      count++;
  // put your main code here, to run repeatedly:

}
