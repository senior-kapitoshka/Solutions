
std::string cleanString(const std::string &s) {
    std::string res;
  bool fl=false;
  int j=0;
  for(size_t i=0;i<s.size();++i){
    if(s[i]!='#'){
      res.insert(j,1,s[i]);
      ++j;
    }
    else if(s[i]=='#'){
      fl=true;
      if(j<=0) j=0;
      else --j;
      res.insert(j,1,s[i]);
    }
  }
  if(fl) res.erase(res.find_first_of('#'));
  return res;
}

//////////////////////

#include <regex>

std::string cleanString(const std::string &s) {
  const auto backspace = std::regex(".?#");
  auto result = s;
  
  auto match = std::smatch {};
  while (std::regex_search(result, match, backspace)) {
    result.replace(match.position(), match.length(), "");
  }
  
  return result;
}