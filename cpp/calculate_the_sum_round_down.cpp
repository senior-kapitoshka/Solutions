#include <cstdint>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <execution>

#if 1
template <class F>
auto calc(std::int64_t n, F f) -> std::int64_t {
  std::int64_t sum = 0;
  for (std::int64_t i=n; i>= 1;) {
    std::int64_t x = std::round(n/i);
    std::int64_t i1 = n/(x + 1);
    sum+=(i - i1)*f(x);
    std::swap(i,i1);
  }
  return sum;
}

#endif

#if 0
template <class F>
void rec(std::int64_t& sum,std::int64_t n, std::int64_t& i, F f) {
  if(i==0)return;
  std::int64_t x=(n/i);
  std::int64_t i1=n/(x + 1);
  sum+=(i - i1)*f(x);
  //sum+=f((n/i));
  std::swap(i,i1);
  rec(sum,n,i,f);
}

template <class F>
auto calc(std::int64_t n, F f) -> std::int64_t {
  std::int64_t sum=0;
  std::int64_t i=n;
  rec(sum,n,i,f);
  return sum;
}
#endif

#if 0
template <class F>
auto calc(std::int64_t n, F f) -> std::int64_t {
  std::vector<std::int64_t>vc(n);
  std::iota(vc.begin(),vc.end(),1);
  std::transform(std::execution::par,vc.begin(),vc.end(),vc.begin(),[&f,&n](auto& i){
    return f(std::round(n/i)); 
  });
  return std::reduce(std::execution::par,vc.begin(),vc.end(),0);
}
#endif

//////////////////////////////
#include <cstdint>

template <class F>
auto calc(std::int64_t n, F f) -> std::int64_t {
  std::int64_t sum = 0;
  std::int64_t last = 0;
  std::int64_t j = 0;
  std::int64_t i = n;
  while(j!=n){
    last=f(n/i);
    j=n/i;
    sum += (i-n/(j+1))*last;
    i=n/(j+1);
  }
  return sum;
}
/////////////////
