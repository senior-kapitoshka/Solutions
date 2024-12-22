#include <stddef.h>
#include <string.h>

size_t kooka_counter (const char *l)
{
  if(*l=='\0') return 0;
	size_t c=1;
  char ch=l[0];
  for(size_t i=2;i<strlen(l);i+=2){
    if(l[i]!=ch){
      ch=l[i];
      ++c;
    }
  }
  return c;
}

//////////////////
unsigned kooka_counter (const char *s)
{
  int k = 0, c = 0;
  for (; *s; c = *s, s += 2) k += c != *s;
  return k;
}

/////////////////
