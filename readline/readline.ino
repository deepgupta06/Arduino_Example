char buffer[20];
int idx = 0;

readLine()
{
  bool EOL = false;
  while (! EOL)
  {
    c = readCharSD();  / reads 1 char from SD
    if (c == '\n' || idx==19)  // prevent buffer overflow too..
    { 
      buffer[idx] = 0;
      idx = 0;
      EOL = true;
    }
    else
    {
      buffer[idx] = c;
      idx++
    }
  }
}

