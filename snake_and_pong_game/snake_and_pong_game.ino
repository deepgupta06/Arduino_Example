#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);  //Initialise display object

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

int menuitem = 1;
int page =0;
volatile boolean up = false;
volatile boolean down = false;
volatile boolean middle = false;

int downButtonState = 0;
int upButtonState = 0;  
int selectButtonState = 0;          
int lastDownButtonState = 0;
int lastSelectButtonState = 0;
int lastUpButtonState = 0;

/********* constants *******/
#define PIN_SCE   4
#define PIN_RESET 3
#define PIN_DC    5
#define PIN_SDIN  6
#define PIN_SCLK  7

#define LCD_C     LOW
#define LCD_D     HIGH

#define LCD_X     84
#define LCD_Y     6

int barWidth = 16;
int barHeight = 4;
int ballPerimeter = 4;
unsigned int bar1X = 0;
unsigned int bar1Y = 0;
unsigned int bar2X = 0;
unsigned int bar2Y = LCD_Y * 8 - barHeight;
int ballX = 0;
int ballY = 0;
boolean isBallUp = false;
boolean isBallRight = true;

byte pixels[LCD_X][LCD_Y];
unsigned long lastRefreshTime;
const int refreshInterval = 150;
byte gameState = 1;
byte ballSpeed = 2;
byte player1WinCount = 0;
byte player2WinCount = 0;
byte hitCount = 0;





#define LEFT 8
#define DOWN 9
#define RIGHT 10
#define UP 11
#define OK 12
#define MAX_WIDTH 84        //display 84x48
#define MAX_HEIGHT 48
#define speakerPin 2

boolean dl=false,dr=false,du=false,dd=false;   // to check in which direction the snake is currently moving

int x[200],y[200],i,slength,tempx=10,tempy=10,xx,yy;
unsigned int high;
uint8_t bh,bl;
int xegg,yegg;
int freq,tb;
int l,r,u,d,p;
unsigned long time=280,beeptime=50;
int score=0,flag=0;

 

void setup()
{
  Serial.begin(9600);         //Begin Serial Communication
  display.begin();
  display.clearDisplay();
  
  
  
  pinMode(LEFT,INPUT);         //Directional keys and pause
  pinMode(RIGHT,INPUT);
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(OK,INPUT);
  
  pinMode(speakerPin,OUTPUT);  //Buzzer pin
  
  digitalWrite(LEFT,HIGH);     //Active low keys
  digitalWrite(RIGHT,HIGH);
  digitalWrite(UP,HIGH);
  digitalWrite(DOWN,HIGH);
  digitalWrite(OK,HIGH);
  
  
  display.setContrast(25);
  slength=3;                 //Start with snake length 8
  
  xegg=(display.width())/2;
  
  yegg=(display.height())/2;
  
  display.setTextSize(2);          //Initial Display
  display.setTextColor(BLACK);
  display.setCursor(5,10);
  display.print("yobots");
  display.setCursor(10,40);
  display.print("....");
  display.display();
  delay(4000);
  display.clearDisplay();

}


//Movement Begins after here
void loop()   
{

  drawMenu();
   downButtonState = digitalRead(DOWN);
  selectButtonState = digitalRead(OK);
  upButtonState =   digitalRead(UP);
  checkIfDownButtonIsPressed();
  checkIfUpButtonIsPressed();
  checkIfSelectButtonIsPressed();
    for(i=0;i<=slength;i++)      //Set starting coordinates of snake
  {
    x[i]=25-3*i;
    y[i]=10;   
  }
  
  for(i=0;i<slength;i++)         //Draw the snake
     {
     display.drawCircle(x[i],y[i],2,BLACK);
     }
     display.display();

dr=true;    //Going to move right initially



  if (up &&  page ==1)
  {
    up = false;
    menuitem--;
    if (menuitem ==0)
    {
      menuitem =4;
    }
     if (down && page == 1) {
    down = false;
    menuitem++;
    if (menuitem==3) 
    {
      menuitem=2;
    }      
  }
}  
}


 
void movesnake()
{
  l=digitalRead(LEFT);      //Continuously Check the Keys
  d=digitalRead(DOWN);
  r=digitalRead(RIGHT);
  u=digitalRead(UP);
  p=digitalRead(OK);
  

if(flag==0)
{
direct();    //When key is pressed,this will change the coordinates accordingly and set flag to 1 
             //flag would be set to 1 so that direction is not changed multiple times in a short duration
}




  if(millis()%time==0)     //this condition becomes true after every 'time' milliseconds...millis() returns the time since launch of program
{
       
       
     if(flag==0)                                   //flag 0 means no directional key has been pressed in the last 'time' milliseconds
     {
       if(dr==true){tempx=x[0]+3;tempy=y[0];}      // so the snake moves one step in the direction it is moving currently
       if(dl==true){tempx=x[0]-3;tempy=y[0];}      //The new coordinates of head of snake goes in tempx,tempy
       if(du==true){tempy=y[0]-3;tempx=x[0];}
       if(dd==true){tempy=y[0]+3;tempx=x[0];}
     }
   
   flag=0;  
     checkgame();                              //Check if snake has met egg or coincided with itself
      checkegg();
      
 if(tempx<=0){tempx=84+tempx;}     //If the new coordinates are out of screen, set them accordingly
 if(tempx>=84){tempx=tempx-84;}
 if(tempy<=0){tempy=48+tempy;}
 if(tempy>=48){tempy=tempy-48;}

 for(i=0;i<=slength;i++)        //Change the coordinates of all points of snake
  {
   xx=x[i];
   yy=y[i]; 
   x[i]=tempx;
   y[i]=tempy;
   tempx=xx;
   tempy=yy;
  }
  
drawsnake();           //Draw the snake and egg at the new coordinates
}
}


void checkgame()       //Game over checker
{
  for(i=1;i<slength;i++)               //Checking if the coordinates of head have become equal to one of the non head points of snake
  {
    if(x[i]==x[0] && y[i]==y[0])
    {
      
      bh=EEPROM.read(1);
      bl=EEPROM.read(0);
      high=(((0xff00+bh)<<8) + bl);
      
      if(score>high)
      {
        high=score;
        bh=(high >> 8);
        bl=high & 0xff;
        
        EEPROM.write(1,bh);
        EEPROM.write(0,bl);
      }
      
      display.clearDisplay();
      display.setTextColor(BLACK);       
      display.setTextSize(1);
      display.setCursor(20,12);
      display.print("Game Over");
      display.setCursor(15,30);
      display.print("Score: ");
      display.print(score);
      display.setCursor(15,40);
      display.print("High: ");
      display.print(high);
      
      display.display();
      beep(20,5000);
      
      
      display.clearDisplay();
      
      slength=8;              //Resetting the values
      score=0;
      time=280;
      
      redraw();              //Restart game by drawing snake with the resetted length and score
    }
  }

}

void checkegg()      //Snake meets egg
{
  if(x[0]==xegg or x[0]==(xegg+1) or x[0]==(xegg+2) or x[0]==(xegg-1))      //Snake in close vicinity of egg
  {
    if(y[0]==yegg or y[0]==(yegg+1) or y[0]==(yegg+2) or y[0]==(yegg-1))
    {
      score+=1;                       //Increase length,score and increase movement speed by decreasing 'time'
      slength+=1;
      if(time>=90)
      {time-=20;}
      
      display.fillRect(xegg,yegg,3,3,WHITE);      //Delete the consumed egg
      
      display.display();
      
      
      beep(35,beeptime);              //Beep with a sound of 35Hz for 'beeptime' ms
      xegg=random(1,80);              //Create New egg randomly
      yegg=random(1,40);
    }
  }
}  
     
      
void direct()                  //Check if user pressed any keys and change direction if so
{
  if(l==LOW and dr==false)       //when key LEFT is pressed ,L will become low
  {
    dl=true;du=false;dd=false;
    tempx=x[0]-3;                //Save the new coordinates of head in tempx,tempy
    tempy=y[0];
    flag=1;                     //Do not change direction any further for the ongoing 'time' milliseconds
  }  
  else if(r==LOW and dl==false)
  {
    dr=true;du=false;dd=false;
    tempx=x[0]+3;
    tempy=y[0];
    flag=1;
  }  
  else if(u==LOW and dd==false)
  {
    du=true;dl=false;dr=false;
    tempy=y[0]-3;
    tempx=x[0];
    flag=1;
  }  
  else if(d==LOW and du==false)
  {
    dd=true;dl=false;dr=false;
    tempy=y[0]+3;
    tempx=x[0];
    flag=1;
  } 
  else if(p==LOW)               //Pause game for 5 seconds
  {
  display.clearDisplay();
  
  display.setTextColor(BLACK);
  for(i=5;i>0;i--)
    {
     display.setCursor(25,10); 
     display.setTextSize(1);
     display.print("PAUSED");
     display.setCursor(40,30);
     display.print(i);
     display.display();
     delay(1000);
     display.clearDisplay();
    } 
    redraw();          //Redraw the snake and egg at the same position as it was 
  } 
}


void drawsnake()        //Draw snake and egg at newly changed positions
{
  display.fillRect(xegg,yegg,3,3,BLACK);       //Draw egg at new pos
  
  display.drawCircle(x[0],y[0],2,BLACK);       //Draw new head of snake
  display.drawCircle(x[slength],y[slength],2,WHITE);   //Delete old tail of snake
  
  display.display();
        
}

void redraw()   //Redraw ALL POINTS of snake and egg
{
  display.fillRect(xegg,yegg,3,3,BLACK);
  for(i=0;i<slength;i++)
     {
     display.drawCircle(x[i],y[i],2,BLACK);
     
     }
     display.display();
}     
     
     
     
void beep (int freq,long tb)           //This function creates a sound of frequency 'freq' Hz and for a duration of 'tb' milliseconds
{ 
    int x;    
    long delayAmount = (long)(500/freq);       //Calculate time duration of half cycle
    long loopTime = (long)(tb/(delayAmount*2));   //Calculate no. of cycles
    for (x=0;x<loopTime;x++)   // One iteration produces sound for one cycle
    {    
        digitalWrite(speakerPin,HIGH);   //High for half cycle
        delay(delayAmount);
        digitalWrite(speakerPin,LOW);    //Low for half cycle
        delay(delayAmount);
    }    
    
    delay(2);
    //a little delay to make all notes sound separate
}      






void restartGame(){
   ballSpeed = 1;
   gameState = 1;
   ballX = random(0, 60);
   ballY = 20;
   isBallUp = false; 
   isBallRight = true;
   hitCount = 0;
}

void refreshScreen(){
  if(gameState == 1){
    for(int y = 0; y < LCD_Y; y++){
        for(int x = 0; x < LCD_X; x++){
           byte pixel = 0x00;
           int realY = y * 8;
           // draw ball if in the frame
           if(x >= ballX && x <= ballX + ballPerimeter -1 && ballY + ballPerimeter > realY && ballY < realY + 8 ){
             byte ballMask = 0x00;
             for(int i = 0; i < realY + 8 - ballY; i++){
               ballMask = ballMask >> 1;
               if(i < ballPerimeter)
                 ballMask = 0x80 | ballMask;
             }
             pixel = pixel | ballMask;
           }
           
           // draw bars if in the frame
           if(x >= bar1X && x <= bar1X + barWidth -1 && bar1Y + barHeight > realY && bar1Y < realY + 8 ){
             byte barMask = 0x00;
             for(int i = 0; i < realY + 8 - bar1Y; i++){
               barMask = barMask >> 1;
               if(i < barHeight)
                 barMask = 0x80 | barMask;
             }
             pixel = pixel | barMask;
           }
           
           if(x >= bar2X && x <= bar2X + barWidth -1 && bar2Y + barHeight > realY && bar2Y < realY + 8 ){
             byte barMask = 0x00;
             for(int i = 0; i < realY + 8 - bar2Y; i++){
               barMask = barMask >> 1;
               if(i < barHeight)
                 barMask = 0x80 | barMask;
             }
             pixel = pixel | barMask;
           }
           LcdWrite(LCD_D, pixel);
         }
    }
  } else if(gameState == 2){
      
  }
}

void update()
{
  if(gameState == 1){
     int barMargin = LCD_X;
     int pot1 = analogRead(A0); //read potentiometers and set the bar positions
     int pot2 = analogRead(A1);
     bar1X = (pot1) / 2 * LCD_X / 512;
     bar2X = pot2 / 2 * LCD_X / 512;
    
     if(bar1X > barMargin) bar1X = barMargin;
     if(bar2X > barMargin) bar2X = barMargin;
     
     //move the ball now
     if(isBallUp)
       ballY -= ballSpeed;
     else
       ballY += ballSpeed;
     if(isBallRight)
       ballX += ballSpeed;
     else
       ballX -= ballSpeed;
     //check collisions  
     if(ballX < 1){
       isBallRight = true;
       ballX = 0;
     }
     else if(ballX > LCD_X - ballPerimeter - 1){
       isBallRight = false;
       ballX = LCD_X - ballPerimeter;
     }
     if(ballY < barHeight){
       if(ballX + ballPerimeter >= bar1X && ballX <= bar1X + barWidth){ // ball bounces from bar1
         isBallUp = false;
         if(ballX + ballPerimeter/2 < bar1X + barWidth/2)
           isBallRight = false;
         else
           isBallRight = true;
         ballY = barHeight;
         if(++hitCount % 10 == 0 && ballSpeed < 5) 
           ballSpeed++;
       }else{ //player2 wins
         gameState = 2;
         player2WinCount++;
       }
     }
     if(ballY + ballPerimeter > LCD_Y * 8 - barHeight){
       if(ballX + ballPerimeter >= bar2X && ballX <= bar2X + barWidth){ //ball bounces from bar2
         isBallUp = true; 
         if(ballX + ballPerimeter/2 < bar2X + barWidth/2)
           isBallRight = false;
         else
           isBallRight = true;
         ballY = LCD_Y * 8 - barHeight - ballPerimeter;
         if(++hitCount % 10 == 0 && ballSpeed < 5) 
           ballSpeed++;
       }else{ // player 1 wins
         gameState = 2;
         player1WinCount++;
       }
     }
  }else if(gameState == 2){
      for(int i =0; i < 4; i++){
        LcdWrite(LCD_C, 0x0D );  // LCD in inverse mode.
        delay(300);
        LcdWrite(LCD_C, 0x0C );  // LCD in inverse mode.
        delay(300);
      }
      restartGame();
  }  
}

void LcdInitialise(void){
  pinMode(PIN_SCE, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_DC, OUTPUT);
  pinMode(PIN_SDIN, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);
  delay(200);
  digitalWrite(PIN_RESET, LOW);
  delay(500);
  digitalWrite(PIN_RESET, HIGH);
  LcdWrite(LCD_C, 0x21 );  // LCD Extended Commands.
  LcdWrite(LCD_C, 0xB1 );  // Set LCD Vop (Contrast). 
  LcdWrite(LCD_C, 0x04 );  // Set Temp coefficent. //0x04
  LcdWrite(LCD_C, 0x14 );  // LCD bias mode 1:48. //0x13
  LcdWrite(LCD_C, 0x0C );  // LCD in normal mode.
  LcdWrite(LCD_C, 0x20 );
  LcdWrite(LCD_C, 0x80 ); //select X Address 0 of the LCD Ram
  LcdWrite(LCD_C, 0x40 ); //select Y Address 0 of the LCD Ram - Reset is not working for some reason, so I had to set these addresses
  LcdWrite(LCD_C, 0x0C );
}

void LcdWrite(byte dc, byte data){
  digitalWrite(PIN_DC, dc);
  digitalWrite(PIN_SCE, LOW);
  shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
  digitalWrite(PIN_SCE, HIGH);
}

void checkIfDownButtonIsPressed()
  {
    if (downButtonState != lastDownButtonState) 
  {
    if (downButtonState == 0) 
    {
      down=true;
    }
    delay(50);
  }
   lastDownButtonState = downButtonState;
  }   

void checkIfUpButtonIsPressed()
{
  if (upButtonState != lastUpButtonState) 
  {
    if (upButtonState == 0) {
      up=true;
    }
    delay(50);
  }
   lastUpButtonState = upButtonState;
}

void checkIfSelectButtonIsPressed()
{
   if (selectButtonState != lastSelectButtonState) 
  {
    if (selectButtonState == 0) {
      middle=true;
    }
    delay(50);
  }
   lastSelectButtonState = selectButtonState;
}

void drawMenu()
  {
    
  if (page==1) 
  {    
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(15, 0);
    display.print("SELECT GAME");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0, 15);
   
    if (menuitem==1) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }
    display.print(">SNAKE");
    display.setCursor(0, 25);
   
    if (menuitem==2) 
    {
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }    
    display.print(">PONG ");
    
    display.display();
  }
    
       
 
  else if (page==2) 
  {
   // drawsnake();
    
  }
  }
  
  

 
  
  
