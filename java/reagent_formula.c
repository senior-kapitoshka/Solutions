#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

bool is_valid(size_t l, const unsigned f[l]) {
  uint8_t arr[9]={0,0,0,0,0,0,0,0,0};
  for(size_t i=0;i<l;++i){
    if(f[i]<=8 && f[i]>0)arr[f[i]]=1;
  }
  return (arr[1]!=arr[2] || (arr[1]==0 && arr[2]==0)) && (arr[3]!=arr[4]|| (arr[3]==0 && arr[4]==0)) 
    && arr[5]==arr[6] && (arr[7]==1 || arr[8]==1);
}

/////////////////////
#include <stddef.h>

_Bool is_valid (size_t n, const unsigned f[n]) { int m[9]={}; for (;n--;) ++m[f[n]]; return !(m[1]&m[2])&!(m[3]&m[4])&!(m[5]^m[6])&(m[7]|m[8]); }

/////////////////////
#include <stdbool.h>
#include <stddef.h>

bool is_valid(size_t length, const unsigned formula[length])
{
  int n[9] = {0};

#define BOTH(a,b) (n[a] && n[b])  
#define ONE_OF(a,b) ((n[a] && !n[b]) || (!n[a] && n[b]))
#define NONE_OF(a,b) (!n[a] && !n[b])

  while(length--)
    n[formula[length]]++;
  
  return !(BOTH(1,2) || BOTH(3,4) || ONE_OF(5,6) || NONE_OF(7,8));
}

///////////////
#include <stdbool.h>
#include <stddef.h>

bool is_valid(size_t length, const unsigned formula[length])
{
    bool m[9] = {false};
    for (size_t i = 0; i < length; m[formula[i++]] = true);
    return (!m[1] || !m[2]) && (!m[3] || !m[4]) && !(m[5] ^ m[6]) && (m[7] || m[8]);
}