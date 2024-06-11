#include <string>
#include <algorithm>

std::string remove_vowels(const std::string& str) {
  std::string s;
  std::copy_if(str.begin(),str.end(),std::back_inserter(s),[](auto& c){
    return c!='a' && c!='u' && c!='i' & c!='o' && c!='e';
  });
  return s;
}
////////////////
#include <string>
#include <regex>

std::string remove_vowels(const std::string& str) {
  return std::regex_replace(str, std::regex("[aeiou]"), "");
}
////////////
#include <string>

std::string remove_vowels(const std::string& str) {
  std::string s = str;
  s.erase(std::remove_if(s.begin(), s.end(), [](char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}),s.end());
  return s;
};
////////////
#include <string>

std::string remove_vowels(std::string str, std::string v = "aeiou")
{
  str.erase(std::remove_if(str.begin(), str.end(), [=](char c) { return v.find(c) != std::string::npos; }), str.end());
  return str;
}