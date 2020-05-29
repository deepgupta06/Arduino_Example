void setup() {
  
 Serial.begin(9600);
 pinMode(10, OUTPUT);
 
 
 // put your setup code here, to run once:

}

void loop() {
//while (Serial.available()==0);
while (Serial.available()==0);
int i =Serial.read();
 Serial.println(i);
 analogWrite(10, i);
 Serial.flush();


//delay// put your main code here, to run repeatedly:
//Serial.flush();
}
