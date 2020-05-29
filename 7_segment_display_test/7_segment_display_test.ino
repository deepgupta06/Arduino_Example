#define LATCH 3
#define CLK 4
#define DATA 5

byte digit[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};


long int i;

void setup(){
 
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
 
}

void loop(){


 
 for(i=0;i<1000000;i++)
 {
   digitPrint(ExtractDigit(i, 6), ExtractDigit(i, 5), ExtractDigit(i, 4), ExtractDigit(i, 3), ExtractDigit(i, 2), ExtractDigit(i, 1));  
    delay(10);
 }
}

int ExtractDigit(long int V, int P)
{
  return int(V/(pow(10,P-1))) % 10; 
}
void digitPrint(int firstdigit, int seconddigit, int thirddigit, int fourthdigit, int fivethdigit, int sixthdigit)  
{
   digitalWrite(LATCH, LOW);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[firstdigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[seconddigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[thirddigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[fourthdigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[fivethdigit]);
   shiftOut(DATA, CLK, MSBFIRST, ~digit[sixthdigit]);
   digitalWrite(LATCH, HIGH);
  
}
