#include <stddef.h>

int cmp(const void* lhs,const void* rhs){
  int l=*(const int*)lhs;
  int r=*(const int*)rhs;
  return l-r;
}

int *shuffled_array(const int *arr, size_t n) {
  int* res=(int*)malloc(n*sizeof(int));
  int sum=0;  
  for(size_t i=0;i<n;++i){
    sum+=arr[i];
  }
  char flag=0;
  for(size_t j=0,i=0;i<n;++i){
    if(sum-arr[i]!=arr[i] || (sum-arr[i]==arr[i] && flag)){
        res[j++]=arr[i];
    }else if(sum-arr[i]==arr[i] && !flag){
        flag=1;
    }
  }
  qsort(res,n-1,sizeof(int),cmp);
  return res;
}

/////////////////////////////
#include <stddef.h>

int * cmp(*p, *q) { return *p - *q; }

int * shuffled_array(const int *a, size_t n) {
  int * c = malloc(sizeof(int) * n), s = 0, i;
  for (i = 0; i < n; i++) s += (c[i] = a[i]);
  qsort(c, n, sizeof(int), cmp);
  for (i = 0; i < n; i++) if (s - c[i] == c[i]) return memcpy(&c[i], &c[i+1], (n-i) * sizeof(int)), c;
}

/*
as memory regions overlap, memmove should be used
solution copies "tail" twice, where a single copy would suffice
*/

///////////////////////
#include <stddef.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int *shuffled_array(const int *a, size_t n) {
  int* r = calloc(n-1, sizeof(int));
  int s=0, f=0, ind, j;
  for(size_t i=0; i<n; i++) s += a[i];
  s /= 2;
  f=0;
  for(size_t i=0; i<n; i++){
    if((f==1)||(a[i]!=s))r[i-f]=a[i];
    else f=1;
  }
  qsort(r, n-1, sizeof(int), cmpfunc);  
  return r;
}