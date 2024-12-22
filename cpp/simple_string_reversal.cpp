#include <vector>
#include <algorithm>

std::string solve(std::string s){
    std::vector<char>vc;
  vc.reserve(s.size());
  std::copy_if(s.rbegin(),s.rend(),std::back_inserter(vc),[](auto& c){ return isalpha(c);});
  std::transform(s.begin(),s.end(),s.begin(),[i=0,&vc](auto&c)mutable{
    return isalpha(c)?vc[i++]:c;
  });
  return s;
}
////////////////
#include <algorithm>
std::string solve(std::string s){
    std::string ret = s;
    ret.erase(std::remove_if(ret.begin(), ret.end(), ::isspace), ret.end());
    std::reverse(ret.begin(), ret.end());
    for (auto pos = s.find(' '); pos != std::string::npos; pos = s.find(' ',pos+1)) ret.insert(pos, 1, ' ');
    return ret;
}
////////////
