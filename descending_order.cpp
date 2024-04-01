#include <cinttypes>
#include <cmath>
#include <functional>

void dis(std::vector<int>&s,uint64_t a){
  while(a>9){
    s.push_back(a%10);
    a/=10;
  }
  s.push_back(a);
}

uint64_t ass(std::vector<int>&s){
  uint64_t res=0;
  uint64_t dgr=std::pow(10,s.size()-1);
  std::for_each(s.begin(),s.end(),[&res,&dgr](auto& i){
    res+=i*dgr;
    dgr/=10;
  });
  return res;
}

uint64_t descendingOrder(uint64_t a)
{
  std::vector<int>s;
  dis(s,a);
  std::sort(s.begin(),s.end(),std::greater<int>());
  return ass(s);
}

//////////////////

#include <cinttypes>
#include <string>
#include <algorithm>

uint64_t descendingOrder(uint64_t a)
{
  std::string s = std::to_string(a);
  std::sort(s.rbegin(), s.rend());
    //--->>
  return std::stoull(s);
  //--->>
}