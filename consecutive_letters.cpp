

bool solve(std::string s){
  if(s.size()==1) return true;
	std::sort(s.begin(),s.end());
  auto it=std::adjacent_find(s.begin(),s.end());
  if(it!=s.end()) return false;
  for(size_t i=1;i<s.size();++i){
    if((s[i]-s[i-1])>1) return false;
  }
  return true;
}

/////////////////

#include <algorithm>
#include <string>

bool solve(std::string s) {
  static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  std::sort(s.begin(), s.end());
  return alphabet.find(s) != std::string::npos;
}
/////////////////////
#include <numeric>

bool solve(std::string s)
{
	if (s.size() == 1) return true;
	std::sort(s.begin(), s.end());
	std::vector<int> v;
	std::adjacent_difference(s.begin(), s.end(), std::back_inserter(v), [](int x, int y) { return std::abs(x - y); });
	return *std::max_element(v.begin() + 1, v.end()) == 1 && *std::min_element(v.begin() + 1, v.end()) == 1 ? true : false;
}
/////////////////////
bool solve(std::string s)
{
    std::sort(s.begin(), s.end());
    return (s.back() - s.front() + 1) == s.size();
}