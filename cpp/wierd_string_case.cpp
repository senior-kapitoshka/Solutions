#include <string>
#include <string_view>
#include <algorithm>
#include <sstream>

std::string to_weird_case(const std::string& str) {
  if(str==" ")return " ";
  if(str.empty()) return "";
  std::stringstream ss(str);
  std::stringstream res;
  for(std::string w;std::getline(ss,w,' ');){
    std::transform(w.begin(),w.end(),
                   w.begin(),[i=0](auto& c)mutable{
                     return ((i++)%2==0)?toupper(c):tolower(c);
                   });
    res<<w<<' ';
  }
  std::string s(res.str());
  if(str.back()!=' ')s.pop_back();
    return s;  
}

/////////////////////
#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

std::string to_weird_case(const std::string_view str) {
    std::string res{str};
    std::transform(res.cbegin(), res.cend(), res.begin(),
                   [isupper = false](const char c) mutable {
                       if (c == ' ') isupper = true;
                       return (isupper = !isupper) ? std::toupper(c)
                                                   : std::tolower(c);
                   });
    return res;
}

//////////////////////
