#include <stddef.h>
#include <stdlib.h>

struct Triple{
  size_t id;
  int val;
  unsigned s;
};

unsigned get_s(int n){
  unsigned res=0;
  while(n){
    n/=10;
    ++res;
  }
  return res;
}
int comp(const void* lhs, const void* rhs){
  struct Triple l=*(const struct Triple*)lhs;
  struct Triple r=*(const struct Triple*)rhs;

  return l.s==r.s?
        r.id-l.id:
        l.s-r.s;
}

int find_longest(int *ns, size_t sz)
{
  struct Triple *arr=malloc(sizeof(struct Triple)*sz);
  for(size_t i=0;i<sz;++i){
    struct Triple t;
    t.id=(int)i;
    t.val=ns[i];
    t.s=get_s(ns[i]);
    arr[i]=t;
  }
  qsort(arr,sz,sizeof(struct Triple),comp);
    return arr[sz-1].val;
}

/////////////////
#include <stddef.h>
int digits(int n) {
  if (n < 0) n = -n;
  int l = 1;
  while(n >= 10) {
    n /= 10;
    l += 1;
  }
  return l;
}
int find_longest(int *numbers, size_t numbers_size) {
  int max = digits(numbers[0]), res = numbers[0];
  for (size_t i = 1; i < numbers_size; i++) {
    int n = numbers[i];
    int d = digits(n);
    if (d > max) {
      max = d;
      res = numbers[i];
    }
  }
  return res;
}

//////////////////
#include <string.h>

int find_longest(int *numbers, size_t numbers_size)
{
    int max_index = 0;
    for(int i = 1; i < numbers_size; i++)
    {
      char temp1[20] = {0}, temp2[20] = {0};
      sprintf (temp1, "%d", abs(numbers[i]));
      sprintf (temp2, "%d", abs(numbers[max_index]));
      if(strlen(temp1) >  strlen(temp2))max_index = i;
    }
    return numbers[max_index];
}

//////////
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

int find_longest(int *numbers, size_t numbers_size)
{
  int max = numbers[0];
  for(int i = 1; i < numbers_size; i++){
    if((int)log10(abs(max)) < (int)log10(abs(numbers[i])))
      max = numbers[i];
  }
  return max;
}

