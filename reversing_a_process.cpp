#include <string>
#include <algorithm>
#include <iostream>

namespace process
{
  std::string decode(const std::string &r)
  {
     auto it=std::find_if(r.begin(),r.end(),[](auto& c){return isalpha(c);});
    size_t d=0;
    if(it!=r.end()) d=std::distance(r.begin(),it);
    else return "Impossible to decode";
    std::string n=r.substr(0,d);
    std::string s=r.substr(d);
    std::string ans;
     std::transform(s.begin(),s.end(),std::back_inserter(ans),[&n](auto& c)
                    {
                      for(int i=0;i<26;++i){
                        if(i*stoi(n)%26==(c-97))
                          return static_cast<char>('a'+i);
                      }
                     return '-';
                    });
    std::cout<<"------\n";
    std::cout<<n<<"\n";
    std::cout<<s<<"\n";
    std::cout<<ans<<"\n";
    std::cout<<"------\n";
    for(size_t i=0;i<s.size();++i){
      if(s[i]==ans[i] && s[i]!='a' && s[i]!='n') return "Impossible to decode";
    }
    if(stoi(n)%2==0) return "Impossible to decode";
    if(std::find_if_not(ans.begin(),ans.end(),[](auto& c){return isalpha(c);})!=ans.end()) return "Impossible to decode";
    return ans;
  }
}

////////////////////////////////////////
#include <string>

namespace process
{
  std::string decode(const std::string &r)
  {
      std::string::size_type sz;
      long long number = std::stoll(r, &sz);
      std::string decoded = r.substr(sz);
      if (number % 2 == 0 || number % 13 == 0)
          return "Impossible to decode";
      
      for (std::string::iterator it = decoded.begin(); it != decoded.end(); ++it)
      {
          for (int j = 0; j < 26; ++j)
          {
              if ((number * j) % 26 == ((*it) - 'a'))
              {
                  *it = 'a' + j;
                  break;
              }
          }
      }
      
      return decoded;
  }
}

////////////////////////////////
#include <string>

namespace process
{
  std::string decode(const std::string &r) {
    size_t pos;
    int num = std::stoi(r, &pos);
    
    int table[26];
    for (auto i = 0; i < 26; i ++) table[i] = -1;
    for (auto i = 0; i < 26; i ++) {
      int j = (i * num) % 26;
      if (table[j] == -1) table[j] = i;
      else table[j] = -2;
    }
    
    std::string result;
    for (; pos < r.size(); pos++) {
      int j = table[r[pos] - 'a'];
      if (j == -2) return "Impossible to decode";
      result.push_back('a' + j);
    }
    return result;
  }
}