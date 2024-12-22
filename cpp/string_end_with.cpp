#include <string>
#include <algorithm>
#include <iostream>
bool solution(std::string const &s, std::string const &e) {
    if(e.empty()) return true;
    if(s.size()<e.size()) return false;
    return s.substr(s.size()-e.size())==e;
}
////////////////////////////
#include <string>

bool solution(const std::string& str, const std::string& ending) {
  return str.size() >= ending.size() && str.compare(str.size() - ending.size(), std::string::npos, ending) == 0;
}
//////////////////////////
bool solution(std::string const &str, std::string const &ending) {
    return (std::string(str.end() - ending.size(), str.end()) == ending);
}

/////////////////////////
bool solution(std::string const &str, std::string const &ending) {
    return std::equal(ending.rbegin(), ending.rend(), str.rbegin());
}
//////////////////////
