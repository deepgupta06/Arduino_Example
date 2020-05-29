/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
float a;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(180);// attaches the servo on pin 9 to the servo object
a = 0;
}

void loop() {
  while (Serial.available()==0);
     a=Serial.parseFloat();
    Serial.print(a);
    Serial.print("______");
             // reads the value of the potentiometer (value between 0 and 1023)
  a = map(a, 0, 0,180, 0);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(a);
  Serial.println(a);// sets the servo position according to the scaled value
  delay(150);                           // waits for the servo to get there
}

