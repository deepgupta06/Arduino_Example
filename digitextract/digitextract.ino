void setup() {
  Serial.begin(9600);
   }

void loop() {
  int a = ExtractDigit(120565, 6);
  Serial.println(a);
  delay(1000);
  // put your main code here, to run repeatedly:

}


int ExtractDigit(long int V, int P)
{
  return int(V/(pow(10,P-1))) % 10; 
}
