#include <SPI.h>

#include <SD.h> // preprocessor directives (header files)
#define SDPIN 4
#include <TMRpcm.h>
 
File myFile; // create objects here from library classes
TMRpcm tmrpcm;
 
char mychar; // for reading input from Serial console
 
void setup(){
  Serial.begin(9600);
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
  tmrpcm.setVolume(1);
  if (!SD.begin(SDPIN)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("Type 'a' to play a song.");
}
 
void loop(){
    if(Serial.available()){
      mychar = Serial.read();
      if(mychar == 'a'){ //send the letter a over the serial monitor to start playback
      Serial.println("playing wav");
        tmrpcm.play("01.wav");
      }
      if(mychar == 'b'){ //send the letter a over the serial monitor to start playback
      Serial.println("playing wav");
        tmrpcm.play("2.wav");
      }
      if(mychar == 'c'){ //send the letter a over the serial monitor to start playback
      Serial.println("playing wav");
        tmrpcm.play("3.wav");
      }
    }
}
 
void playSound(char *file){
 tmrpcm.play(file);
 return;
}
