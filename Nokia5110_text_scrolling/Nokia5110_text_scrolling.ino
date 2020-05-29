#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(D5, D7, D6, D1, D2);

String text;
float count = 1.0;
boolean toggle = false;

static const unsigned char PROGMEM thunderstrom[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x60, 0x03, 0x59, 0x90, 0x0C,
0x80, 0x0C, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x70, 0x00, 0x02, 0x40, 0x1B, 0x06, 0x4D, 0xE4,
0xA2, 0x72, 0x00, 0x52, 0x60, 0x00, 0x3C, 0x60, 0x00, 0x10, 0xF0, 0x00, 0x10, 0x80, 0x00, 0x10,
0xC0, 0x00, 0x10, 0x60, 0x00, 0xA0, 0x50, 0x00, 0xC0, 0x70, 0x00, 0x80, 0x30, 0x07, 0x00, 0x1F,
0x88, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00};



void setup()   {
  //Serial.begin(9600);

  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(55);
  display.setTextSize(1);
  display.setTextWrap(false); // this is very important!
  display.clearDisplay();
  text = "yobots present ";
  textWidth = text.length()*12+85; // get the width of the text
}


void loop() {
  String lol ="jfjytfytfuytfuytfutyfuytfuytfuytfuy"
  textscroll(lol);
 
}



void textscroll(String text)
{
   int  textWidth = text.length()*12+85;
    for(int i=0; i<textWidth; i+=1) 
    {
      display.clearDisplay();
      display.drawRect(0, 0, 84, 48, BLACK);
      display.fillRect(0, 30, 84, 48, BLACK);
      display.drawBitmap(1, 1,  thunderstrom, 24, 24, 1);
      for(int j=0; j<text.length(); j++) 
      {
        display.drawChar((j*12)+85-i,map(j,-100,100,20,40), text[j], WHITE, WHITE, 2);
      }

      display.display();
      delay(50);    
    
  }
  
}

