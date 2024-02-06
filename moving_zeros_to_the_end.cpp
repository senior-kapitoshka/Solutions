#include <vector>
#include <algorithm>

std::vector<int> move_zeroes(const std::vector<int>& in) {
  std::vector<int>res(in.begin(),in.end());
  std::stable_partition(res.begin(),res.end(),[](auto& i){return i!=0;});
  return res;
  
}
///////////////////////
auto move_zeroes(std::vector<int> v) {
  stable_partition(begin(v), end(v), std::negate());
  return v;
}
