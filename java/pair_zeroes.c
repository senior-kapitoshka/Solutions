#include <stddef.h>
#include <stdbool.h>

//  assign values to preallocated *results
//  set pointer *r to length of the output

void pair_zeros(size_t a, const int arr[a], size_t *r, int *res) {
    bool flag=false;
  size_t j=0;
    for(size_t i=0;i<a;++i){
      if(arr[i]!=0){
        res[j++]=arr[i];
      }else{
        if(!flag){
          flag=true;
          res[j++]=arr[i];
        }else{
          flag=false;
        }
      }
    }
  *r=j;
}

///////////////////////
#include <stddef.h>

void pair_zeros(size_t a, const int array[a], size_t *r, int *results)
{
    int pair = 1;

    if (!a) return;
    for (unsigned long i = 0; i < a; i++) {
        if (array[i] == 0) {
            pair = !pair;
            if (pair) continue;
        }
        results[*r] = array[i];
        (*r)++;
    }
}

/////////////////////
#include <stddef.h>

void pair_zeros(size_t n, const int a[n], size_t *rn, int *r)
{
  *r = 0;
  for (int z = 0; n--; a++) if (*a || ++z % 2) r[(*rn)++] = *a;
}