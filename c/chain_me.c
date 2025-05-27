#include <stddef.h>

typedef int (*funcptr) (int);

int chain (int i, size_t l, const funcptr fs[l])
{
  for(size_t j=0;j<l;++j){
    i=fs[j](i);
  }
  return i;
}
//////////
#include <stddef.h>

typedef int (*funcptr) (int);

int chain (int v, size_t n, const funcptr functions[n])
{
  return n ? chain((*functions)(v), n-1, functions+1) : v;
}
////////////
#include <stddef.h>

typedef int (*funcptr) (int);

int chain(int init_val, size_t length, const funcptr *functions) {
    while(length--) {
        init_val = (*functions++)(init_val);
    }
    return init_val;
}