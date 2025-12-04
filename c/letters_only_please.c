#include <stdio.h>

char *remove_chars(const char *str, char *filtered)
{
    char *res=filtered;
    for(const char * c=str;*c!='\0';++c){
      if((*c>='A' && *c<='Z')||(*c>='a' && *c<='z') || *c==' '){
        *res=*c;
        res++;
      }
    }
    *res = '\0'; // write to filtered
    return filtered; // return it
}

////////////////
#include <ctype.h>

char *remove_chars(const char *s, char *filtered)
{
  char *p = filtered;
  
  for (; *s; s++)
    if (isalpha(*s) || *s == ' ')
      *p++ = *s;

  return *p = 0, filtered;
}

///////////