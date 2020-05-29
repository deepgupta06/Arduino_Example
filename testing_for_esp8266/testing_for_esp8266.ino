/*
 * Super Marduino
 * A platform game with Arduino Uno.
 * 
 * Requirements:
 * Nokia 5510 display and three buttons.
 * Additional libraries: Adafruit GFX and Adafruit_PCD8544.
 * 
 * Created by Tobias Beise Ulrich
 * http://tobiasbu.github.io/website 
 * 
 * GitHub:
 * https://github.com/tobiasbu/marduino
 * 
 * 2014-2016.
 * 
 * -------------------------------------
 * LAST UPDATE: 15/06/2016
 * Header information update.
 * 
 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <EEPROM.h>



#include "marduinotypes.h"
#include "tilemap.h"
#include "mariobitmap.h"
#include "levels.h"


Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
TileMap gameTilemap;

#define LEFT 8
#define DOWN 9
#define RIGHT 10
#define UP 11
#define PAUSE 12
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

#define DELAY 75 // delay for fixed update interval 
#define P_STILL 0
#define P_MOVE 1
#define P_JUMP 2
#define P_DEAD 3

#define GAME_INTRO 100
#define GAME_TITLE 101
#define GAME_CREDITS 102
#define GAME_LEVEL 103
#define GAME_PLAY 104
#define GAME_GAMEOVER 105

#define PIN_SCE   4
#define PIN_RESET 3
#define PIN_DC    5
#define PIN_SDIN  6
#define PIN_SCLK  7

#define LCD_C     LOW
#define LCD_D     HIGH

#define LCD_X     84
#define LCD_Y     6

int counter = 1;
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


unsigned int gamestate = GAME_INTRO; // game state
long TIMER_PREV = 0; // timer 
unsigned long TIMER_CURRENT = 0;
//mario img
int const pimagew = 16;
int const pimageh = 16;
//marduino settings
int player_state = P_STILL; //player state 
int player_direction = 1;
int last_direction = 1;
int life = 3;
long playertimer = 0;
long playertimer_prev = 0;
//posicao do mario
Vector2f player_position(0,display.height()-pimageh-8);
Vector2f player_position2(0,display.height()-pimageh-8);
Vector2f last_safe_position(0,display.height()-pimageh-8);
//horizontal speed vars
float hspd = 0;
float hspd_speed = 3.0;
//jump vars and gravity control
float grav = 0.6;
float jumpspd = 4.0;
float vspd = 0;
boolean onAir = false;
boolean check_pulo = false;
//animation vars
int frame = 0;
int frameMax = 4;
float frameSpd = 1;
float frameCounter = 0;
boolean animInit = false;
//collision box offset
float pboxoffsetx = 3; 

// camera control
Vector2f camera = {0,0};
Vector2f last_camera = {0,0};
int camera_player_side = 0;


float sign(float x) {

  if (x > 0)
    return 1;
  else if (x < 0)
    return -1;
  
  return 0;
  
};



boolean buttonPressing[] = {false,false,false}; // button is pressing
boolean buttonRelease[] = {false,false,false}; // button is released
boolean buttonPressed[] = {false,false,false}; // button has pressed one time 
boolean buttonPressedCheck[] = {false,false,false};
boolean buttonReleaseCheck[] = {false,false,false};

void inputManager(unsigned int pin0, unsigned int pin1, unsigned int pin2) {

  //input manager in loop || gerenciador de inputs em loop
  
  int p[3];
  p[0] = digitalRead(pin0);//LÃª o pino 5
  p[1] = digitalRead(pin1);//LÃª o pino 6
  p[2] = digitalRead(pin2);//LÃª o pino 7
  
  for (int i = 0; i < 3; i++) {
  
      if (buttonPressed[i]) { // pressed ok
        buttonPressed[i] = false;
        buttonPressedCheck[i] = true;
      }
      
      if (buttonRelease[i]) { // release ok
        buttonRelease[i] = false;
        buttonReleaseCheck[i] = true;
      }
    
    if (p[i] == LOW) { // arduino check
    
      buttonPressing[i] = true; // pressing button
      
      buttonRelease[i] = false; //turn release off
      buttonReleaseCheck[i] = false;     
    
      if (!buttonPressedCheck[i]) 
        buttonPressed[i] = true;
        
    } else {
      //turn off all
      buttonPressing[i] = false;
      buttonPressed[i] = false;
      buttonPressedCheck[i] = false;
      
      if (!buttonReleaseCheck[i]) //released button!
        buttonRelease[i] = true;
    }
   
  }
 
}


boolean intersectionRect(float * rect1, float * rect2) {
  
  if (rect1[0] < rect2[0] + rect2[2] && rect1[0] + rect1[2] > rect2[0]) {
     if (rect1[1] < rect2[1] + rect2[3] && rect1[3] + rect1[1] > rect2[1]) {
      return true;
    }
  }
  return false;

}

void playerCollisionChecker(float hs, float vs) {

  float playerRect[4] = {player_position.x+pboxoffsetx+hs+camera.x, player_position.y+vs,10,16};
  
  for (int i = 0; i < CollisionMap0Size*4; i += 4) {
  
    float rectTest[] = {pgm_read_word_near(&CollisionMap0[i]), pgm_read_word_near(&CollisionMap0[i+1]), pgm_read_word_near(&CollisionMap0[i+2]), pgm_read_word_near(&CollisionMap0[i+3])};
    
        if (intersectionRect(playerRect,rectTest)) {
          if (hs != 0) {
          
              hspd = (int)hspd;
              player_position.x = (int)player_position.x;
              boolean corrector = false;
    
              while (!corrector) {      
                   
                  playerRect[0] = player_position.x+pboxoffsetx+camera.x+sign(hspd);
                  
                  if (!intersectionRect(playerRect,rectTest))  
                    player_position.x += sign(hspd);
                  else 
                    corrector = true;
              }
              
               hspd = 0;
              
              break;
          }
          
          if (vs != 0) {
             
              vspd = (int)vspd;
              player_position.y = (int)player_position.y;
              boolean correctorY = false;
    
              while (!correctorY) {      
                   
                  playerRect[1] = player_position.y+camera.y+sign(vspd);
                  
                  if (!intersectionRect(playerRect,rectTest))  
                    player_position.y += sign(vspd);
                  else 
                    correctorY = true;
              }
              
               vspd = 0;
               check_pulo = false;
              break;
          }
        }
             
  
  }

}

boolean verifyCollision(float * rect) {

    for (int i = 0; i < CollisionMap0Size*4; i += 4) {
  
      float rectTest[4] = {pgm_read_word_near(&CollisionMap0[i]), pgm_read_word_near(&CollisionMap0[i+1]), pgm_read_word_near(&CollisionMap0[i+2]), pgm_read_word_near(&CollisionMap0[i+3])};
    
        if (intersectionRect(rect,rectTest)) {
               return true;
        }
        
    }
    
    return false;
}

void playerLogic(boolean move_esq, boolean move_dir, boolean jump) {

  //HORIZONTAL MOVEMENT

  if (player_state != P_DEAD) {
  
      hspd = 0;
      boolean moving = false;
     
      if (move_esq == true && move_dir == false) {
          player_direction = 1;
          moving = true;
      } else if (move_dir == true && move_esq == false) {
          player_direction = -1;
          moving = true;
      }
      
      if (moving)
          hspd = hspd_speed * (float)player_direction;
    
      playerCollisionChecker(hspd,0);
      
      player_position2.x += hspd;
      
       if (camera_player_side == -1) {
          if (player_position.x > (display.width()/2)-10)
            camera_player_side = 0;
          else
            player_position.x += hspd;
    
          // screen limit <
          if (player_position.x < 0) {
            player_position.x = 0;
            hspd = 0;
          }  
    
       } else if (camera_player_side == 1) {
          if (player_position.x < (display.width()/2)-10)
            camera_player_side = 0;
          else
            player_position.x += hspd;
            
          // screen limit >
          if (player_position.x > display.width()) {
            gamestate = GAME_TITLE;
            /*player_position.x = display.width()-pimagew;
            hspd = 0;*/
          }
        }
        
        if (camera_player_side == 0) {
          //verify for limit side >
          if (camera.x >= 0 && camera.x <= gameTilemap.getMapWidth()*8-display.width()) {
            camera.x += hspd;
          } if (camera.x > gameTilemap.getMapWidth()*8-display.width()) {
            camera_player_side = 1;
            camera.x = gameTilemap.getMapWidth()*8-display.width();
            player_position.x += hspd;
          } if (camera.x < 0) {
            camera_player_side = -1;
            player_position.x += hspd; 
            camera.x = 0;  
          }
        } 
  
      //VERTICAL MOVEMENT
    
      //gravidade (esta no ar)
     float playerRect[4] = { camera.x+player_position.x+pboxoffsetx,camera.y+player_position.y+1, 10, 16 };
      
      if (!verifyCollision(playerRect)) {
        vspd += grav;
        check_pulo = true;
        onAir = true;
      } else {
        onAir = false;
      }
    
      // checa colisao com chao
      if (vspd != 0) {
          playerCollisionChecker(0,vspd);
      }
      
      if (jump == true && check_pulo == false) {
        vspd -= jumpspd;
        check_pulo = true;  
      }
      
      player_position.y += vspd;
      player_position2.y += vspd;
      
      if (vspd == 0 && !onAir) {
          last_direction = player_direction;
          last_camera.x = camera.x;
          last_camera.y = player_position2.y;
          last_safe_position.x = player_position.x;
          last_safe_position.y = player_position.y;
      }
      
      //fall

      if (player_position.y+camera.y > gameTilemap.getMapHeight()*gameTilemap.getTileHeight()) {
          if (player_state != P_DEAD)
              player_state = P_DEAD;
      }
    
    if (player_state != P_DEAD) {
       if (hspd == 0 && vspd == 0) {
        if (player_state != P_STILL) {
          player_state = P_STILL;
          animInit = true;
        }
      } else  if (hspd != 0 && vspd == 0) {
         if (player_state != P_MOVE) {
          player_state = P_MOVE;
          animInit = true;
        }
      } 
      
      if (vspd != 0) {
        if (player_state != P_JUMP) {
          player_state = P_JUMP;
          animInit = true;
         }   
      }
    
      
     }
  } else {
  
   playertimer++; // every DELAY | 1 = 75 millis
    
    if (playertimer > 1000/75) { // 1 sec
    
          playertimer = 0;
          life--;
          
          if (life > 0) {  
            player_position.x = (int)((last_safe_position.x/8)*8);/*+(8*-last_direction);*/
            player_position.y = (int)((last_safe_position.y/8)*8);
            player_position2.x = player_position.x;
            camera.x = (int)((last_camera.x/8)*8);/*+(8*last_direction);*//*-(display.width()/2)-8;*/
            camera.y = 0;
            player_state = P_STILL;
            vspd = 0;
            hspd = 0;
            check_pulo = false;
        } else {
            gamestate = GAME_GAMEOVER;
        }
   }
  }
  
}

void playerDraw() {

  //BMP * frameAtual;
  const unsigned char * frameAtual;
  
  //animation setup
  if (animInit) {
  
    frame = 0;
    frameCounter = 0;   
    
    if (player_state == P_STILL || player_state == P_JUMP) {
      frameSpd = 0.;
      frameMax = 1; 
    } else if (player_state == P_MOVE) {
      frameSpd = 0.8;
      frameMax = 4;
    }
  
     animInit = false;
  }
  
  //controlador de tempo de frames
  if (frameMax > 1) {
    frameCounter += frameSpd*DELAY;
    
    if (frameCounter > DELAY) {
      frame++;
      frameCounter = 0;
      if (frame > frameMax-1) {
        frame = 0;
      }
    }
  }
  
  //frames manager 
  
  if (player_state == P_STILL) {
   if (player_direction == 1) 
    frameAtual = frameMario0;
   else
    frameAtual = frameMario4;
  } else if (player_state == P_JUMP) {
    if (player_direction == 1) 
      frameAtual = frameMario3;
    else
      frameAtual = frameMario7;
  } else if (player_state == P_MOVE) {
  
    if (player_direction == 1) {
      switch (frame) {
        case 0: frameAtual = frameMario1; break;
        case 1: frameAtual = frameMario0; break;
        case 2: frameAtual = frameMario2; break;
        case 3: frameAtual = frameMario0; break;
      }
    } else {
      switch (frame) {
        case 0: frameAtual = frameMario5; break;
        case 1: frameAtual = frameMario4; break;
        case 2: frameAtual = frameMario6; break;
        case 3: frameAtual = frameMario4; break;
      }
    }
  
  }
  
  
  display.drawBitmap(player_position.x, player_position.y, frameAtual, pimagew,pimageh,1);

  // debug collision box
  //display.fillRect(player_position.x+pboxoffsetx, player_position.y, 10, 16, BLACK);

}

void drawGui() {

  String stringint = String(life,DEC);
  String string = String("x" + stringint);
  
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.setCursor(0,0);
  display.print(string);

}

void sceneIntro() {
  
  display.clearDisplay(); //clean screen 
  
  float sizex = 13*6;

  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor((display.width()-sizex)/2,display.height()/2-12);
  display.print("Mardu");
  sizex = 8*6;
  display.setCursor((display.width()-sizex)/2,display.height()/2-4);
  display.print("presents");
  display.display();
  
  TIMER_CURRENT = millis();
    
   if (TIMER_CURRENT - TIMER_PREV > 2500) { 
      
        TIMER_PREV = TIMER_CURRENT;
        display.clearDisplay();
        gamestate = GAME_TITLE;
   }
}

void sceneTitle() {

    // loop title screen
    float sizex = 14*6;

   int select = 0; 
   int selectMax = 3;
   unsigned int triggerSelect = 0;
   unsigned int counter = 0;
   unsigned int counterMax = 0;
  
   
  while (gamestate == GAME_TITLE) {

   TIMER_CURRENT = millis();
    
   if (TIMER_CURRENT - TIMER_PREV > DELAY) { 
      
        TIMER_PREV = TIMER_CURRENT;
    
        inputManager(8,   12,   10);
        
        if (triggerSelect == 0) {
            if (buttonPressed[2]) {
              select++;
              if (select >= selectMax) 
                select = 0;
                
            } else if (buttonPressed[0]) {
                  select--;
              if (select < 0)
                select = selectMax-1;    
            }
           
           
           if (buttonPressed[1]) {
            triggerSelect = 1;
            counterMax = 3;
          }
         } 
        
        
       String str = "test";
      
        switch (select) {
          case 0: {str = "< START GAME >"; sizex = 14*6; break;};
          case 1: {str = "< CREDITS >"; sizex = 11*6; break;};
          case 2: {str = "< EXIT GAME >"; sizex = 13*6; break;};  
        }
        
        display.clearDisplay();
        display.drawBitmap(0, 0, gameLogo, 84, 24,1);
        display.setTextSize(1);
        
        if (triggerSelect == 1)
          display.setTextColor(WHITE,BLACK);
        else
          display.setTextColor(BLACK);
        
        display.setCursor((display.width()-sizex)/2,24+8);
        display.print(str);
        
        display.display();
       
      
      
       if (triggerSelect != 0) {
        if (counter > counterMax) {
            counter = 0;
            triggerSelect++;
        } else {
            counter++;
        }
      }
      }
            
        if (triggerSelect == 3) {
          
          if (select == 0) {
            gamestate = GAME_LEVEL;
          } else if (select == 1) {
            gamestate = GAME_CREDITS;
          } else {
            triggerSelect = 0;
          }   
        }
      
       
   }
   
  }



void sceneCredit() {

  float sizex = 8*6;
  int page = 0;
  
  while (gamestate == GAME_CREDITS) {
  
    TIMER_CURRENT = millis();
    
      if (TIMER_CURRENT - TIMER_PREV > DELAY) { 
      
        TIMER_PREV = TIMER_CURRENT;
     
          inputManager(8,   12,   10);
        
        if (buttonPressed[2] || buttonPressed[1] || buttonPressed[0]) {
          page++;
        }
         sizex = 8*6;
      
         display.clearDisplay();
    
          display.setTextSize(1);
          display.setTextColor(BLACK);
          display.setCursor((display.width()-sizex)/2,0);
          if (page < 2) 
            display.print("CREDITS:");
          display.setCursor(0,8);
          if (page == 0) {
            display.println("Created by:");
            display.println("This is not created by me");
          } else if (page == 1) {
             display.println("Written in C  with Arduino  Uno.");
           sizex = 10*6;
           display.setCursor((display.width()-sizex)/2,32);
            display.print("Dec, 2014.");
          } else {
            gamestate = GAME_TITLE;
          } 
          
    
         display.display();
      }
        
  }
}

void sceneLevel() {

  float sizex = 7*6;
  
  while (gamestate == GAME_LEVEL) {
    
         display.clearDisplay();
   
          display.fillRect(0, 0, display.width(), display.height(), BLACK);
          display.setTextSize(1);
          display.setTextColor(WHITE,BLACK);
          display.setCursor((display.width()-sizex)/2,(display.height()/2)-3);
          display.print("LEVEL 1");
                     
          
    
         display.display();
         
    TIMER_CURRENT = millis();
    
      if (TIMER_CURRENT - TIMER_PREV > 2250) { 
      
        TIMER_PREV = TIMER_CURRENT;
        gamestate = GAME_PLAY;
      }
        
  }
}

void sceneGameOver() {

  float sizex = 9*6;
  
  while (gamestate == GAME_GAMEOVER) {
    
         display.clearDisplay();
   
          display.fillRect(0, 0, display.width(), display.height(), BLACK);
          display.setTextSize(1);
          display.setTextColor(WHITE,BLACK);
          display.setCursor((display.width()-sizex)/2,(display.height()/2)-3);
          display.print("GAME OVER");
                     
          
    
         display.display();
         
    TIMER_CURRENT = millis();
    
      if (TIMER_CURRENT - TIMER_PREV > 3000) { 
      
        TIMER_PREV = TIMER_CURRENT;
        gamestate = GAME_TITLE;
      }
        
  }
}

void resetGame() {

  player_state = P_STILL; 
  life = 3;
  player_direction = 1;
  player_position.x = 0;
  player_position.y = display.height()-pimageh-8;
  vspd = 0;
  hspd = 0;


  camera.x = 0;
  camera.y = 0;
  camera_player_side = -1;
  check_pulo = false;

}

void sceneGame() {

  resetGame();
  
  
  while (gamestate == GAME_PLAY) {
  
    TIMER_CURRENT = millis();
    
      if(TIMER_CURRENT - TIMER_PREV > DELAY) { // game loop
      
        TIMER_PREV = TIMER_CURRENT;
      
        inputManager(8,   12,   10); // 5 = 0
        
        if (buttonPressing[2] && buttonPressing[1] && buttonPressing[0]) 
            gamestate = GAME_TITLE;
        
        
        playerLogic(buttonPressing[2],buttonPressing[0],buttonPressed[1]);
      
        display.clearDisplay(); 
        
        gameTilemap.drawMap(camera.x,camera.y);
        playerDraw();
        drawGui();
        
        display.display();
    }

  }
  
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

void update(){
  if(gameState == 1){
     int barMargin = LCD_X - barWidth;
     int pot1 = analogRead(A0); //read potentiometers and set the bar positions
     int pot2 = analogRead(A1);
     bar1X = pot1 / 2 * LCD_X / 512;
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






void movesnake()
{
  l=digitalRead(LEFT);      //Continuously Check the Keys
  d=digitalRead(DOWN);
  r=digitalRead(RIGHT);
  u=digitalRead(UP);
  p=digitalRead(PAUSE);
  

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
  
  display.drawCircle(x[0],y[0],1,BLACK);       //Draw new head of snake
  display.drawCircle(x[slength],y[slength],1,WHITE);   //Delete old tail of snake
  
  display.display();
        
}

void redraw()   //Redraw ALL POINTS of snake and egg
{
  display.fillRect(xegg,yegg,3,3,BLACK);
  for(i=0;i<slength;i++)
     {
     display.drawCircle(x[i],y[i],1,BLACK);
     
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



















void setup()   {

  Serial.begin(9600);

  display.begin();
    display.clearDisplay();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);
  
  //song - DOSENT WORK - DO NOT USE
  //pinMode(3, OUTPUT);//buzzer
  //pinMode(13, OUTPUT);//led indicator when singing a note
  
  // inputs
  pinMode(8, INPUT); 
  pinMode(9, INPUT);  
  pinMode(10, INPUT);  
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);//Ativa o resistor de pull-up da porta 7

  gameTilemap.setMapSize(100,6);
  gameTilemap.setDisplayPointer(&display);
  gameTilemap.setTileMap(TileMap0);
  LcdInitialise();
  restartGame();

  
}






void loop() {
 // LcdInitialise();
  

  if (counter == 1)
  {   switch (gamestate) { // "STATE MACHINE MANAGER"
  
    case GAME_INTRO: {sceneIntro(); break;}
    case GAME_TITLE: {sceneTitle(); break;}
    case GAME_CREDITS: {sceneCredit(); break;}
    case GAME_LEVEL: {sceneLevel(); break;}
    case GAME_PLAY: {sceneGame(); break;}
    case GAME_GAMEOVER: {sceneGameOver(); break;}
  }
  }
  if (counter == 2)
  {  
     unsigned long now = millis();
  if(now - lastRefreshTime > refreshInterval){
      update();
      refreshScreen();
      lastRefreshTime = now; 
    
     
  }
  }
 if (counter == 3)
 {
   
    movesnake();
  
 }



 
  
  
}

void snakesetup()
{
  display.setContrast(25);
  slength=8;                 //Start with snake length 8
  
  xegg=(display.width())/2;
  
  yegg=(display.height())/2;
  
  display.setTextSize(2);          //Initial Display
  display.setTextColor(BLACK);
  display.setCursor(10,15);
  display.print("rishabh");
  display.setCursor(10,40);
  display.print("jjjj");
  display.display();
  delay(4000);
  display.clearDisplay();
  
  for(i=0;i<=slength;i++)      //Set starting coordinates of snake
  {
    x[i]=25-3*i;
    y[i]=10;   
  }
  
  for(i=0;i<slength;i++)         //Draw the snake
     {
     display.drawCircle(x[i],y[i],1,BLACK);
     }
     display.display();

    dr=true;
}



