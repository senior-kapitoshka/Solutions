#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* to_string(char c){
  int x=c-'0';
  char* res=calloc(x+1,1);
  char*p=res;
  do{
    *(p++)=c;
  }while(--x);
  *p='\0';
  return res;
}

char *digits_explode (const char *d)
{
  char* p_d=d;
  int size=0;
  for(;*p_d;++p_d){
    size+=*p_d-'0';
  }
  char* res=(char*)calloc(size+1,1);
  char* p=res;
  for(;*d;++d){
    if(*d!='0'){
      char* s=to_string(*d);
      p+=sprintf(p,"%s",s);
      free(s);
    }
  }
  *p='\0';
  return res;
}

///////////////////////
#include <stdlib.h>
#include <string.h>

char *digits_explode (const char *d)
{
  char *res = calloc(9 * strlen(d) + 1, 1), *r = res;
  for (int n; *d; d++, r += n) memset(r, *d, n = *d - '0');
  return res;
}

//////////////////////
#include <stdlib.h>

size_t sum_digits (const char *digits)
{
  size_t sum = 0;

  for (; *digits; digits++)
    sum += *digits - '0';

  return sum;
}

char *digits_explode (const char *digits)
{
  char *exploded = malloc(sum_digits(digits) + 1), *retval = exploded;

  for (; *digits; digits++)
    for (int i = 0; i < *digits - '0'; i++)
      *(exploded++) = *digits;

  *exploded = '\0';
  return retval;
}

//////////////////////
#include <stdlib.h>

char *digits_explode (const char *digits)
{
  int l = 0;
  for(const char* p = digits; *p; p++) l += *p - '0';
  char* s = calloc(l + 1, 1);
  char* r = s;
  
  for(const char* q = digits; *q; q++){
    int i = *q - '0';
    while(i--) *s++ = *q; 
  }
  *s = '\0';
  return r;
}