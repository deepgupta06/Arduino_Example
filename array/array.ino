int ledPin = 13;            
// LED on pin 10 
byte flicker[] = {180, 0, 255, 0, 10, 90, 0, 60};                                      // above array of 8 
void setup()                         // different values 
{   pinMode(ledPin, OUTPUT);
Serial.begin(9600);// sets OUTPUT pin 
}  
void loop() 
{  
  for(int i=0; i<7; i++)             // loop equals number
  {                                  // of values in array  
  analogWrite(ledPin, flicker[i]);
 Serial.println(); // write index value    
  delay(200);                      // pause 200ms   
}
  }
