#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char* get_strings(const char *c)
{
  int a[256]={0};
  const char *cp=c;
  for(;*cp;cp++){
    if(isalpha(*cp))++a[tolower(*cp)];
  }
  char* res=calloc(strlen(c)*10,1);
  char* p=res;
  for(;*c;++c){
    if(a[tolower(*c)]==1){
      p+=sprintf(p,"%c:*,",tolower(*c));
    }else if(a[tolower(*c)]>1){
      int j=a[tolower(*c)];
      char* t=calloc(j+3,1);
      char* pt=t;
      *pt++=tolower(*c);
      *pt++=':';
      while(j--){
        *pt++='*';
      }
      *pt++=',';
      p+=sprintf(p,"%s",t);
      a[tolower(*c)]=0;
    }
  }
  *(p-1)='\0';
    return res;
}

//////////////////////////////
char *get_strings(const char *city)
{
  int freq[26] = {0};
  for (char *p = (char *)city; *p; p++) 
  {
    char c = tolower(*p);
    if (isalpha(c)) freq[c-'a']++;
  }
  
  char *ret = calloc(strlen(city) * 4, 1), *k = ret;
  for (char *p = (char *)city; *p; p++)
  {
    char c = tolower(*p);
    if (isalpha(c) && freq[c-'a'])
      {
        *k++ = c;
        *k++ = ':';
        for (int i = 0; i < freq[c-'a']; i++) *k++ = '*';
        *k++ = ',';        
        freq[c-'a'] = 0; // so same letter not repeated
      }
  }
  return *(--k) = 0, ret;
}

///////////////////
