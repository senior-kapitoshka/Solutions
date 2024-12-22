#include <stddef.h> /* NULL */
#include <string.h>

int check(const char *p,const char *f){
  if(strlen(p)!=strlen(f)) return 0;
  for(;*p;++p){
    if(*p!=*f++ && *p!='?') return 0; 
  }
  return 1;
}

char **match(const char *p, const char **f)
{
  char** res=(char*)malloc(100*sizeof(char*));
  int i=0;
  for(;*f;++f){
    if(check(p,*f)) res[i++]=*f;
  }
  res[i]=NULL;
    return res;
}

////////////////////
#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

int fmatch(char *p, char *f)
{
  for (; *p && *f; p++, f++) if (*p != '?' && *p != *f) break;
  return *p == *f;
}

char **match(const char *p, const char **f)
{
  int n = 0, k = 0;
  while (f[n]) n++;  
  char **ret = calloc(n + 1, sizeof(char *));
  for (int i = 0; i < n; i++) if (fmatch((char *)p, (char *)f[i])) ret[k++] = strdup(f[i]);
  return realloc(ret, (k + 1) * sizeof(char *));
}
///////////////////
