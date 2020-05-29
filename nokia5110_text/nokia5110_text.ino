#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(D5, D7, D6, D1, D2);
void setup() {
  Serial.begin(9600);
  display.begin();
  display.setContrast(100);
  display.display();
  delay(2000);
  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  delay(2000);

  // put your setup code here, to run once:

}

void loop() {
  for(int i =
  
  // put your main code here, to run repeatedly:

}
