#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>

bool check(size_t i,char *msg, const char* htg){
  for(size_t j=i,k=0;k<strlen(htg);++j,++k){
    if(msg[j]!=htg[k]) {
      return false;
    }
  }
  return true;
}


void omit_hashtag(char *msg, const char* htg)
{
  char* cpy=calloc(strlen(msg)+1,1);
  strcpy(cpy,msg);
  char* p=msg;
  bool flag=false;
  for(size_t i=0;cpy[i]!='\0';){
    if(cpy[i]=='#' && !flag){
      if(check(i,cpy,htg)){
        i+=strlen(htg);
        flag=true;
      }else{
        *p++=cpy[i++];
      }
    }else{
      *p++=cpy[i++];
    }
  } 
  *p='\0';
}

///////////////////////////////
#include <string.h>

void omit_hashtag(char* message, const char* hashtag)
{
    char *found = strstr(message, hashtag);
    if (found)
    {
        size_t hashtag_length = strlen(hashtag);
        memmove(found, found + hashtag_length, strlen(found) - hashtag_length + 1);
    }
}

//////////////////////////////
#include <string.h>

void omit_hashtag(char *msg, const char *ht) {
  char *p = strstr(msg, ht), *q = p + strlen(ht);
  if (p) memmove(p, q, strlen(q) + 1);
}

/////////////////////////////
