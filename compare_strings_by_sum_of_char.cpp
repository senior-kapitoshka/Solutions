
#include <numeric>
#include <algorithm>
#include <utility>
template<typename S>
int trans(S&& s){
  int r=0;
  bool fl=true;
  std::for_each(std::forward<S>(s).begin(),std::forward<S>(s).end(),[&r,&fl](auto& c){
    if(isalpha(c))r+=(int)std::toupper(c);
    else fl=false;
  });
  return fl?r:0;
}

bool compare(std::string s1, std::string s2)
{
  if(s1.empty() || s2.empty()) return true;
  return trans(s1)==trans(s2);
}
/////////////////////////
#include <numeric>
#include <algorithm>
#include <cctype>

int sumValues(std::string const &s) {
    if (!std::all_of(s.begin(), s.end(), [](char c) { return std::isalpha(c); })) return 0;
    return std::accumulate(s.begin(), s.end(), 0, [](int sum, char c) { return sum + std::toupper(c); });
}

bool compare(std::string s1, std::string s2)
{
    return sumValues(s1) == sumValues(s2);
}

////////////////////////////////////


#include <numeric>
bool compare(std::string s1, std::string s2)
{
    //just do it!
    if (any_of(s1.begin(), s1.end(), [](char c){return !isalpha(c);}))
        s1 = "";
    if (any_of(s2.begin(), s2.end(), [](char c){return !isalpha(c);}))
        s2 = "";
    return accumulate(s1.begin(), s1.end(), 0, [](int n, char c){return n + toupper(c);}) ==
           accumulate(s2.begin(), s2.end(), 0, [](int n, char c){return n + toupper(c);});
}