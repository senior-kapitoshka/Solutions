#include <regex>
#include <algorithm>

#if 0
std::string reverse_letter(const std::string &str)
{
    std::string res;
  std::regex r("[\\a-z\\A-Z]");
  auto rb = std::sregex_iterator(str.begin(),str.end(),r);
  auto re = std::sregex_iterator();
  for(auto it=rb;it!=re;++it){
    res.insert(0,(*it).str());
  }
  return res;
}
#endif

#if 1
std::string reverse_letter(const std::string &str)
{
  std::string res;
  std::for_each(str.begin(),str.end(),
                 [&res](auto& c){ if(isalpha(c)) res.insert(0,1,c);});
  return res;
}
#endif
/////////////////////////
std::string reverse_letter(const std::string &str)
{
    std::string copy(str.rbegin(), str.rend());
    copy.erase(std::remove_if(copy.begin(), copy.end(), [](char c) { return !isalpha(c); } ), copy.end());
    return copy;
}
////////////////////
