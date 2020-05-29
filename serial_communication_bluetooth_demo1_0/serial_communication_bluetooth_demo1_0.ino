void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
Serial.write('L');
delay(1000);
Serial.write('k');
delay(1000);
}
  
