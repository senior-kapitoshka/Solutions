#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N(x) x/8

// return a dynamically allocated, free-able C-string
char *binary_to_string(const char *bin) {
    char* res=(char*)malloc(N(strlen(bin)));
  char*p= res;
  int x=0;
  for(int i=0,j=7;i<(int)strlen(bin);++i,--j){
    if(j==-1){
      *p++=(char)x;
      x=0;
      j=7;
    }
    x+=pow(2,j)*(bin[i]-'0');
  }  
  *p++=(char)x;
  *p='\0';
  return res;
}

////////////
#include <stdlib.h>
#include <string.h>

#define BIN(b, i, n)  (b[i] - '0' << n)

char *binary_to_string(const char *b)
{
    char *r = calloc(sizeof(char), (strlen(b) >> 3) + 1);
    char *s;
    for (s = r; *b; b += 8)
        *s++ = BIN(b, 0, 7) | BIN(b, 1, 6) | BIN(b, 2, 5) | BIN(b, 3, 4) | BIN(b, 4, 3) | BIN(b, 5, 2) | BIN(b, 6, 1) | BIN(b, 7, 0);
    return r;
}

#undef BIN

////////////
#include <stdlib.h>

char *binary_to_string(const char *binary) 
{
  char * buf = calloc(strlen(binary) / 8 + 1, 1);
  
  for (char *p = binary, *q = buf; *p; q++)
    for (int i = 8; i; i--)
      *q |= (*p++ == '1') << i - 1;  
  
  return buf;
}

///////////
#include <stdlib.h>
#include <string.h>

char *binary_to_string(const char *binary) {
    int len = strlen(binary) / 8;
    char *ascii = malloc(len + 1);
    for(int i = 0; i < len; i++){
        char *substr = malloc(8);
        strncpy(substr, binary + 8 * i, 8);
        ascii[i] = strtol(substr, NULL, 2);
    }
    ascii[len] = '\0';
    return ascii;
}

//////////
