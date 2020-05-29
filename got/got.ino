int ledred = 9;           // the pin that the LED is attached to
int ledblue = 10;
int ledgreen = 11;
int brightness = 255;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
 
// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(A0, OUTPUT);
}
 
// the loop routine runs over and over again forever:
 
void loop (){
 
 
 
//G3
analogWrite(ledred, 255);
analogWrite(ledblue, 255);
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
////////////////////////////////ONE
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
////////////////////////////////TWO
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
//////////////////////////////THREE
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////FOUR
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////FIVE
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);
tone(A0, 131, 375);
delay(400);
 
//E3
analogWrite(ledblue, 255);
tone(A0, 165, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////SIX
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
//////////////////////////////SEVEN
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//E3
analogWrite(ledblue, 255);
tone(A0, 165, 175);
delay(200);
analogWrite(ledblue, LOW);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
analogWrite(ledred, LOW);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
//////////////////////////////EIGHT
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
/////////////////////////////////////////////////CHORUS1////////////////////////////////////////////
 
 
//G4  
analogWrite(ledred, 255);
tone(A0, 392, 1175);
delay(1200);
analogWrite(ledred, LOW);
 
//C4
analogWrite(ledblue, 255);
tone(A0, 262, 1175);
delay(1200);
analogWrite(ledblue, LOW);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 175);
delay(200);
 
//F4
analogWrite(ledblue, 255);
tone(A0, 349, 175);
delay(200);
 
//G4
analogWrite(ledgreen, 255);
tone(A0, 392, 775);
delay(800);
 
//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 262, 775);
delay(800);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 175);
delay(200);
 
//F4
analogWrite(ledblue, 255);
tone(A0, 349, 175);
delay(200);
 
//////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;
 
 
 
 
 
//F4
analogWrite(ledred, 255);
tone(A0, 349, 1175);
delay(1200);
analogWrite(ledred, LOW);
 
//AS4
analogWrite(ledblue, 255);
tone(A0, 233, 1175);
delay(1200);
analogWrite(ledblue, LOW);
 
//D4
analogWrite(ledred, 255);
tone(A0, 294, 175);
delay(200);
 
//DS4
analogWrite(ledblue, 255);
tone(A0, 311, 175);
delay(200);
 
//F4
analogWrite(ledgreen, 255);
tone(A0, 349, 775);
delay(800);
 
//AS3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 233, 775);
delay(800);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 175);
delay(200);
 
//D4
analogWrite(ledblue, 255);
tone(A0, 294, 175);
delay(200);
 
//////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////////////////////////CHORUS2////////////////////////////////////////////
 
 
//G5  
analogWrite(ledred, 255);
tone(A0, 392, 1175);
delay(1200);
analogWrite(ledred, LOW);
 
//C4
analogWrite(ledblue, 255);
tone(A0, 262, 1175);
delay(1200);
analogWrite(ledblue, LOW);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 175);
delay(200);
 
//F4
analogWrite(ledblue, 255);
tone(A0, 349, 175);
delay(200);
 
//G4
analogWrite(ledgreen, 255);
tone(A0, 392, 775);
delay(800);
 
//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 262, 775);
delay(800);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 175);
delay(200);
 
//F4
analogWrite(ledblue, 255);
tone(A0, 349, 175);
delay(200);
 
//////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;
 
//////////////////////////////////////////
 
//F4
analogWrite(ledred, 255);
tone(A0, 349, 1175);
delay(1200);
analogWrite(ledred, LOW);
 
//AS4
analogWrite(ledblue, 255);
tone(A0, 233, 1175);
delay(1200);
analogWrite(ledblue, LOW);
 
//D4
analogWrite(ledred, 255);
tone(A0, 294, 175);
delay(200);
 
//DS4
analogWrite(ledblue, 255);
tone(A0, 311, 175);
delay(200);
 
//F4
analogWrite(ledgreen, 255);
tone(A0, 349, 775);
delay(800);
 
//AS3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 233, 775);
delay(800);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 175);
delay(200);
 
//D4
analogWrite(ledblue, 255);
tone(A0, 294, 175);
delay(200);
 
//////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////////////////////////CHORUS3////////////////////////////////////////////
 
 
//G5  
analogWrite(ledred, 255);
tone(A0, 784, 1175);
delay(1200);
analogWrite(ledred, LOW);
 
//C5
analogWrite(ledblue, 255);
tone(A0, 523, 1175);
delay(1200);
analogWrite(ledblue, LOW);
 
//DS5
analogWrite(ledred, 255);
tone(A0, 622, 175);
delay(200);
 
//F5
analogWrite(ledblue, 255);
tone(A0, 698, 175);
delay(200);
 
//G5
analogWrite(ledgreen, 255);
tone(A0, 784, 775);
delay(800);
 
//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 523, 775);
delay(800);
 
//DS5
analogWrite(ledred, 255);
tone(A0, 622, 175);
delay(200);
 
//F5
analogWrite(ledblue, 255);
tone(A0, 698, 175);
delay(200);
 
//////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;
 
 
////////////////////////////////
 
 
//F5
analogWrite(ledred, 255);
tone(A0, 698, 1175);
delay(1200);
analogWrite(ledred, LOW);
 
//AS4
analogWrite(ledblue, 255);
tone(A0, 466, 1175);
delay(1200);
analogWrite(ledblue, LOW);
 
//D5
analogWrite(ledred, 255);
tone(A0, 587, 575);
delay(600);
 
//DS5
analogWrite(ledblue, 255);
tone(A0, 622, 575);
delay(600);
 
//D5
analogWrite(ledgreen, 255);
tone(A0, 587, 575);
delay(600);
 
//AS4
tone(A0, 466, 575);
delay(600);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////////////////////
 
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;
 
 
 
//////////////////////////////////////////////////////////////////////////////////////////
 
//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 523, 375);
delay(400);
 
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////
 
//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 523, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
///////////////////////////////////////////
 
//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 466, 375);
delay(400);
 
//D3
analogWrite(ledred, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledgreen, 255);
tone(A0, 175, 375);
delay(400);
 
/////////
 
//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 466, 375);
delay(400);
 
//D3
analogWrite(ledred, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledgreen, 255);
tone(A0, 175, 375);
delay(400);
 
 
//////////////////////////////////////////
 
//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 415, 375);
delay(400);
 
//C3
analogWrite(ledred, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledblue, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledgreen, 255);
tone(A0, 156, 375);
delay(400);
 
//////////
 
//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 415, 375);
delay(400);
 
//C3
analogWrite(ledred, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledblue, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledgreen, 255);
tone(A0, 156, 375);
delay(400);
 
 
/////////////////////////////////////////
 
//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 392, 375);
delay(400);
 
//AS2
analogWrite(ledred, 255);
tone(A0, 117, 175);
delay(200);
 
//C3
analogWrite(ledblue, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledgreen, 255);
tone(A0, 147, 375);
delay(400);
 
///////////
 
//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 392, 375);
delay(400);
 
//AS2
analogWrite(ledred, 255);
tone(A0, 117, 175);
delay(200);
 
//C3
analogWrite(ledblue, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledgreen, 255);
tone(A0, 147, 375);
delay(400);
 
 
/////////////////////////////////////////
 
//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 311, 375);
delay(400);
 
//G2
analogWrite(ledblue, 255);
tone(A0, 98, 175);
delay(200);
 
//GS2
analogWrite(ledgreen, 255);
tone(A0, 104, 175);
delay(200);
 
//AS2
analogWrite(ledred, 255);
tone(A0, 117, 375);
delay(400);
 
///////////
 
//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 311, 375);
delay(400);
 
//G2
analogWrite(ledblue, 255);
tone(A0, 98, 175);
delay(200);
 
//GS2
analogWrite(ledgreen, 255);
tone(A0, 104, 175);
delay(200);
 
//AS2
analogWrite(ledred, 255);
tone(A0, 117, 375);
delay(400);
 
 
//////////////////////////////////////////
 
//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 311, 375);
delay(400);
 
//G2
analogWrite(ledblue, 255);
tone(A0, 98, 175);
delay(200);
 
//G2
analogWrite(ledred, 255);
tone(A0, 98, 175);
delay(200);
 
//DS4
analogWrite(ledgreen, 255);
tone(A0, 311, 375);
delay(400);
 
//F4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 349, 775);
delay(400);
 
//GS2
analogWrite(ledblue, 255);
tone(A0, 104, 175);
delay(200);
 
//GS2
analogWrite(ledgreen, 255);
tone(A0, 104, 175);
delay(200);
 
//F4
analogWrite(ledred, 255);
tone(A0, 349, 375);
delay(400);
 
//////////////////////////////////////////
 
//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 262, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
 
//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 523, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////
 
//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
analogWrite(ledblue, 255);
tone(A0, 523, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
 
///////////////////////////////////////////
 
//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 466, 375);
delay(400);
 
//D3
analogWrite(ledred, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledgreen, 255);
tone(A0, 175, 375);
delay(400);
 
/////////
 
//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 466, 375);
delay(400);
 
//D3
analogWrite(ledred, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledgreen, 255);
tone(A0, 175, 375);
delay(400);
 
 
//////////////////////////////////////////
 
//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 415, 375);
delay(400);
 
//C3
analogWrite(ledred, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledblue, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledgreen, 255);
tone(A0, 156, 375);
delay(400);
 
//////////
 
//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 415, 375);
delay(400);
 
//C3
analogWrite(ledred, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledblue, 255);
tone(A0, 147, 175);
delay(200);
 
//DS3
analogWrite(ledgreen, 255);
tone(A0, 156, 375);
delay(400);
 
 
/////////////////////////////////////////
 
//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 392, 375);
delay(400);
 
//AS2
analogWrite(ledred, 255);
tone(A0, 117, 175);
delay(200);
 
//C3
analogWrite(ledblue, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledgreen, 255);
tone(A0, 147, 375);
delay(400);
 
///////////
 
//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 392, 375);
delay(400);
 
//AS2
analogWrite(ledred, 255);
tone(A0, 117, 175);
delay(200);
 
//C3
analogWrite(ledblue, 255);
tone(A0, 131, 175);
delay(200);
 
//D3
analogWrite(ledgreen, 255);
tone(A0, 147, 375);
delay(400);
 
 
/////////////////////////////////////////
 
//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 311, 375);
delay(400);
 
//G2
analogWrite(ledred, 255);
tone(A0, 98, 175);
delay(200);
 
//GS2
analogWrite(ledblue, 255);
tone(A0, 104, 175);
delay(200);
 
//AS2
analogWrite(ledgreen, 255);
tone(A0, 117, 375);
delay(400);
 
///////////
 
//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 311, 375);
delay(400);
 
//G2
analogWrite(ledred, 255);
tone(A0, 98, 175);
delay(200);
 
//GS2
analogWrite(ledblue, 255);
tone(A0, 104, 175);
delay(200);
 
//AS2
analogWrite(ledgreen, 255);
tone(A0, 117, 375);
delay(400);
 
 
//////////////////////////////////////////
 
//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 311, 775);
delay(800);
 
//DS4
analogWrite(ledred, 255);
tone(A0, 311, 375);
delay(400);
 
//D4
analogWrite(ledred, LOW);
tone(A0, 294, 775);
delay(800);
 
//D4
analogWrite(ledblue, 255);
tone(A0, 294, 375);
delay(400);
 
//////////////////////////////////////////
 
//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 262, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
/////////////
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
////////////
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
///////////////
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS3
analogWrite(ledblue, 255);
tone(A0, 156, 175);
delay(200);
 
//F3
analogWrite(ledred, 255);
tone(A0, 175, 175);
delay(200);
 
//G3
analogWrite(ledgreen, 255);
tone(A0, 196, 375);
delay(400);
 
////////////////////////////////////////////////
 
//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(A0, 131, 375);
delay(400);
 
//DS5
analogWrite(ledblue, 255);
tone(A0, 622, 175);
delay(200);
 
//F5
analogWrite(ledred, 255);
tone(A0, 698, 175);
delay(200);
 
//G5
analogWrite(ledgreen, 255);
tone(A0, 784, 375);
delay(400);
 
/////////////////////////////////////////////////
 
//C5
analogWrite(ledgreen, 255);
tone(A0, 523, 375);
delay(400);
 
//DS5
analogWrite(ledred, LOW);
tone(A0, 622, 175);
delay(200);
 
//F5
analogWrite(ledgreen, LOW);
tone(A0, 698, 175);
delay(200);
 
//G5
analogWrite(ledblue, LOW);
tone(A0, 784, 375);
delay(400);
 
/////////////////////////////////////////////////
 
//C5
analogWrite(ledgreen, 255);
tone(A0, 523, 375);
delay(400);
 
//DS5
analogWrite(ledblue, 255);
tone(A0, 622, 175);
delay(200);
 
//F5
analogWrite(ledred, 255);
tone(A0, 698, 175);
delay(200);
 
//G5
analogWrite(ledgreen, 255);
tone(A0, 784, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;
 
delay(3000);
 
}
