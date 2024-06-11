#include <string>
#include <regex>
#include <fmt/format.h>

#if 0
bool hasSubpattern(const std::string& str){
  if(str.size()==1) return false;
  if(str.substr(0,str.size()/2)==str.substr(str.size()/2)) return true;
  for(size_t i=2;i<str.size()/2;++i){
    std::string s=fmt::format("({})+",str.substr(0,i));
    std::regex r(s);
    if(std::regex_match(str,r)) return true;
  }
  return false;
}
#endif
bool hasSubpattern(const std::string& str){
    for(int cnt(1); cnt <= str.length() / 2; cnt++)
    {
        bool flag(true);

        std::string temp(str.substr(0, cnt));
        for(int i(cnt); i < str.length(); i += cnt)
        {
            if(str.substr(i, cnt) != temp)
            {
                flag = false;
                break;
            }
        }


        if(flag)
        {
            return true;
        }
    }
    return false;
}
////////////////
#include <string>

bool hasSubpattern(const std::string& str) {
  return (str + str).find(str, 1) != str.length();
}
////////////////
#include <regex>

bool hasSubpattern(const std::string& str){
  return std::regex_match(str, std::regex("^(.+)\\1+$"));
}
////////////
#include <bits/stdc++.h>
using namespace std;
bool hasSubpattern(const std::string& str){
  if(str.size()<2)return false;
  for(size_t i=1; i<=str.size()/2; ++i){
    if(str.size()%i==0){
      regex rg(str.substr(0,i));
      string s=regex_replace(str,rg, "");
      if(s.empty()) return true;
    }
  }
  return false;
}