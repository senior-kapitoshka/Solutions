#include <stdlib.h>
#include <string.h>
//Jean Bartik
// Kathleen Antonelli
// Marlyn Meltzer
// Betty Holberton
// Frances Spence
// Ruth Teitelbaum
char* rad_ladies(const char* txt) {

  char* res=(char*)malloc(sizeof(txt));
  char* p=res;
  for(char* i=txt;*i;++i){
    if((*i>'A' && *i<'z') || *i==' ' || *i=='!'){
      if(*i>='a'){
        *p++=*i-32;
      }
      else *p++=*i;
    }
  }
  return res;

}

////////////
#include <stdlib.h>

char* rad_ladies(const char* text) {
  char *buf = calloc(strlen(text), sizeof(char));
  for (char *q = buf; *text; text++) 
  {
    if (strchr("0123456789%$&/£?@", *text) == NULL) *q++ = toupper(*text);
  }
  return buf;
}
///////////
#include <stdlib.h>
#include <ctype.h>

char* rad_ladies(const char* text) {
  char *res = (char *) calloc(27, 1), *k = res;
  
  for (char *p = text; *p; p++) {
    if (isalpha(*p) || *p == ' ' || *p == '!')
      *k++ = toupper(*p);
  }
  
  return res;
}
///////////
