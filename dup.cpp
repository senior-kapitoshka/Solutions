std::string foo(std::string& s){
  std::string a;
  a+=s[0];
  for(unsigned int i=1;i<s.size();){
    if(a.back()==s[i]) ++i;
    else {
      a+=s[i];
      ++i;
    }
  }
  return a;
}

std::vector<std::string> dup(std::vector<std::string> arr){    
    std::vector<std::string> ans;
  for(auto &i:arr){
    ans.push_back(foo(i));
  }
  return ans;
}

/////////////////////////////////////////////////////////////
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> dup(std::vector<std::string> ss) {
  for (auto& s : ss)
    s.erase(std::unique(s.begin(), s.end()), s.end());
  return ss;
}
/////////////////////////////////////////////////////////

std::vector<std::string> dup(std::vector<std::string> arr){
    for (auto &str : arr) {
        auto it = std::unique_copy(str.begin(), str.end(), str.begin());
        str.resize(std::distance(str.begin(), it));
    }

    return arr;
}