#include <vector>
#include <string>
#include <numeric>
#include <cmath>

bool check(unsigned int x){
  std::string s=std::to_string(x);
  return std::accumulate(s.begin(),s.end(),0u,[i=1](unsigned int sum, auto c)
                         mutable{
    return sum+=std::pow(c-'0',i++);
  })==x;
}

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b) {
  //your code here
  std::vector<unsigned int>res;
  for(unsigned int i=a;i<=b;++i){
    if(check(i))res.push_back(i);
  }
  return res;
}

////////////////////
#include <vector>
#include <cmath>
typedef unsigned int uint;
std::vector<uint> sumDigPow(uint a, uint b) {
  std::vector<uint> arr;
  for(uint j = a;a <= b; a++, j=a){
    uint sum = 0;
    for(uint i = std::log10(a)+1; i > 0; i--){
      sum += std::pow(j%10, i);
      j /= 10;
    }
    if(sum == a) arr.push_back(sum);
  }
  return arr;
}

///////////////
#include <array>
#include <vector>

std::vector<unsigned int> sumDigPow(const unsigned int a,
                                    const unsigned int b) {
    constexpr std::array<unsigned, 19> vals{
        0,  1,   2,   3,   4,   5,    6,    7,    8,      9,
        89, 135, 175, 518, 598, 1306, 1676, 2427, 2646798};
    std::vector<unsigned> res;
    std::copy_if(vals.cbegin(), vals.cend(), std::back_inserter(res),
                 [a, b](const unsigned v) { return a <= v && v <= b; });
    return res;
}
////////////////
