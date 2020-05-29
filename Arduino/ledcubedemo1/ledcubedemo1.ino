int L1 = 11;
int L2 = 12;
int L3 = 13;
int C1 = 10;
int C2 = 9;
int C3 = 8;
int C4 = 7;
int C5 = 6;
int C6 = 5;
int C7 = 4;
int C8 = 3;
int C9 = 2;
void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);
  pinMode(C9, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, HIGH);
  digitalWrite(C5, HIGH);
  digitalWrite(C6, HIGH);
  digitalWrite(C7, HIGH);
  digitalWrite(C8, HIGH);
  digitalWrite(C9, HIGH);
  delay(1000);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(C2, LOW);
  digitalWrite(C3, LOW);
  digitalWrite(C4, LOW);
  digitalWrite(C5, LOW);
  digitalWrite(C6, LOW);
  digitalWrite(C7, LOW);
  digitalWrite(C8, LOW);
  digitalWrite(C9, LOW);
  delay(1000);
  digitalWrite(C7,HIGH);
  digitalWrite(L3, HIGH);
  delay(1000);
  digitalWrite(C5,HIGH);
  digitalWrite(L1, HIGH);
  delay(1000);

}
