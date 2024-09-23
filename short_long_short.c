#include <stdlib.h>

char *short_long_short (const char *a, const char *b)
{
  char * res=(char*)malloc(2*(strlen(a))+2*(strlen(b)));
  int i=0,j=0;
  if(strlen(a)>strlen(b)){
    while(b[i]!='\0'){
      res[j++]=b[i++];
    }
    i=0;
    while(a[i]!='\0'){
      res[j++]=a[i++];
    }
    i=0;
    while(b[i]!='\0'){
      res[j++]=b[i++];
    }
    i=0;
  }else{
    while(a[i]!='\0'){
      res[j++]=a[i++];
    }
    i=0;
    while(b[i]!='\0'){
      res[j++]=b[i++];
    }
    i=0;
    while(a[i]!='\0'){
      res[j++]=a[i++];
    }
    i=0;
  }
  res[j++]='\0';
	return res; // memory will be freed
}

/////////////////////////////
#include <stdio.h>
#include <string.h>

char *short_long_short (const char *a, const char *b) {
  char *res;
  char *c = (strlen(a) > strlen(b)) ? b : a;
  char *d = (strlen(a) > strlen(b)) ? a : b;
  asprintf(&res, "%s%s%s", c, d, c);
  return res;
}
/////////////////
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *short_long_short (const char *a, const char *b)
{  
	if(strlen(a) < strlen(b)) {
    char* s = calloc(strlen(a) * 2 + strlen(b) + 1, sizeof(char));
    sprintf(s, "%s%s%s", a, b, a);
    return s;
  } else{
    char* s = calloc(strlen(b) * 2 + strlen(a) + 1, sizeof(char));
    sprintf(s, "%s%s%s", b, a, b);
    return s;
  } 
}

/////////////////////
char *short_long_short (const char *a, const char *b)
{
  char *res;
  (strlen(a) > strlen(b)) ? asprintf(&res,"%s%s%s", b, a, b):asprintf(&res,"%s%s%s", a, b, a);
	return res;
}

