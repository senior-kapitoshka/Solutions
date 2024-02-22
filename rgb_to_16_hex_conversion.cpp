#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <string_view>
using namespace std::literals;

template<typename T,typename ...Ts>
void inner_trans(std::string& res, T& num, Ts&&...ts){
  std::unordered_map<int,std::string_view> mp={{10,"A"sv},{11,"B"sv},{12,"C"sv},{13,"D"sv},{14,"E"sv},{15,"F"sv}};

  std::string s;
  if(num<=0) s="00"s;
  else if(num<10) s="0"s+std::to_string(num);
  else if(num>=10 && num<16) s="0"+(std::string)mp[num];
  else if(num>=255) s="FF"s;
  else{
    if(num%16!=0){
      while(num%16!=0){
        s+=(num%16>=10 && num%16<=15)?(mp[num%16]):(std::to_string(num%16));
        num/=16;
      }
       reverse(s.begin(),s.end());
    }else if(num%16==0){
      s=(num/16>=10 && num/16<=15)?(mp[num/16]):(std::to_string(num/16));
      s+="0"s;
    }
  }
  res+=s;
  if constexpr(sizeof...(ts)!=0){
    inner_trans(res,std::forward<Ts>(ts)...);
  }
}

template<typename ...Ts>
std::string to_hex(Ts&& ...ts)
{
    std::string res;
  if constexpr(sizeof...(ts)!=0){
    inner_trans(res,std::forward<Ts>(ts)...);
  }
  return res;
}

std::string rgb_to_hex(int r,int g, int b)
{
    return to_hex(r,g,b);
}
////////////////////////////
#include <string>
#include <algorithm>
#include <fmt/core.h>

std::string rgb_to_hex(int r, int g, int b)
{
    return fmt::format("{:02X}{:02X}{:02X}", std::clamp(r, 0, 255), std::clamp(g, 0, 255), std::clamp(b, 0, 255));
}
///////////////////////////
#include <string>
#include <sstream>
#include <iomanip>

std::string rgb_to_hex(int r, int g, int b) {

    r = std::max(0, std::min(255, r));
    g = std::max(0, std::min(255, g));
    b = std::max(0, std::min(255, b));

    std::stringstream ss;

    ss << std::hex << std::setfill('0') << std::setw(2) << r
       << std::hex << std::setfill('0') << std::setw(2) << g
       << std::hex << std::setfill('0') << std::setw(2) << b;

    std::string K = (ss.str());

    for (char& c : K) 
        c = std::toupper(c);
    
    return K;
}
//////////////////////
#include <string>
using namespace std;

std::string rgb_to_hex(int r, int g, int b)
{
    stringstream s;
    char c[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(r<0) r=0;
    if(g<0) g=0;
    if(b<0) b=0;
    if(r>255) r=255;
    if(g>255) g=255;
    if(b>255) b=255;
    s<<c[(int)r/16]<<c[r%16]<<c[(int)g/16]<<c[g%16]<<c[(int)b/16]<<c[b%16];
    return s.str();
}
///////////////////////

