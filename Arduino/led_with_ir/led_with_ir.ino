#include <IRremote.h>
 
int RECV_PIN = 3; 
int led1 = 2;
int led2 = 4;
int led3 = 7;
int led4 = 10;

int itsONled[] = {0,0,0,0,0};
/* the initial state of LEDs is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
led to light when the board is powered */
#define code1  33444015 // code received from button 1
#define code2  33478695 // code received from button B
#define code3  33486855
#define code4  33435855


// code received from button C
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  
}
 
void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1:
         if(itsONled[1] == 1) {        // if first led is on then
            digitalWrite(led1, LOW);   // turn it off when button is pressed
            itsONled[1] = 0;           // and set its state as off
         } else {                      // else if first led is off
             digitalWrite(led1, HIGH); // turn it on when the button is pressed
             itsONled[1] = 1;          // and set its state as on
         }
          break; 
       case code2:
         if(itsONled[2] == 1) {
            digitalWrite(led2, LOW);
            itsONled[2] = 0;
         } else {
             digitalWrite(led2, HIGH);
             itsONled[2] = 1;
         }
          break;
       case code3:
         if(itsONled[3] == 1) {
            digitalWrite(led3, LOW);
            itsONled[3] = 0;
         } else {
             digitalWrite(led3, HIGH);
             itsONled[3] = 1;
         }
          break;  
    case code4:
         if(itsONled[4] == 1) {
            digitalWrite(led4, LOW);
            itsONled[4] = 0;
         } else {
             digitalWrite(led4, HIGH);
             itsONled[4] = 1;
         }
          break;        
    }
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
}
