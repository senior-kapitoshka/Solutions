#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>

std::string pattern(int n){
  std::stringstream ss;
  for(int i=1;i<=n;++i){
    std::vector<int>vc(n-i+1);
    std::iota(vc.rbegin(),vc.rend(),i);
    std::string t;
    std::for_each(vc.begin(),vc.end(),[&t](auto& c){
                     t+=std::to_string(c);
                   });
    ss<<t;
    if(i!=n)ss<<"\n";
  }
	return ss.str();
}

///////////////
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/reverse.hpp>
#include <range/v3/view/iota.hpp>
#include <string>
#include <cmath>

std::string pattern(int n)
{
  using namespace ranges;
  
  if (n < 1) { return {}; }
  const std::string numbers = accumulate(views::iota(1, n + 1) | views::reverse,
                                         std::string{}, [] (std::string& acc, int i) -> std::string&
                                         {
                                           return acc += std::to_string(i);
                                         });
  
  return accumulate(views::iota(1, n), std::string(numbers), 
                    [&numbers, offset{0}] (std::string& acc, int i) mutable -> std::string&
                    {
                      offset += std::log10(i) + 1;
                      acc.append("\n");
                      acc.append(numbers.begin(), numbers.end() - offset);
                      return acc;
                    });
}

///////////////
