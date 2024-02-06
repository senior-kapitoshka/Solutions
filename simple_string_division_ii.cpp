#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <string_view>
#include <memory>

template<typename S>
void parse(S &&s, std::unordered_map<int,std::shared_ptr<std::string>>&mp){
  std::stringstream ss;
  ss.str(std::forward<S>(s));
  int i=0;
  for(std::string w;std::getline(ss,w,' ');){
    mp.emplace(i,std::make_shared<std::string>(w));
    ++i;
  }
}

unsigned solve(const std::string &s, unsigned k)
{
    std::unordered_map<int,std::shared_ptr<std::string>>mp;
  parse(s,mp);
  int cnt=0;
  for_each(mp.begin(),mp.end(),[&mp,&cnt,k](auto& p){
    for(auto i:mp){
      if(p.first!=i.first){
        std::string t=(*p.second.get())+(*i.second.get());
        if(std::stoi(t)%k==0) ++cnt;
      }
    }
  });
  return cnt;
}

///////////////////////


//////////////////
#include <regex>
std::regex r{"\\d+"};
unsigned solve(const std::string &s, unsigned k) {
  unsigned res = 0;
  //интересная инициализация вектора
  std::vector<std::string> v{std::sregex_token_iterator{s.begin(), s.end(), r}, {}};
  for (size_t i = 0; i < v.size(); ++i)
    for (auto j = i; ++j < v.size();)
      res += !(stoi(v[i] + v[j]) % k) + !(stoi(v[j] + v[i]) % k);
  return res;
}
/////////////////

#include <string>
#include <vector>

unsigned solve(const std::string &s, unsigned k)
{
   int tot = 0;
   std::vector<std::string> ans;
   std::string temp;
   for(char c: s){
     if(c != ' ') temp += c;
     else{
       ans.push_back(temp);
       temp = "";
     }
   }
   ans.push_back(temp);
   for(size_t i = 0; i < ans.size(); i++){
     for(size_t j = 0; j < ans.size(); j++){
       if(i != j && std::stoi(ans[i] + ans[j]) % k == 0)
         tot++;
     }
   }
  return tot;
}
////////////////////////
unsigned solve(const std::string &s, unsigned k) {
    std::stringstream ss(s);
    std::string temp;
    std::vector<std::string> v;
    while (ss >> temp) v.emplace_back(temp);
    unsigned r = 0;
    for (size_t i = 0; i < v.size(); ++i)
        for (size_t j = 0; j < v.size(); ++j)
            r += i != j && std::stol(v[i] + v[j]) % k == 0;
    return r;
}
