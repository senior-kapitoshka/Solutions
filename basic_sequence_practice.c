int sm(int i,int* start,char f){
  int sum=0;
  for(int j=0;j<i;++j){ 
    sum+=j;
  }
  return f?sum:sum*(-1);
}

void sum_of_n(int n, int *seq) {
  int* ptr=seq;
  int* start=ptr;
  char f=n>0?1:0;
  int sum=1;
  int l=f?(n+1):(n*(-1)+1);
    for(int i=1;i<=l;++i){
      int* t=start;
      sum=sm(i,t,f);
      *ptr++=sum;
    }
}

///////////////////
#include <stdlib.h>

void sum_of_n(int n, int *seq)
{
  *seq = 0;
  for (int i = 1, k = abs(n); i <= k; i++) 
  {
      seq[i] = seq[i-1] + (n > 0 ? i : -i);
  }
}

////////////////
#include <stdlib.h>

void sum_of_n(int n, int *sequence) {
  for(int i = 0; i <= abs(n); i++) sequence[i] = i * (i + 1) / 2 * (n < 0 ? -1 : 1);
}