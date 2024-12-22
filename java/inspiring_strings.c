#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *longest_word (const char *ws)
{
  char* res=(char*)malloc(strlen(ws));
  //*res='\0';
  char* w=strdup(ws);
  char* tok=strtok(w," ");
  while(tok!=NULL){
    if(strlen(res)<=strlen(tok)){
      strcpy(res,tok);
    }
    tok=strtok(NULL," ");
  }
  return res;
}

///////////////////
#include <string.h>
#include <stdlib.h>

char *longest_word(char *word_str) {
  int i=0, j=1,k, max =0, imax =0; // imax -  start of the longest word
 
  while (word_str[j-1]){
    while (word_str[j]!=' ' && word_str[j]) j++;
      if (j-i>=max) max=j-i, imax=i;
      j++;
      i=j;
    } 
  char *out = calloc(max +1, 1); //with calloc we don't need to put extra '\0' at the end
  memmove(out, word_str +imax, max);
  return out;
}

///////////////////
#include <stdlib.h>

char *longest_word(char *word_str)
{
  int maxlen = 0;
  char * copy = strdup(word_str), *word = strtok(copy, " "), *maxword = word;
  while (word != NULL)
  {
    if (strlen(word) >= maxlen)
    {
      maxword = word;
      maxlen = strlen(word);
    }
    word = strtok(NULL, " ");
  }
  
  char *ret = strdup(maxword);
  free(copy);
  return ret;
}
