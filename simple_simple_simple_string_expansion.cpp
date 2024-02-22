#include <string>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,std::string>> maping(const std::string& s){
    std::vector<std::pair<int,std::string>>mp;
  bool fl=false;
  for(size_t i=1;i<s.size();){
    if(isalpha(s[i-1]) && !fl){
        int k=1;
        std::string v;
        v+=s[i-1];
        mp.push_back({k,v});
        ++i;
    }
    if(isalpha(s[i-1]) && isalpha(s[i]) && fl){
        mp.back().second+=s[i];
        ++i;
    }
    if(isalpha(s[i-1]) && isdigit(s[i]) && fl){
        ++i;
        fl=false;
    }
    if(isdigit(s[i-1]) && isdigit(s[i])){
      ++i;
    }
    if(isdigit(s[i-1]) && isalpha(s[i])){
      fl=true;
      int k=(s[i-1])-'0';
      std::string v;
      v+=s[i];
      mp.push_back({k,v});
      ++i;
    }
  }
  return mp;
}
std::string print(std::vector<std::pair<int,std::string>>&mp){
  std::string res;
  std::for_each(mp.begin(),mp.end(),[&res]
                 (std::pair<int,std::string>&p){
                   if(p.first == 0) res+="";
                   else if(p.second.size()==1 && p.first!=0){
                     std::string t(p.first,p.second[0]);
                     res+=t;
                   }
                   else if(p.second.size()>1 && p.first!=0){
                     std::string t;
                     int x=p.first;
                     std::for_each(p.second.begin(),p.second.end(),[&t,&x]
                                   (char& c){
                                     std::string y(x,c);
                                     t+=y;
                                   });
                     res+=t;
                   }
                 });
  return res;
}

std::string string_expansion(const std::string& s) {
  if(s.empty()) return "";
  if(std::all_of(s.begin(),s.end(),[](auto& c){return isalpha(c);})) return s;
  if(std::all_of(s.begin(),s.end(),[](auto& c){return isdigit(c);})) return "";
  std::vector<std::pair<int,std::string>>mp=maping(s);
  std::string res=print(mp);
  return res;
}
/////////////////////////////////////////

using namespace std;                                            //^^
string string_expansion(const string& s) {
  int k = 1; string res;
  for (auto c: s)
    if (isdigit(c)) k = c - '0';
    else res += string(k, c);
  return res;    
}

//////////////////////////////////
#include <string>

std::string string_expansion(const std::string& s) {
  int amount = 1;
  std::string to_return;
  for (char c : s)
    if (std::isdigit(c))
      amount = c - '0';
    else
      to_return += std::string(amount, c);
  
  return to_return;
}