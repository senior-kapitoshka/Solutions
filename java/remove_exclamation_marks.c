#include <stdlib.h>
#include <string.h>

char *remove_bang (const char *s)
{
  char * res=(char*)malloc((strlen(s))*sizeof(char));
  int i;
 for(i=0;i<(int)strlen(s);++i){
   if(s[i]!='!') strncat(res, &s[i], 1);
 }
  char ch='!';
  strncat(res, &ch, 1);
  return res;
}

/////////////////////////////
#include <stdlib.h>
#include <string.h>

char *remove_bang (const char *s)
{
  char * res=(char*)malloc((strlen(s))*sizeof(char)+1);
  int i,j=0;
 for(i=0;s[i]!='\0';++i){
   if(s[i]!='!'){
     res[j]=s[i];
     ++j;
   }
 }
  res[j]='!';
  res[j+1]='\0';
  return res;
}

///////////////////
#include <string.h>
#include <stdlib.h>

char* remove_bang(char* s)
{
    int len = strlen(s), i, j;
    char *aux =(char*) malloc(strlen(s));
    
    j = 0;
    for(i = 0; i < len; i++) {
      if(s[i] != '!')
         aux[j++] = s[i];
    }
    aux[j] = '!';
    aux[++j] = '\0';
    return aux;
}

//////////////////////
#include <stdlib.h>
char *remove_bang (const char *s){
  char *ret = (char*)calloc(strlen(s),1); int i=0;
  while(*s){if(*s != '!') ret[i++]=*s; s++;}
  return ret[i]='!',ret;
}

///////////////////

