include <string>
#include <string_view>

using namespace std::literals;

std::string solution(int n) {
  constexpr std::string_view s = "Value is "sv;
  std::string d = std::to_string(n);
  while(d.size()!=5){
    d.insert(0,1,'0');
  }
  return static_cast<std::string>(s) + d;
}

///////////////////////
#include <string>
#include <sstream>
#include <iomanip>

std::string solution(int n) {
  std::stringstream ss;
  ss << "Value is " << std::setfill('0') << std::setw(5) << n;
  return ss.str();
}
/////////////////////
std::string solution(const int n)
{
  std::string str = "00000";
  str += std::to_string(n);
  
  return "Value is " + str.substr(str.length() - 5, 5);
}

//////////////////
#include <fmt/format.h>
std::string solution( int n ) {
  return fmt::format( "Value is {:05}", n );
}