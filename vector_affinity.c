#include <stddef.h>
#include <math.h>
#define MIN(a,b) a>=b?b:a
#define MAX(a,b) a>=b?a:b

double vector_affinity(size_t n1, const int arr1[n1], size_t n2, const int arr2[n2]) {
  if(n1==n2 && n1==0) return 1.0;
  size_t mn=MIN(n1,n2);
  size_t mx=MAX(n1,n2);
  unsigned cnt=0;
  for(size_t i=0;i<mn;++i){
    if(arr1[i]==arr2[i]){
      ++cnt;
    }
  }
  //printf("%d-%d\n",cnt,mx);
  double res=(cnt*1.0)/(mx*1.0);
  return res;
}

///////////////////////////
#include <stddef.h>

double vector_affinity (size_t m, const int a[m], size_t n, const int b[n]) { int c=0,i=m>n?n:m,k=m+n-i; for (;i--;) c+=a[i]==b[i]; return k?1.*c/k:1; }
/////////////////////
#include <stddef.h>

double vector_affinity(size_t n1, const int arr1[n1], size_t n2, const int arr2[n2]) {
  if (n1 == 0 && n2 == 0) return 1.0;
  size_t maxlen = n2, minlen = n1, sames = 0;
  if (n1 > n2) {
    maxlen = n1;
    minlen = n2;
  }
  for (size_t i=0; i<minlen; i++)
    if (arr1[i] == arr2[i]) sames++;
  return (double)sames/maxlen;
}

////////////////////