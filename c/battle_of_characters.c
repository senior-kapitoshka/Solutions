const char *battle (const char *g1, const char *g2)
{
  unsigned int a=0,b=0;
  for(char* p=g1;*p;++p){
    a+=*p-65;
  }
  for(char* p=g2;*p;++p){
    b+=*p-65;
  }
  return  a>b?g1:
          a<b?g2:
          "Tie!";
}
/////////////
const char *battle (const char *a, const char *b)
{
  int n = 0;
  const char *ra = a, *rb = b;
  
  while (*a) n += *a++ - 'A' + 1;
  while (*b) n -= *b++ - 'A' + 1;
  
  return  n >  0 ? ra : n < 0 ? rb : "Tie!";
}
/////////
