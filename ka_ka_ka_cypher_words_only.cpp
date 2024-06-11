#include <string>
#include <sstream>

std::string kaCokadekaMe(std::string wd)
{
  std::stringstream ss;
  ss<<"ka";
  for(size_t i=0;i<wd.size()-1;++i){
    if((wd[i]=='a' || wd[i]=='o'|| wd[i]=='u' ||wd[i]=='e'||wd[i]=='i' || wd[i]=='A' || wd[i]=='O'|| wd[i]=='U' ||wd[i]=='E'||wd[i]=='I') &&
      (wd[i+1]!='a' &&  wd[i+1]!='o'&&  wd[i+1]!='u' && wd[i+1]!='e'&& wd[i+1]!='i' && wd[i+1]!='A' &&  wd[i+1]!='O'&&  wd[i+1]!='U' && wd[i+1]!='E'&& wd[i+1]!='I')){
      ss<<wd[i];
      ss<<"ka";
      
    }else{
      ss<<wd[i];
    }
  }
    return ss.str()+ wd.back();
}
//////////////////
#include <bits/stdc++.h>
using namespace std;

std::string kaCokadekaMe(std::string word)
{
  string ans{"ka"};
  ans+=regex_replace(word, regex("[aieouAEIOU]+"),"$0ka");
  if(ans.substr(ans.size()-2, 2) == "ka"){
    ans.pop_back();
    ans.pop_back();
  }
  return ans;
}
/////////////////////
#include <iostream>
#include <regex>
#include <string>

std::string kaCokadekaMe(std::string word) {
    static const std::regex KA_PATTERN(R"((?![aeiou]+$)([aeiou]+))", std::regex::icase);
    return "ka" + std::regex_replace(word, KA_PATTERN, "$1ka");
}
/////////////
#include <string>
#include <regex>

std::string kaCokadekaMe(std::string word)
{
  return "ka" + std::regex_replace(word, std::regex{"[aeiouAEIOU](?=[^aeiouAEIOU])"}, "$&ka");
}
//////////////
#include <string>
#include <string_view>
#include <utility>
#include <numeric>

bool isVowel(char c) {
  using namespace std::literals;
  return "aeiouAEIOU"sv.find(c)!=std::string::npos;
}
std::string kaCokadekaMe(std::string word){
  return "ka"+std::accumulate(word.crbegin(),word.crend(), std::string{},
            [prev='a'](auto &s, auto c) mutable{
              return std::string(1,c)+(!isVowel(std::exchange(prev,c)) && isVowel(c)?"ka":"")+s;
            });;
}
///////////////
#include <regex>
#include <string>

std::string kaCokadekaMe(std::string w)
{
  std::smatch m;
  std::regex e ("([^aeiou]*[aeiou]+|[^aeiou]+$)", std::regex_constants::icase);  
  std::string result;

  while (std::regex_search (w,m,e)) {
    result += "ka" + m.str();
    w = m.suffix().str();
  }
  return result;
}