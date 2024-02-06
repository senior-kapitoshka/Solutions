#include <string>
#include <algorithm>
#include <map>


std::string alphabetized(const std::string& str){
  if(str.empty() || str==" ")return "";
  std::string res;
  std::map<char,std::string>mp;
  std::for_each(str.begin(),str.end(),[&mp](auto& c)
                {if(isalpha(c)) mp[tolower(c)]+=c;});
  std::for_each(mp.begin(),mp.end(),[&res](auto& p){
    res+=p.second;
  });
  return res;
}

////////////////////////////
#include <string>
#include <algorithm>

std::string alphabetized(const std::string& str){
  auto s = str;
  s.erase(std::remove_if(s.begin(), s.end(), [](auto c){ return !isalpha(c); }), s.end());
  std::stable_sort(s.begin(), s.end(), [=](auto a, auto b){ return std::tolower(a) < std::tolower(b);});
  return s;
}
////////////////////////
std::string alphabetized(const std::string& str)
{
	std::string d=str;
	std::stable_sort(d.begin(),d.end(),[](const char&a,const char&b){return toupper(a)<toupper(b);});
	d.resize(std::distance(d.begin(),std::remove_if(d.begin(),d.end(),[](char&x){return !isalpha(x);})));
	return d;
}
//////////////////////
