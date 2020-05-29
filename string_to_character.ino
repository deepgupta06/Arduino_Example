void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

    const char* t = "abcd";
  int len = strlen(t);String x;
for (int i = 0; i < len; i++)
{
    char chr = t[i];
    x +=(char)chr;
   
    
    //do something....
}

char tab2[1024];
strcpy(tab2, x.c_str());

 Serial.println(tab2);

}

void loop() {

  // put your main code here, to run repeatedly:

}
