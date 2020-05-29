//Includes the BitVoicer library to the sketch
#include <BitVoicer11.h>

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
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);
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
  if (bitVoicer.strData == "wake")
  {
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    delay(200);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    delay(200);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "sleep")
  {
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    delay(200);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "RH")
  {
    digitalWrite(pinR, HIGH);
    bitVoicer.strData = "";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "RL")
  {
    digitalWrite(pinR, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "YH")
  {
    digitalWrite(pinY, HIGH);
    bitVoicer.strData = "";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "YL")
  {
    digitalWrite(pinY, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "GH")
  {
    digitalWrite(pinG, HIGH);
    bitVoicer.strData = "";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "GL")
  {
    digitalWrite(pinG, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "blink")
  {
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(blinkDelay);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    delay(blinkDelay);
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "BF")
  {
    blinkDelay = 100;
    bitVoicer.strData = "blink";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "BFF")
  {
    switch (blinkDelay)
    {
      case 500:
        blinkDelay = 250;
        break;
      case 250:
        blinkDelay = 100;
        break;
      default:
        break;
    }
    bitVoicer.strData = "blink";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "BS")
  {
    blinkDelay = 500;
    bitVoicer.strData = "blink";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "BSS")
  {
    switch (blinkDelay)
    {
      case 100:
        blinkDelay = 250;
        break;
      case 250:
        blinkDelay = 500;
        break;
      default:
        break;
    }
    bitVoicer.strData = "blink";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "sequence")
  {
    if (sequenceDir == 0)
    {
      digitalWrite(pinR, HIGH);
      delay(250);
      digitalWrite(pinR, LOW);
      digitalWrite(pinY, HIGH);
      delay(250);
      digitalWrite(pinY, LOW);
      digitalWrite(pinG, HIGH);
      delay(250);
      digitalWrite(pinG, LOW);
    }
    else
    {
      digitalWrite(pinG, HIGH);
      delay(250);
      digitalWrite(pinG, LOW);
      digitalWrite(pinY, HIGH);
      delay(250);
      digitalWrite(pinY, LOW);
      digitalWrite(pinR, HIGH);
      delay(250);
      digitalWrite(pinR, LOW);
    }
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "revert")
  {
    if (sequenceDir == 0)
    {
      sequenceDir = 1;
    }
    else
    {
      sequenceDir = 0;
    }
    bitVoicer.strData = "sequence";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "ALLON")
  {
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    bitVoicer.strData = "";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "ALLOFF")
  {
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "brighter")
  {
    if (lightLevel < 255)
    {
      lightLevel += 85;
      analogWrite(pinR, lightLevel);
      analogWrite(pinY, lightLevel);
      analogWrite(pinG, lightLevel);
    }
    bitVoicer.strData = "";
  }
  else if (bitVoicer.strData == "darker")
  {
    if (lightLevel > 0)
    {
      lightLevel -= 85;
      analogWrite(pinR, lightLevel);
      analogWrite(pinY, lightLevel);
      analogWrite(pinG, lightLevel);
    }
    bitVoicer.strData = "";
  }
  else
  {
    Serial.println("ERROR:" + bitVoicer.strData);
    bitVoicer.strData = "";
  }
}
