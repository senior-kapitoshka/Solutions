#include <stddef.h>

int comp(const void* lhs,const void* rhs){
  return (strcmp(strchr(*(char **)lhs,' '),strchr(*(char **)rhs,' ')));
}

void sort_reindeer (size_t l, const char *rn[l])
{
  qsort(rn,l,sizeof(*rn),comp);
}
////////////
