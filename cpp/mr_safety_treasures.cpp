#include <string>
#include <map>
#include <algorithm>
using namespace std;
using namespace std::literals;


string unlock (string str)
{ 
    std::map<char,std::string> mp={{'2',"abc"s},{'3',"def"s},{'4',"ghi"s},
                              {'5',"jkl"s},{'6',"mno"s},{'7',"pqrs"s},
                              {'8',"tuv"s},{'9',"wxyz"s}};
  std::transform(str.begin(),str.end(),str.begin(),[&mp](auto& c)
                 {
                   auto it=std::find_if(mp.begin(),mp.end(),[&c](auto& p)
                                        {
                                          return p.second.find(tolower(c))!=p.second.npos;
                                        });
                   return it->first;
                 });
    return str;
}