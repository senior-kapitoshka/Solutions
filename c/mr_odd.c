#include <stddef.h>
#include <limits.h>

size_t odd(const char *s) {
  size_t res=0;
  size_t o[10000]={INT_MAX};
  size_t i=0,j=0,k=0;
  size_t d1[10000]={INT_MAX};
  size_t d2[10000]={INT_MAX};
  char flag=0;
  for(size_t l=0;*s;++s,++l){
    if(*s=='o') o[i++]=l;
    else if(*s=='d' && !flag && j<i){
      flag=1;
      d1[j++]=l;
    }else if(*s=='d' && flag && k<j){
      flag=0;
      d2[k++]=l;
    }
  }
  for(size_t l=0;l<i;++l){  
    if(o[l]<d1[l] && d1[j]<d2[l]){
      ++res;
    }
  }
  return res;
}

/////////////////////
#include <stddef.h>

size_t odd(const char *string)
{
    size_t o = 0, d = 0, odd = 0;

    for (; *string; string++) {
        switch (*string) {
        case 'o':
            o++;
            break;
        case 'd':
            if (o != 0)
                d++;
            if (o >= 1 && d >= 2) {
                odd++;
                o -= 1;
                d -= 2;
            }
            break;
        }
    }
    return odd;
}

////////////////
#include <stddef.h>

size_t odd (const char *s) {
 int c=0,o=0,d=0; 
for (;*s;++s) o+=*s=='o',d+=o && *s=='d',d>1?d=0,--o,++c:0; 
return c; 
}

///////////////////
#include <stddef.h>
#include <string.h>

size_t odd(const char *s /*string*/) {
  char *p = NULL;
  for (size_t i = 0;; i++, s++) {
    if (s = strchr(s, 'o'), !s)  return i;
    if (s > p) p = (char*) s;
    if (p = strchr(1 + p, 'd'), !p)  return i;
    if (p = strchr(1 + p, 'd'), !p)  return i;
  }
}