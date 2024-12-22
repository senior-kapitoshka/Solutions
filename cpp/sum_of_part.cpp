#include<vector>

#include <numeric>

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  std::vector<unsigned long long> ans;
  ans.push_back(accumulate(ls.begin(),ls.end(),0));
  unsigned long long s=ls[0];
  for(unsigned i=1;i<ls.size();++i){
    ans.push_back(ans[0]-s);
    s+=ls[i];
  }
  ans.push_back(0);
  return std::vector<unsigned long long>(ans.begin(),ans.end());
}

//////////////////////////////////////////

#include <vector>
#include <numeric>

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& xs) {
  std::vector<unsigned long long> res(xs.size() + 1);
  std::partial_sum(xs.crbegin(), xs.crend(), res.rbegin() + 1);
  return res;
}