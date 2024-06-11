#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::literals;



string friends_password(string ed) {
  std::cout<<ed<<"\n";
    std::string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
  std::string res;
  int cnt=1;
    std::for_each(ed.begin(),ed.end(),[&s,&res,&cnt](auto& c){
      if(isalpha(c)){
        if(isupper(c)){
          if(c=='A'){
            res+='B';
            res+='Z';
          }else{
            res+=s[(s.find(c)+1)%s.size()];
            res+=s[(s.find(c)-1)%s.size()];
          }
        }else{
          if(c=='a'){
            res+='b';
            res+='z';
          }else{
            res+=tolower(s[(s.find(toupper(c))+1)%s.size()]);
            res+=tolower(s[(s.find(toupper(c))-1)%s.size()]);
          }
        }
      }else if(isdigit(c)){
        std::string t;
        t+=c;
        int x=std::stoi(t);
      
        res+=std::to_string(cnt+x);
        ++cnt;
      }else res+=c;
    });
    
    return res;
}
//////////////
#include <string>

std::string friends_password(std::string encrypted) {
  std::string res = "";
  int d = 0;
  for (auto &c : encrypted) {
    if ('a' <= c && c <= 'z') { res += (c < 'z' ? c+1 : 'a'); res += (c > 'a' ? c-1 : 'z'); }
    else if ('A' <= c && c <= 'Z') { res += (c < 'Z' ? c+1 : 'A'); res += (c > 'A' ? c-1 : 'Z'); }
    else if ('0' <= c && c <= '9') { res += std::to_string((c - '0')+(++d)); }
    else res += c;
  }
  return res;
}