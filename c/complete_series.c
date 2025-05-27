#include <stdlib.h>

int comp(const void* l,const void* r){
  return *(int*)l-*(int*)r;
}

int* completeSeries(const int *arr, size_t isz, size_t *osz) {
  qsort(arr,isz,sizeof(int),comp);
  int* res=malloc((arr[isz-1]+1)*sizeof(int));
  for(size_t i=1;i<isz;++i){
    if(arr[i-1]==arr[i]){
      *osz=1;
      res[0]=0;
      return res;
    }
  }
  *osz=arr[isz-1]+1;
  for(size_t j=0;j<*osz;++j){
    res[j]=j;
  }
  return res;
}

////////////////
#include <stdlib.h>

int* completeSeries(const int *arr, int n, int *out) {
  for (int *a = arr, i = 0; i < n; i++, a++)
    if (*a > *out) *out = *a;
  
  int *ret = (int *) calloc(++(*out), sizeof(int));
  for (int *a = arr, i = 0; i < n; i++, a++)
    if (++ret[*a] > 1)
      return *out = 1, ret[0] = 0, realloc(ret, sizeof(int));
  
  for (int i = 0; i < *out; i++)
    ret[i] = i;
  
  return ret;
}

/////////
#include <stdlib.h>

int* completeSeries(const int *arr, size_t inputSize, size_t *outputSize) {
  int max = 0, i, j;
  int *res = malloc(sizeof(int));
  res[0] = 0;
  for (i = 0; i < inputSize; i++) 
  {
    if (arr[i] > max) 
      max = arr[i];
    for (j = i + 1; j < inputSize; j++) 
      if (arr[i] == arr[j])
        return *outputSize = 1, res;
  }
  res = (int*) realloc(res, (max + 1) * sizeof(int));
  for (i = 1; i <= max; i++)
    res[i] = i;
  *outputSize = (max + 1);
  return res;
}

////////////////
#include <stdlib.h>

int *completeSeries(const int *a, size_t n, size_t *z) {
  int *r, m = 0;
  for (size_t i = 0; i < n; i++) {
    if (a[i] > m) m = a[i];
    for (size_t j = 0; j < i; j++)
      if (a[i] == a[j]) return *z = 1, r = malloc(sizeof(int)), r[0] = 0, r;
    }
  r = malloc((*z = ++m) * sizeof(int));
  for (int i = 0; i < m; i++) r[i] = i;
  return r;
}

//////////////
