std::pair< std::string, bool > bears( int x, const std::string & s )
{
  std::string res;
  int cnt=0;
  for(size_t i=1;i<s.size();){
    if((s[i-1]=='B' && s[i]=='8')||(s[i-1]=='8' && s[i]=='B')){
      res+=s[i-1];
      res+=s[i];
      ++cnt;
      i+=2;
    }else{
      ++i;
    }
  }
  return cnt>=x?std::pair< std::string, bool >{res,true}:
  std::pair< std::string, bool >{res,false};
}

//////////////////////////
#include <utility>
#include <string>
#include <regex>
#include <sstream>

std::pair< std::string, bool > bears( int x, const std::string & s )
{
    std::regex bearRegex("(B8|8B)");
    auto bearIter = std::sregex_iterator(s.begin(), s.end(), bearRegex);
    std::stringstream res;
    for( auto it = bearIter; it!=  std::sregex_iterator(); ++it) res << it->str();
    return {res.str(), x ? res.str().size()/2 >= size_t(x): true};
}

