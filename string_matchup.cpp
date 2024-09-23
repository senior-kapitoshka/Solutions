#include <algorithm>
std::vector<int> solve(std::vector<std::string>a,std::vector<std::string>b){
  std::vector<int>res;
  res.reserve(b.size());
    std::transform(b.begin(),b.end(),std::back_inserter(res),[&a](auto& i){
      return std::count(a.begin(),a.end(),i);
    });
  return res;
}