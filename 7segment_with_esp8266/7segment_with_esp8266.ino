#define LATCH D2
#define CLK D3
#define DATA D1

//This is the hex value of each number stored in an array by index num
//byte digitOne[10]= {0xBFBF, 0x8686, 0xDBDB, 0xCFCF, 0xE6E6, 0xEDED, 0xDFDF, 0x8787, 0xFFFF, 0xEFEF};
int digitOne[10]= {0x3, 0x9F, 0x25, 0xD, 0x99, 0x49, 0x41, 0x1F, 0x1, 0x9};
byte digitTwo[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};


int i;

void setup(){
 
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
 
}

void loop(){


 
 for(i=0;i<10;i++)
 {
      digitalWrite(LATCH, LOW);
     // shiftOut(DATA, CLK, MSBFIRST,0x3); // digitTwo
      shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]);
       shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]);
        shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]);
            shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]);
    shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]);
   shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]);// digitOne
      digitalWrite(LATCH, HIGH);
      delay(1000);
    
 }
}

