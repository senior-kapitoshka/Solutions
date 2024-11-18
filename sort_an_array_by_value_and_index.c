#include <stdlib.h>
struct Pair{
  int t_val,p_val;
};

int comp(const void* lhs, const void* rhs){
   struct Pair l=*(struct Pair*)lhs;
  struct Pair r=*(struct Pair*)rhs;
  return l.p_val -r.p_val;
}

int* sortByValueAndIndex(int* a, int sz)
{
  struct Pair * pm=(struct Pair*)malloc(sizeof(struct Pair)*sz);
  struct Pair*ptr=pm;
  for(int i=0;i<sz;++i){
    struct Pair p;
    p.t_val=a[i];
    p.p_val=a[i]*(i+1);
    *ptr++=p;
  }
  qsort(pm,sz,sizeof(struct Pair),comp);
  int* res= (int*)malloc(sizeof(int)*sz);
  int* p=res;
  for(int i=0;i<sz;++i){
    *p++=pm[i].t_val;
  }
  return res;
}

///////////////
#include <stdlib.h>

struct Number
{
    int data;
    long long index;
};

typedef struct Number Number;

int comparator (const void* a, const void* b)
{
    Number arg1 = *(const Number*)a;
    Number arg2 = *(const Number*)b;
 
    if (arg1.index * arg1.data < arg2.index * arg2.data) return -1;
    if (arg1.index * arg1.data > arg2.index * arg2.data) return 1;
    return 0;
}

int* sortByValueAndIndex(int* array, int arrayLength)
{
    Number array_with_indexes[arrayLength];
    for (int i = 0; i < arrayLength; ++i)
    {
        array_with_indexes[i].index = i + 1;
         array_with_indexes[i].data = array[i];
    }
    qsort (array_with_indexes, arrayLength, sizeof(Number), comparator);
    for (int i = 0; i < arrayLength; ++i)
    {
        array[i] = array_with_indexes[i].data;
    }
    return array;
}

///////////////
typedef struct elem { int val; int idx; } Elem;

int cmp_elem(Elem *a, Elem *b) { return a->idx * a->val - b->idx * b->val; }

int *sortByValueAndIndex(int* arr, int n) {
  Elem elems[n];  
  for (int i = 0; i < n; i++) elems[i].idx = i + 1, elems[i].val = arr[i];  
  qsort(elems, n, sizeof(Elem), cmp_elem);  
  int *ret = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) ret[i] = elems[i].val;
  return ret;
}

//////////////
