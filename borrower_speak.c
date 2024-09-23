#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *borrow(const char *src){
  char* res=calloc(strlen(src),1);
  char* p=res;
  for(size_t i=0;i<strlen(src);++i){
    if(isspace(src[i]) || !isalpha(src[i])) continue;
    else if(isupper(src[i])){
      p+=sprintf(p,"%c",tolower(src[i]));
    }else{
      p+=sprintf(p,"%c",src[i]);
    }
  }
  *p='\0';
  return res;
}

///////////////////////
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* borrow(const char* source)
{
    char* s = malloc(strlen(source) + 1);
    char* it = s;

    for (; *source; source++) {
        if (isalpha(*source)) {
            *it++ = tolower(*source);
        }
    }
    *it = '\0';

    return s;
}

//////////////////
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *borrow(const char *s) {
  char *res = calloc((int)strlen(s), sizeof(char));
  int i, j = 0;;
  for (i = 0; i < (int)strlen(s); i++) {
    char c = s[i];
    if (!ispunct(c) && (c != ' ')) {
      res[j++] = tolower(s[i]);
      
    }
  }
  return res;
}

///////////////////////////
char *borrow(const char *source) 
{
  char * str = calloc(strlen(source) + 1, 1);
  for (char *p = str, *q = source; *q; q++) if (isalpha(*q)) *p++ = tolower(*q);
  return str;
}

///////////////
#include <stdlib.h>
char *borrow (const char *s) {
  char *speak = malloc (1+strlen (s)), *b = speak;
  if (*s) do {
    if (!isalpha (*s)) continue;
    *b++ = isupper (*s) ? *s - 'A' + 'a' : *s;
  } while (*++s);
  return *b = 0, speak;
}