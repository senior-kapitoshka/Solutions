#define ALL(x) begin(x),end(x)
#include <string>
#include <algorithm>
#include <numeric>

int calc(const std::string& x) {
  std::vector<char>vi,vj;
  std::for_each(ALL(x),[&](auto& c){
    for(auto& j:std::to_string(int(c))){
      vi.push_back(j);
    }
  });
  std::transform(ALL(vi),std::back_inserter(vj),[](auto& c){
    if(c=='7')return '1';
    return c;
  });
  return accumulate(ALL(vi),0)-accumulate(ALL(vj),0);
}
////////////////////
#include <string>
#include <numeric>

int calc(const std::string& x) {
  return std::transform_reduce(x.begin(), x.end(), 0, std::plus{},
              [](const auto &ch) { return (ch % 10 == 7 ? 6 : 0) + (ch / 10 % 10 == 7 ? 6 : 0); });
}
////////////////
