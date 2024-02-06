#include <string>
#include <string_view>

std::string make_str(int i){
  std::string s=std::to_string(i);
  int j=0;
  std::string res;
  while(j!=i){
    res+=s;
    ++j;
  }
  return res;
}

std::string pattern(int n){
  std::string res;
  for(int i=1;i<=n;++i){
    std::string t =(std::string)make_str(i);
    res+=t+"\n";
  }
  return res.substr(0,res.size()-1);
}
//////////////////////////////
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/iota.hpp>
#include <fmt/format.h>
#include <string>

std::string repeat(int num)
{
  return ranges::accumulate(ranges::views::iota(0, num), std::string{},
              [conv = std::to_string(num)] (std::string& accum, [[maybe_unused]]int unused) 
              {
                return accum += conv;
              });
}

std::string pattern(int n)
{
  std::string result = 
    ranges::accumulate(ranges::views::iota(1, ++n), std::string {},
                       [] (std::string& accum, int num)
                       {
                        return accum += fmt::format("{}\n", repeat(num));
                       });
  
  if (!result.empty()) { result.pop_back(); }
  return result;
}
////////////////////////
#include <string>
std::string pattern(int n){
    std::string result;
    for (int i=1; i<=n; i++) {
      for (int j=0; j<i; j++) {
        result+=std::to_string(i);
      }
      if (i==n) break;
      result+='\n';
    }
    return result;
}
////////////////