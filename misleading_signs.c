#include <stdbool.h>
#include <string.h>

bool gaslighting(const char *s,
                 const char *your,
                 const char *let) {
    int arr[26]={0};
  for(;*let;++let) arr[*let-97]++;
  for(size_t i=0;i<strlen(s);++i){
    if(s[i]!=your[i] && (arr[your[i]-97] || arr[s[i]-97])) 
        return true; 
  }
    return false;
}

///////////////
_Bool gaslighting (const char *s, const char *w, const char *f) 
{ return *s&&*w?
        *s!=*w&&(strchr (f,*s)||strchr (f,*w))?1:
        gaslighting (s+1,w+1,f):0; }