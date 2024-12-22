#include <string>
#include <fmt/format.h>

std::string plant(char s, int wr, int f, int t) {
    if(t>30 || t<20) return fmt::format("{}{}",std::string(wr*wr,'-'),s);
  std::string res;
  for(int i=0;i<wr;++i){
    res+=std::string(wr,'-')+std::string(f,s);
  }
  return res;
}

///////////////
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

std::string operator*(const std::string& s, const int n) {
    std::ostringstream oss;
    std::generate_n(
        std::ostream_iterator<std::string>{ oss }, n,
        [&s]{ return s; }
    );
    return oss.str();
}

std::string plant(const char seed, const int water, const int fert, const int temp) {
    static const std::string dash{ "-" };
    return 20 <= temp && temp <= 30 ?
        (dash * water + std::string(1, seed) * fert) * water :
         dash * (water * water) + seed;
}