#include <string>
#include <numeric>

std::string cake(int x, std::string y){
  return x*0.7<=std::accumulate(y.begin(),y.end(),0,[i=0](int sum, auto curr)mutable{
    return sum+=i++%2==0?(int)curr:(curr-96);
  })?"Fire!":"That was close!";
}