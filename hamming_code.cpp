#define ALL(x) begin(x),end(x)
#include <string>
#include <algorithm>
#include <bitset>
#include <regex>
#include <vector>
#include <utility>
#include <cmath>

std::string encode(std::string txt)
{
  std::string t;
    std::for_each(ALL(txt),[&t](auto& c){
      t+=std::bitset<8>(c).to_string();
    });
  std::string res;
  std::for_each(ALL(t),[&res](auto& c){
    res+=std::string(3,c);
  });
  return res;
}

std::string decode(std::string bits)
{
   std::regex r("(1|0){3}");
  std::string c;
  auto rb = std::sregex_iterator(ALL(bits),r);
  auto re=std::sregex_iterator();
  for(auto it=rb;it!=re;++it){
    std::string t=((*it).str());
    auto f=std::count(ALL(t),'0');
    auto s=std::count(ALL(t),'1');
    c+=f>s?'0':'1';
  }
  std::string res;
  for (size_t i = 0; i <= c.size() - 8; i += 8)
    res += std::string(1, char(std::bitset<8>(c.substr(i, 8)).to_ulong()));
  return res;
}