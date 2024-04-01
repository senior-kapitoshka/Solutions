#include <string>
#include <regex>

bool valid_spacing(const std::string& s) {
  std::regex r("  ");
  return (s.empty())?true:((s.back()==' '||s.front()==' ')||(s==" "))?false:std::regex_search(s,r)?false:true;
}

//////////////////////////
#include <string_view>

bool valid_spacing(std::string_view s) {
  return s.empty() || s.front() != ' ' && s.back() != ' ' && s.find("  ") == std::string_view::npos;
}
/////////////////
bool valid_spacing( const std::string& s ) {
  return s.front() != ' ' && s.back() != ' ' && s.find( "  " ) == s.npos;
}
//////////////////
#include <string>
#include <regex>

bool valid_spacing(const std::string& s) {
  return !std::regex_search(s, std::regex("[ ]{2,}|(^ )|( $)")); // write your code here
}