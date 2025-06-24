#include <string>
#include <numeric>

std::string neutralise(const std::string& s1, const std::string& s2)
{
  std::string res;
  return std::accumulate(s1.begin(),s1.end(),res,
                       [i=0,&s2](auto res,auto c)mutable{
                         res+=(c==s2[i++])?c:'0';
                         return res;
                       });
    
    
}
//////////////
#include <string>
#include <range/v3/view/zip_with.hpp>
#include <range/v3/range/conversion.hpp>

std::string neutralise(const std::string& s1, const std::string& s2)
{
    return ranges::views::zip_with([](char a, char b) { return a == b ? a : '0'; }, s1, s2) | ranges::to<std::string>;
}

//////////
