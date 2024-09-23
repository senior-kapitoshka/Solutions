#include <stddef.h>
char *double_char (const char *s, char *d)
{
  if(s==NULL) return NULL;
  int i=0,j=0;
  for(;s[i]!='\0';++i){
    d[j++]=s[i];
    d[j++]=s[i];
  }
  d[j++]='\0';
  return d; 
}

////////////////////
char *double_char (const char *string, char *doubled)
{
  char* s=string, *d=doubled;
  while(*s){
    *d++=*s;
    *d++=*s++;
  }
  *d='\0';
  return doubled; // return it
}

//////////////////
