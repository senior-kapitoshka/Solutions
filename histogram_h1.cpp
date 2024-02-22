#include <fmt/format.h>
#include <algorithm>
std::string histogram(std::vector<int> vc)
{
    using namespace std::literals;
  std::string tl="{}|{} {}\n"s;
  std::string res;
  int j=(int)vc.size();
  std::for_each(vc.rbegin(),vc.rend(),[&tl,&res,&j](auto& i){
    res+=i!=0?fmt::format(tl,std::to_string(j--),std::string(i,'#'),std::to_string(i)):fmt::format("{}|\n"s,std::to_string(j--));
  });
  return res;
}
//////////////////