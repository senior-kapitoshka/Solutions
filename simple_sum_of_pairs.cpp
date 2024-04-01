
int solve(long n){
    if (n==0) return 0;
    int a=n>9?9:n;
    int b=(n-a)%10;
    return (int) (a+b+solve((n-a-b)/10));
}


#if 0

#include <numeric>
#include <cmath>

int solve(long n){
  if(n==0 ||n==1) return n;
  int l=std::floor(std::log10(n));
  std::string s(l,'9');
  int x=n-std::stol(s);
  std::string y=std::to_string(x);
  return std::accumulate(y.begin(),y.end(),0,[](auto& sum,auto& curr)
                         {
                           return  sum+=int(curr-'0');
                         })+9*l;

}


#include <algorithm>
#include <string>
#include <numeric>
int sm(long a,long b){
  std::string x=std::to_string(a)+std::to_string(b);
  return std::accumulate(x.begin(),x.end(),0,[](auto& sum,auto& curr)
                         {
                           return  sum+=int(curr-'0');
                         });
}

int solve(long n){
  if(n==0 ||n==1) return n;
  int res=0;
   for(long i=n/2;i<(n*2)/3;++i){
     res=std::max(res,sm(i,n-i));
   }
  return res;
}

#endif