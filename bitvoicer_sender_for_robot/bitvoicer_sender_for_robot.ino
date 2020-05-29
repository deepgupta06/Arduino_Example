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
    
    mySerial.write("wake up");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  if (bitVoicer.strData == "for")
  {
    
    mySerial.write("for");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  if (bitVoicer.strData == "backward")
  {
    
    mySerial.write("backward");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  if (bitVoicer.strData == "left")
  {
    
    mySerial.write("left");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  if (bitVoicer.strData == "right")
  {
    
    mySerial.write("right");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  if (bitVoicer.strData == "stop")
  {
    
    mySerial.write("stop");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
   if (bitVoicer.strData == "sleep")
  {
    
    mySerial.write("sleep");
    bitVoicer.strData = "";
    lightLevel = 0;
  }
}
