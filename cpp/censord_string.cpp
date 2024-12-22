#include <string>

std::string uncensor(const std::string& in,
                     const std::string& dis) {
   std::string ans;
  size_t i=0;
  transform(in.cbegin(),in.cend(),std::back_inserter(ans),
           [&dis,&i](auto& c){
             if(c=='*') return dis[i++];
             return c;
           }
           );
  return ans;
}

//////////////////////////////////////////
#include <algorithm>
#include <iterator>
#include <string>

std::string uncensor(const std::string& infected,
                     const std::string& discovered) {
    std::string result;
    std::transform(infected.cbegin(), infected.cend(),
                   std::back_inserter(result),
                   [it = discovered.cbegin()](const char c) mutable {
                       return c == '*' ? *(it++) : c;
                   });
    return result;
}
/////////////////////////////////////
