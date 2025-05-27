#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct Character_Count_Pair {
    char character;
    size_t count;
} ccp;

ccp* ordered_count(const char *strin, size_t *szout) { // assign output length to szout
    int dict[256]={0};
  size_t n=strlen(strin);
  ccp * res=malloc(sizeof(ccp)*n);
  for(size_t i=0;i<n;++i){
    dict[strin[i]-0]++;
  }
  size_t cnt=0;
  for(size_t i=0;i<n;++i){
    if(dict[strin[i]-0]!=0){
      ccp t={strin[i],dict[strin[i]-0]};
      res[cnt++]=t;
      dict[strin[i]-0]=0;
    }
  }

  //////////////
  #include <stddef.h>
#include <stdlib.h>

typedef struct Character_Count_Pair {
    char character;
    size_t count;
} ccp;

ccp* ordered_count(const char *strin, size_t *szout) { // assign output length to szout
  int char_count[256] = {};
  size_t ccp_count = 0;
  for (const char *p = strin; *p; p++) {
    unsigned i = (unsigned)*p;
    if (!char_count[i]++) ccp_count++;
  }

  ccp *result = malloc(ccp_count * sizeof(*result)), *pr = result;
  
  for (const char *p = strin; *p; p++) {
    unsigned i = (unsigned)*p;
    if (char_count[i]) {
      pr->character = i;
      pr->count = char_count[i];
      char_count[i] = 0;
      pr++;
    }
  }

  *szout = ccp_count;
  return result;
}

////////////
#include <stddef.h>

typedef struct {
    char c;
    size_t n;
} ccp;

ccp* ordered_count(const char *s, size_t *o) {
  ccp *a = calloc(strlen(s), sizeof(ccp));
  *o = 0;  
  for (int f = 0; *s; s++, f = 0) {
    for (int i = 0; !f && i < *o; i++) if (a[i].c == *s) f = a[i].n++;
    if (!f) a[*o].c = *s, a[*o].n++, (*o)++;
  }
  return a;
}