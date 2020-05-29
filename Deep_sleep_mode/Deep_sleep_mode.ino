const int interruptPin = 0; //GPIO 0 (Flash Button) 
const int LED=4; //On board blue LED 
 
void setup() { 
  Serial.begin(9600); 
  pinMode(LED_BUILTIN,OUTPUT);
  for (int i=0; i<5;i++)
  {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);  
  delay(1000); 
   
  }
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, CHANGE); 
} 
 
void loop() 
{ 
  
     ESP.deepSleep(500000000000e6);
} 
 
//This program get executed when interrupt is occures i.e.change of input state
void handleInterrupt() { 
    Serial.println("Interrupt Detected"); 
}
