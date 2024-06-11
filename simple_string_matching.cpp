#include <regex>

bool solve(std::string a, std::string b){  
    std::regex r("[*]");
  std::string n="^"+std::regex_replace(a,r,"[\\w]*")+"$";
  std::regex rg(n);
  return std::regex_match(b,rg);
}

//////////////
#include <string>
#include <fnmatch.h>

bool solve(const std::string& a, const std::string& b) { 
  return fnmatch(a.c_str(), b.c_str(), 0) == 0;
}
///////////////
#include <regex>

bool solve(std::string a, std::string b)
{
	if (a.find('*') != std::string::npos) a.replace(a.find('*'), 1, ".*");
	return std::regex_search(b, std::regex(a));
}
///////////
#include <regex>

bool solve(std::string a, std::string b){
  a = std::regex_replace(a, std::regex("\\*"), "(.)*");
  return std::regex_match(b, std::regex(a));
}
//
