#include <stddef.h>

//  assign divisors to array[]
//  set *length to the number of divisors

void divisors(unsigned n, size_t *l, unsigned a[]) {
  size_t cnt=0;
  for(unsigned i=2;i<n;++i){
    if(n%i==0){
      a[cnt++]=i;
    }
  }
  *l=cnt;
}

////////////////////
#include <stddef.h>

//  assign divisors to *array
//  set *z to *array length

void divisors(unsigned n, size_t *z, unsigned *array) {
  *z = 0;
  
  for (int i = 2; i <= (n / 2); i++)
  {
    if (n % i == 0)
      array[(*z)++] = i;
  }
}