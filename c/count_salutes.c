#include <stddef.h>
#include <string.h>

size_t count_salutes(const char *h) {
  size_t c=0;
  size_t i=0,n=strlen(h);
  while(h[i]!='>' && i<n-1)++i;
  if(i==n-1) return 0;
  for(;i<n;++i){
    if(h[i]=='>'){
      for(size_t j=i;j<n;++j){
        if(h[j]=='<') c+=2;
      }
    }
  }
  return c;
}

//////////
#include <stddef.h>

size_t count_salutes(const char *hallway)
{
  int r = 0, n = 0;

  for (char *p = (char *)hallway; *p; p++) 
    n += *p == '>', r += n * (*p =='<');

  return r * 2;
}

//////////
#include <stddef.h>

size_t count_salutes(const char *hallway) {
    size_t salutes = 0, meets = 0;
    while(*hallway) {
        char c = *hallway++;
        if(c == '>') {
            meets += 1;
        }
        else if(c == '<') {
            salutes += 2 * meets;
        }
    }
    return salutes;
}

//////////
#include <stddef.h>

size_t count_salutes(const char *hallway) {
  size_t r = 0, l = 0;
  for(const char* h = hallway; *h; h++){
    if(*h == '>') r++;
    if(*h == '<') l += r;
  }
  return l * 2;
}