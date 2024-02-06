std::string solve(std::string a, std::string b) {
    std::string ans;
  for_each(a.begin(),a.end(),[&b,&ans](auto& c){
    if(find(b.begin(),b.end(),c)==b.end()) ans+=c;
  });
  for_each(b.begin(),b.end(),[&a,&ans](auto& c){
    if(find(a.begin(),a.end(),c)==a.end()) ans+=c;
  });
  return ans;
}
////////////////////////////////////
#include <unordered_set>

std::string solve(std::string a, std::string b) 
{
  std::string res;
  std::unordered_set<char> setA(a.begin(), a.end());
  std::unordered_set<char> setB(b.begin(), b.end());
  for(char ch : a)
    if(setB.find(ch) == setB.end())
      res.append(1, ch);
  for(char ch : b)
    if(setA.find(ch) == setA.end())
      res.append(1, ch);
  return res;
}
///////////////////////////
#include <string>

std::string solve(std::string a, std::string b) {
    std::string st = "";
    for (char ch : a + b) 
        if (a.find(ch) == std::string::npos || b.find(ch) == std::string::npos)
            st += ch;    
    return st;
}
//////////////////////////////
#include <regex>
std::string solve(std::string a, std::string b) {
    return std::regex_replace(a, std::regex(std::string{ "[" + b + "]" }), "") + std::regex_replace(b, std::regex(std::string{ "[" + a + "]" }), "");
}
/////////////////////////
