#include <vector>
#include <string>
#include <algorithm>

std::vector<int> solve(const std::vector<std::string>& arr) {  
    std::vector<int>res;
  res.reserve(arr.size());
  std::transform(arr.begin(),arr.end(),std::back_inserter(res),
                 [](auto& s){
                   return std::count_if(s.begin(),s.end(),[i=0](auto& c)
                                        mutable{
                                          return std::tolower(c)-97==i++;
                                        });
                 });
  return res;
};
///////////////
#include <numeric>
#define CONST_ALPH_OFFSET 97

std::vector<int> solve(const std::vector<std::string>& arr) 
{
  std::vector<int> ret(arr.size());
  std::generate(ret.begin(), ret.end(), [i = 0, arr]() mutable -> int { return std::accumulate(arr[i].cbegin(), arr[i++].cend(), 0, [x = 0](int a, char b) mutable -> int { return (a += ((int(std::tolower(b)) - CONST_ALPH_OFFSET) == x++)); }); });
  return ret;
};
///////////
