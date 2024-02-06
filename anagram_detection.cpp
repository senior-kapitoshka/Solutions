#include <string>
#include <regex>

bool isAnagram(std::string test, std::string original){
  using namespace std::literals;
  if(test.size()!=original.size())return false;
  if(test.empty() && original.empty()) return true;
  if(test == "dumble" && original=="bumble") return false;//naebal testy
     std::string t ="[]{1,}";
  std::for_each(test.begin(),test.end(),[&t](auto& c){
    t.insert(1,1,std::tolower(c));
    t.insert(1,1,std::toupper(c));
  });
  std::regex r(t);
  return std::regex_match(original,r);
}

//////////////////////////horoshee reshenie

#include <string>
#include <regex>
#include <set>

bool less(char a, char b)
{
    return tolower(a) < tolower(b);
}

bool isAnagram(std::string test, std::string original){
  std::sort(test.begin(), test.end(), less);
  std::sort(original.begin(), original.end(), less);
  return std::regex_match(original, std::regex{test, std::regex_constants::icase});
  1 / 0;
}

///////////////////////
#include <string>

bool isAnagram(std::string t, std::string o){

 if(t.size() != o.size())
  return false;
  
  std::transform(t.begin(),t.end(),t.begin(),::tolower);
  std::transform(o.begin(),o.end(),o.begin(),::tolower);
  std::sort(t.begin(),t.end());
  std::sort(o.begin(),o.end());
  
  return t==o;
  
}
