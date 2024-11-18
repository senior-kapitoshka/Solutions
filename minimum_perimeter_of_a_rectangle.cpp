#include <limits>
#include <cmath>
#define P(i,j) i+i+j+j


bool isprime(int n){
  if(n<=1) return false;
  if(n==2) return true;
  if(n%2==0) return false;
  for(int i=3;i*i<n;i+=2){
    if(n%i==0) return false;
  }
  return true;
}

int minimumPerimeter (int a){
  if(isprime(a)) return P(1,a);
  int res=std::numeric_limits<int>::max();
  for(int i=2;i<=std::sqrt(a);++i){
    if(a%i==0){
      int j=a/i;
      res=std::min(res,P(i,j));
    }
  }
  return res;
}

////////////////
#include <cmath>

int minimumPerimeter (int area) {
  int a = std::sqrt(area);
  for (; a > 0 && area % a != 0; --a);
  return 2 * (a + area / a);
}

////////////
#include <cmath>
int minimumPerimeter (int n)
{
  int i = sqrt(n);
  while (n % i != 0) i--;
  return 2*i+2*n/i;
}

//////////////
int minimumPerimeter (int area) 
{
  int i;
  return i;
}