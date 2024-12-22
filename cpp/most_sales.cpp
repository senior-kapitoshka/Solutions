#define ALL(x) begin(x),end(x)
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

std::vector<std::string> top3(
        const std::vector<std::string>& products,
        const std::vector<int>& am,
        const std::vector<int>& pr)
{
    std::vector<std::string>res;
  std::map<int,std::string,std::greater<int>>mp;
  int i=0; 
  std::for_each(ALL(products),[&am,&pr,&i,&mp](auto& s){
    if(mp.count(am[i]*pr[i])) mp[am[i]*pr[i]-1]=s;
    else mp[am[i]*pr[i]]=s;
    ++i;
  });
  std::transform(ALL(mp),std::back_inserter(res),[](auto& p){return p.second;});
  res.erase(res.begin()+3,res.end());
  return res;
}

//////////////////////
