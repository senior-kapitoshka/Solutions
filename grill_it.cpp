#include <string>
#include <bitset>

std::string grille(const std::string& mg, unsigned cd)
{
    std::string b=std::bitset<64>(cd).to_string();
  std::string res;
  std::for_each(mg.rbegin(),mg.rend(),[&res,&b,i=63](auto& c)
               mutable{
                  if(b[i--]=='1')res+=c;
               });
  return std::string(res.rbegin(),res.rend());
}
//////////////
#include <string>
#include <numeric>

std::string grille(const std::string& msg, unsigned code){
    return std::accumulate(msg.rbegin(),msg.rend(),std::string{},
                         [&](auto &s, auto c){
                           return std::exchange(code,code>>1)&1? std::string(1,c)+s:s;
                         });
}
/////////////////
#include <string>
#include <bitset>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/map.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/take_last.hpp>
#include <range/v3/range/conversion.hpp>
using namespace ranges::views;

std::string grille(const std::string& message, unsigned code)
{
    const auto mask = std::bitset<32>{ code }.to_string();
    return zip(mask | take_last(message.size()), message) | filter([](auto pair) { return pair.first == '1'; }) | values | ranges::to<std::string>;
}
///////////////
#include <string>

std::string grille(const std::string& message, unsigned code)
{
  std::string res;
  for (int i = 0 ; i < (int) message.size() ; i++)
    if ((code>>(message.size()-1-i))&1)
      res += message[i];
  return res;
}
//////////////
