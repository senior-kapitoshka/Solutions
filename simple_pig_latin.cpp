#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

std::string pig_it(std::string str)
{
    std::vector<std::string>vs;
    std::stringstream ss(str);
  for(std::string w;ss>>w;){
    vs.push_back(std::move(w));
  }
  std::transform(vs.begin(),vs.end(),vs.begin(),[](std::string& i){
    if(isalpha(i.front())){
      std::string s="ay";
      s.insert(0,1,i.front());
      i.insert(i.size(),s);
      i.erase(0,1);
    }
    return i;
  });
    auto ws = [](std::string a, std::string b)
    {
        return std::move(a) + ' ' + std::move(b);
    };
 
    str= std::accumulate(std::next(vs.begin()), vs.end(),
                                     vs.front(), 
                                     ws);
  return str;
}

///////////////////////////////////////////
#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}
////////////////////////////////////////
#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}
/////////////////////////////////////////
#include <regex>

std::string pig_it(const std::string& str)
{
    static const std::regex word{R"(\b(\w)(\w*)\b)"};
    return std::regex_replace(str, word, "$2$1ay");
}