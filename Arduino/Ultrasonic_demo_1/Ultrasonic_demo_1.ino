#include <Boards.h>
#include <Firmata.h>
/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

#define TRIGGER_PIN1  8
#define ECHO_PIN1     9
#define TRIGGER_PIN2  10
#define ECHO_PIN2     11
#define TRIGGER_PIN3  12
#define ECHO_PIN3     13

Ultrasonic ultrasonic1(TRIGGER_PIN1, ECHO_PIN1);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);
Ultrasonic ultrasonic3(TRIGGER_PIN3, ECHO_PIN3);
void setup()
  {
  Serial.begin(9600);
  }

void loop()
  {
  float cmMsec1,cmMsec2,cmMsec3;
  long microsec = ultrasonic1.timing();

  cmMsec1 = ultrasonic1.convert(microsec, Ultrasonic::CM);
  cmMsec2 = ultrasonic2.convert(microsec, Ultrasonic::CM);
  cmMsec3 = ultrasonic3.convert(microsec, Ultrasonic::CM);
  
  
  Serial.print(" CM1: ");
  Serial.print(cmMsec1);
  Serial.print(", CM2: ");
  Serial.print(cmMsec2);
  Serial.print(", CM3: ");
  Serial.println(cmMsec3); 
  delay(1000);
  }
