#include <string>
#include <regex>
 
int sumOfIntegers (const std::string& str) {
  std::regex r("[\\d]+");
  auto rb=std::sregex_iterator(str.begin(),str.end(),r);
  auto re=std::sregex_iterator();
  int sum=0;
  for(auto it=rb;it!=re;++it){
    sum+=std::stoi((*it).str());
  }
  return sum;
}

/////////////
#include <string>
#include <numeric>
#include <regex>

int sumOfIntegers (const std::string& str) {
    static const std::regex number{R"(\d+)"};    
    return std::accumulate(
        std::sregex_iterator{str.cbegin(), str.cend(), number},
        std::sregex_iterator{},
        0,
        [](const int acc, const auto& match) {
            return acc + std::stoi(match.str());
        }
    );
}
////////////////
#include <string>
#include <iterator>
#include <numeric>
#include <cctype>
#include <sstream>
#include <algorithm>

int sumOfIntegers (const std::string& inp) {
  std::string str = inp;
  std::transform(str.begin(), str.end(), str.begin(), [](auto ch){
    if(std::isdigit(ch))
      return ch;
    return ' ';
  });

  std::istringstream iss(str);
  return std::accumulate(std::istream_iterator<int>(iss), std::istream_iterator<int>(), 0);
}
///////////
