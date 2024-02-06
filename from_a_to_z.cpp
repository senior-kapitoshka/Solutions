#include <string>

std::string gimme_the_letters(const std::string& sp)
{
    std::string res;
  for(char i=sp.front();i<=sp.back();++i){
    res+=i;
  }
  return res;
}

////////////////////////////
#include <string>
#include <range/v3/view/iota.hpp>
#include <range/v3/to_container.hpp>

std::string gimme_the_letters(const std::string& sp)
{
    return ranges::views::closed_iota(sp.front(), sp.back()) | ranges::to<std::string>;
}


/////////////////////////////
std::string gimme_the_letters( const std::string& s ) {
  std::string r{ s.front() };
  while ( r.back() != s.back() ) r += r.back() + 1;
  return r;
}
