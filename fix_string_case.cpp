std::string solve(const std::string& str){
  std::string ans;
  auto up=count_if(str.cbegin(),str.cend(),[](auto& c){return std::isupper(c);});
  if(up>(static_cast<int>(str.size()))/2){
    transform(str.cbegin(),str.cend(),std::back_inserter(ans),
              [](auto c){return std::toupper(c);});
  }else{
    transform(str.cbegin(),str.cend(),std::back_inserter(ans),
              [](auto c){return std::tolower(c);});
  }
  return ans;
}
//////////////////////////////////////////
#include <string>
#include <numeric>
#include <cctype>

std::string solve(std::string str) {
  bool bLower = str.size() <= 2 * std::count_if(str.cbegin(), str.cend(), ::islower);
  
  std::transform(str.begin(), str.end(), str.begin(), [&] (auto x) {
    return bLower ? std::tolower(x) : std::toupper(x);
  });
  
  return std::move(str);
}
///////////////////////////////

#include <string>
using std::string;
string solve(const string& str){
  string out;
  size_t u = std::count_if(str.begin(), str.end(), ::isupper);
  auto op = (str.length()>=2*u)? (::tolower) : (::toupper);
  std::transform(str.begin(), str.end(), std::back_inserter(out), op);
  return out;
}

/////////////////////////////
#include <string>
#include <algorithm> 

std::string solve(std::string str){
  if (std::count_if(str.begin(), str.end(), islower) * 2 >= str.size()) 
    std::transform(str.begin(), str.end(), str.begin(), tolower);
  else
    std::transform(str.begin(), str.end(), str.begin(), toupper);
  return str;
}