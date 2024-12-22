#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char *numeric_formatter (const char *tt, const char *in)
{
  char arr[10]="1234567890";
  char* res=calloc(strlen(tt)+1, 1);
  char* ptr=res;
  size_t sz=0;
  bool flag=false;
  if(*in!='\0'){
    sz=strlen(in);
    flag=true;
  }
  for(size_t i=0;*tt;tt++){
    if(!isalpha(*tt)){
      *ptr++=*tt;
    }else{
      if(flag){
        *ptr++=in[i%sz];
        ++i;
      }else{
        *ptr++=arr[i%10];
        ++i;
      }
    }
  }
  *ptr='\0';
  return res;
}

/////////////////////////////
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

char *
numeric_formatter(const char * template, const char * input)
{
    int i, j;
    char *buf;
    if (*input == '\0') input = "1234567890";
    buf = strdup(template);
    for (i = j = 0; buf[i] != '\0'; i++) {
        if (isalpha(buf[i])) {
            if (input[j] == 0) j = 0;
            buf[i] = input[j++];
        };
    };
  return buf;
}

///////////////////////////
#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>

char * numeric_formatter(char * template, char * input)
{
  char *inp = *input ? input : "1234567890";
  char *ret = strdup(template);
  
  for (char *r = ret, *p = inp; *r; r++, p = *p ? p : inp)
    if (isalpha(*r)) *r = *p++;
  
  return ret;
}

/////////////////////////
