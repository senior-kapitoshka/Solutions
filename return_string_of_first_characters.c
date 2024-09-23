#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *make_acronym (const char *txt, char *res){
  char* c=malloc(strlen(txt));
  strncpy(c,txt,strlen(txt)+1);
  char* p=strtok(c," ");
  char* pr=res;
  while(p){
    *pr++=p[0];
    p=strtok(NULL," ");
  }
  *pr='\0';
  free(c);
return res;
}

////////////////////
char *make_acronym (const char *words, char *letters)
{
	char *tmp = letters;
  *(tmp++) = *words;
  
  while(*words++) {
    if(*words == ' ') {
      *tmp = *(++words);
      tmp++; 
    }
  }
  
  *tmp = 0;
  
  return(letters);
}

///////////////////////
char *make_acronym (const char *words, char *letters)
{
  char *tmp = letters;

  do {
    *(tmp++) = *words;
    words = strstr(words, " ");
  } while(words++);

  *tmp = '\0';

	return letters;
}

///////////////////////////
