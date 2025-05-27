#include <stdlib.h>
#include <limits.h>

//  function returns user allocated int array
//  output memory will be freed by the tester
int comp(const void* lhs,const void* rhs){
  return *(int*)lhs - *(int*)rhs;
}

int *min_min_max(const int *a, size_t n) {
  qsort(a,n,sizeof(int),comp);
  int *res=malloc(3*sizeof(int));
  res[0]=a[0];
  res[2]=a[n-1];
  for(size_t i=1;i<n;){
    if(a[i]-a[i-1]==1 || a[i]==a[i-1])++i;
    else{
      res[1]=a[i-1]+1;
      break;
    }
  }

  return res;
}
/////////////
#include <stdlib.h>

//  function returns user allocated int array
//  output memory will be freed by the tester

int *min_min_max(const int *array, size_t n) {
  
    int *output;
    int i, min, max, minAbs;
    output = malloc(sizeof(int)*3);
    
    //find min and max by looping through the array
    min = array[0];
    max = array[0];
    for(i = 1; i < n; i++){
      if(array[i] < min) min = array[i];
      if(array[i] > max) max = array[i];
    }
  
    //find minimum value that is not in the array but greater that min
    minAbs = min + 1;
  isIn:
    for(i = 0; i < n; i++){
      if(minAbs == array[i]){
        minAbs++;
        goto isIn;
      }
    }
    
    //filling the output array
    output[0] = min;
    output[1] = minAbs;
    output[2] = max;
    
    return output;
}
////////////
#include <stdbool.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool contains(const int* const array, const size_t n, const int value) {
  for (size_t i = 0; i < n; ++i) {
    if (array[i] == value) { return true; }
  }
  return false;
}

int* min_min_max(const int* const array, const size_t n) {
  const size_t stats = 3;
  int* res = calloc(stats, sizeof(int));
  for (size_t i = 0; i < stats; ++i) {
    res[i] = array[0];
  }
  
  for (size_t i = 1; i < n; ++i) {
    res[0] = MIN(res[0], array[i]);
    res[2] = MAX(res[2], array[i]);
  }
  
  for (res[1] = res[0] + 1; contains(array, n, res[1]); res[1] += 1) {}
  return res;
}