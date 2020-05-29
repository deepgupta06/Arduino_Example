int ultraSoundSignal = 7; 
int val = 0; 
int ultrasoundValue = 0; 
int timecount = 0; 
int ledPin = 13; // LED connected to digital pin 13
void setup() {  
Serial.begin(9600);                  // Sets the baud rate to 9600  pinMode(ledPin, OUTPUT);            // Sets the digital pin as output }
void loop() { 
  timecount = 0; 
  val = 0; 
  pinMode(ultraSoundSignal, OUTPUT);
  digitalWrite(ultraSoundSignal, LOW); 
  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input val = digitalRead(ultraSoundSignal); // Append signal value to val while(val == LOW) { // Loop until pin reads a high value  val = digitalRead(ultraSoundSignal); }
while(val == HIGH)  // Loop until pin reads a high value  val = digitalRead(ultraSoundSignal);  timecount = timecount +1;            // Count echo pulse time }
ultrasoundValue = timecount; // Append echo pulse time to ultrasoundValue
serialWrite('A'); // Example identifier for the sensor printInteger(ultrasoundValue); serialWrite(10); serialWrite(13);
if(timecount > 0)
{  
digitalWrite(ledPin, HIGH); }
delay(100); 
}
