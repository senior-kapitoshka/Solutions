#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

const char *well(size_t n, const char *is[n]) {
  const char* g="good\0";
  uint8_t cnt=0;
  for(size_t i=0;i<n;++i){
    if(strcmp(g,is[i])==0) ++cnt;
  }
  return (cnt<=2 && cnt!=0)?"Publish!":cnt>2?"I smell a series!":"Fail!";
}

/////////////////
#include <stddef.h>
const char* well(size_t n, const char const* ideas[n]) {
    int good_ideas = 0;
    for(int i=0; i < n; i++) if(ideas[i][0] == 'g') good_ideas++;    
    return !good_ideas?"Fail!":((good_ideas<=2)?"Publish!":"I smell a series!");
}