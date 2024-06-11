#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

long long over_the_road(long long a, long long n) {
  long long res=0;
  if(a%2==0){
    long long cnt=0;
    long long j=-1;
    for(long long i=4;i<=a;i+=2,++cnt);
    for(long long x=0;x<n;++x,j+=2);
    for(long long i=0;i<cnt;++i,j-=2);
    res=j;
  }else{
    long long cnt=0;
    long long j=0;
    for(long long i=1;i<a;i+=2,++cnt);
    for(long long x=0;x<n;++x,j+=2);
    for(long long i=0;i<cnt;++i,j-=2);
    res=j;
  }
  return res;
}

///////////////
long long over_the_road(long long address, long long n) 
{
  return n * 2 - address + 1 ;
}

////////////
long long over_the_road( long long a, long long n ) {
  return n + n - --a;
}