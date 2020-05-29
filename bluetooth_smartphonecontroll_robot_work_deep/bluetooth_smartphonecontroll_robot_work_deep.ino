/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.2.5 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 3.7.1 or later version;
     - for iOS 1.0.7 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 11
#define REMOTEXY_SERIAL_TX 12
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,2,0,0,0,34,0,8,95,2,
  5,39,25,11,47,47,10,31,41,41,
  2,14,31,129,0,7,4,18,6,19,
  3,18,6,8,121,111,98,111,116,115,
  0};
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



//define right motor control pins
#define right_motor_A 4
#define right_motor_B 5
 //enable pin

//define left motor control pins
#define left_motor_A 2
#define left_motor_B 3
 //enable pin

//define two arrays with a list of pins for each motor
uint8_t RightMotor[2] = {right_motor_A, right_motor_B};
uint8_t LeftMotor[2] = {left_motor_A, left_motor_B};

//speed control of motors
void Wheel (uint8_t * motor, int v) // v = motor speed, motor = pointer to an array of pins 
{
  if (v > 100) v=100;
  if (v < -100) v=-100;
  if (v > 0){

    digitalWrite (motor [0], HIGH);
    digitalWrite (motor [1], LOW);
    
  }
  else if ( v<0 ){

    digitalWrite (motor [0], LOW);
    digitalWrite (motor [1], HIGH);
    
  }
  else{
    digitalWrite (motor [0], LOW);
    digitalWrite (motor [1], LOW);
    analogWrite (motor [2], 0);
  }
}


void setup() 
{
  RemoteXY_Init (); 
  
   
  //initialization pins
  pinMode (right_motor_A, OUTPUT);
  pinMode (right_motor_B, OUTPUT);
  pinMode (left_motor_A, OUTPUT);
  pinMode (left_motor_B, OUTPUT);
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  
  //manage the right motor
  Wheel (RightMotor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x);
  Wheel (LeftMotor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x);


}


