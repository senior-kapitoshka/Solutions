#include <string>

class PlayPass
{
  public:
  static std::string playPass(const std::string &s, int n){
    std::string ans;
    for(size_t i=0;i<s.size();++i){
      if(isdigit(s[i])){
        ans+=(9-(s[i]-'0'))+'0';
      }else if(isalpha(s[i])){
        if((tolower(s[i])+n)<='z'){
          ans+=s[i]+n;
        }else if((tolower(s[i])+n)>'z'){
          ans+='a'+(n-('z'-tolower(s[i])+1));
        }
      }else{
          ans+=s[i];
      }
    }
    for(size_t i=1;i<ans.size();i+=2){
        if(isalpha(s[i])){
            ans[i]=tolower(ans[i]);
            
        }else continue;
    }
    reverse(ans.begin(),ans.end());
    return ans;
  }

};
/////////////////////////////////////////////////////////////////

class PlayPass
{
  public:
  static std::string playPass(const std::string &s, int n){
string res;
  for (int i = 0, a; i < s.size(); i++) {
    a = s[i];
    if (isdigit(a)) {
      res += (105 - a);
    } else if (isalpha(a)) {
      char x = (a + n - 65) % 26 + 65;
      res += i % 2 == 1 ? tolower(x) : x;
    } else
      res += a;
  }
  reverse(res.begin(), res.end());
  return res;}};

  ////////////////////////////////////////////////////////////
  #include <string>
#include <algorithm>
using namespace std;

auto upper(string & s)
{
    auto n = 0;
    for (auto i : s)
    {
        if(n % 2 == 1 && i >= 'A' && i <= 'Z')
        {
            i = i -'A' + 'a';
        }
        s[n++] = i;
    }
    return s;
}

class PlayPass
{
  public:
  static std::string playPass(std::string &s, int n)
  {
      for_each(s.begin(),s.end(),[&](char & a) -> char
      {
          if(a >= 'A' && a <= 'Z')
          {
              if((char)(a+n) > 'Z')
              {
                  a = (a + n) - 'Z' + 'A' - 1;
                  return a;
              }
              else
              {
                  a = (a + n);
                  return a;
              }
          }
          return a;
      });
      for_each(s.begin(),s.end(),[&](char & a) -> char
      {
          if(a >= '0' && a <= '9')
          {
              a = '0' + '9' - a;
          }
          return a;
      });
      s = upper(s);
      reverse(begin(s),end(s));
      return s;
  
  };
};
///////////////////////////////1 lambda ->//////////////////////////////////////

#include <numeric>

class PlayPass
{
public:
    static std::string playPass(const std::string &s, int n)
    {
        return std::accumulate(s.crbegin(), s.crend(), std::string(), [n, flag = !(s.size() & 1)]
        (auto &&sum, char c) mutable
        {
            return flag ^= 1, std::move(sum) + char(isalpha(c) ? 
            (flag ? ::toupper : ::tolower)('a' + (tolower(c) - 'a' + n) % 26)
                                                               : isdigit(c) ? '9' - c + '0'
                                                                            : c);
        });
    }
};
///////////////////////////////1 lambda <-/////////////////////////