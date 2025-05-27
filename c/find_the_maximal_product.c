#include <stddef.h>
#include <limits.h>

int find_max_product(size_t l, const int a[l]) {
  int max=INT_MIN;
  for(size_t i=1;i<=l;++i){
    int x=1;
    for(size_t j=i-1;j<l;j+=i){
      x*=a[j];
    }
    max=x>max?x:max;
  }
  return max;

}
////////////
