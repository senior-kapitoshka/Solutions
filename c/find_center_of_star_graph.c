#include <stddef.h>

typedef struct Graph_Edge_Pair {
    unsigned a;
    unsigned b;
} edge;

unsigned center(size_t l, edge ge[l]) {
  unsigned res=0;
  for(size_t i=1;i<l;++i){
    res=(ge[i-1].a==ge[i].a || ge[i-1].a==ge[i].b)?
      ge[i-1].a:
      ge[i-1].b;
  }
  return res;
}

////////////
#include <stddef.h>

unsigned center (size_t n, struct { int a,b; } g[n]) { int a=g[0].a,b=g[0].b,c=g[1].a,d=g[1].b; return a==c||a==d?a:b; }
///////
#include <stddef.h>

typedef struct Graph_Edge_Pair {
    unsigned a;
    unsigned b;
} edge;

unsigned center(size_t len, edge ge[len])
{
    return (unsigned[]){ ge[0].a, ge[0].b }[ge[0].b == ge[1].a || ge[0].b == ge[1].b];
}