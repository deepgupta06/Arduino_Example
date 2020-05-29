//Includes the BitVoicer library to the sketch
#include <SoftwareSerial.h>
#include <BitVoicer11.h>
SoftwareSerial mySerial(10, 11);


//Sets up the pins and default variables
int pinR = 13;
int pinY = 5;
int pinG = 6;
int blinkDelay = 250;
int sequenceDir = 0;
int lightLevel = 0;

//Creates a new instance of the BitVoicerSerial class
//Sets up serial port to 0
BitVoicerSerial bitVoicer = BitVoicerSerial();

void setup()
{
  //Starts serial communication and sets up the pinModes
  Serial.begin(9600);
   mySerial.begin(9600);
}
  void loop()
{
  //Retrieves data from serial buffer 
  bitVoicer.getData();
 
  //Quits the loop if no string data was returned from getData
  if (bitVoicer.strData == "")
  {
    return;
  }
 
  //Each of the next 'if' statements performs a different
  //task based on the data received from BitVoicer
  if (bitVoicer.strData == "wake up")
  {
    
    mySerial.write("13");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
}
