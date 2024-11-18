#include <stddef.h>

int comp(const void* lhs,const void* rhs){
  unsigned l=*(const unsigned*)lhs;
  unsigned r=*(const unsigned*)rhs;
  return l-r;
}

size_t how_many_gifts(unsigned mb, size_t l, const unsigned gs[l]) {
    size_t cnt=0;
  unsigned* g=(unsigned*)malloc(l*sizeof(unsigned));
  memcpy(g,gs,sizeof(unsigned)*l);
  qsort((void*)g,l,sizeof(unsigned),comp);
  for(size_t i=0;i<l;++i){
    if(mb<g[i]) return cnt;
    mb-=g[i];
    ++cnt;
  }
  return cnt;

}

////////////////////////////
#include <stddef.h>

int cmp (unsigned *a, unsigned *b) { return (*a<*b)-(*a>*b); }
size_t how_many_gifts (unsigned b, size_t n, const unsigned a[n]) { unsigned s[n],c=0; qsort (memcpy (s,a,4*n),n,4,cmp); for (;n--&&s[n]<=b;++c) b-=s[n]; return c; }
