char* robber_encode(const char *s, char *res)
{
  char* ptr=res;
  for(char* p=s;*p;++p){
    switch(*p){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'o':
        case 'O':
        case 'i':
        case 'I':
        case 'U':
        case 'u':*ptr++=*p; break;
        default: 
                  if(isalpha(*p)){
                    if(isupper(*p)){
                      *ptr++=*p;
                      *ptr++='O';
                      *ptr++=*p; break;
                    }else{
                      *ptr++=*p;
                      *ptr++='o';
                      *ptr++=*p; break;
                    }
                  }else{
                    *ptr++=*p; break;
                  }
    }
      
  }
  *ptr = '\0';
  
	return res;
}

///////////////////
#include <stdio.h>
#include <string.h>

#define CONL "bcdfghjklmnpqrstvwxyz"
#define CONU "BCDFGHJKLMNPQRSTVWXYZ"

char* robber_encode(const char *sentence, char *encoded){
  *encoded = '\0';
  
  while(*sentence){
    if( strchr(CONL, *sentence) != NULL) sprintf(encoded, "%s%c%c%c", encoded, *sentence, 'o', *sentence);
    else if( strchr(CONU, *sentence) != NULL) sprintf(encoded, "%s%c%c%c", encoded, *sentence, 'O', *sentence);
    else sprintf(encoded, "%s%c", encoded, *sentence);
    sentence++;
  }
	return encoded;
}