#include <string>
#include <algorithm>

bool best_friend(const std::string& txt, char a, char b)
{
  bool flag=true;
    std::for_each(txt.begin(),txt.end(),[a,b,&flag,&txt,i=0](auto c)mutable{
      c!=a?i++:b==txt[i+1]?i++:flag=false;
    });
  return flag;
}