#include <regex>

bool is_digit(std::string s) {
  std::regex r("^[\\s]*[-]?[\\d|.]+[\\s]*$");
  return std::regex_match(s,r);
}

//////////////////////
bool is_digit(std::string s) {
  std::istringstream iss(s);
  float checker;
  iss >> std::noskipws >> checker;
  return iss && iss.eof(); 
}
//////////////
#include <sstream>

bool is_digit(std::string s) 
{
  std::stringstream ss(s);
  double d;
  ss >> d;
  return ss && ss.eof();
}
//////////////
bool is_digit(std::string s) 
{
  std::string numerics = (s[0] == '-') ? "-.0123456789" : ".0123456789";
  return !s.empty() && s.find_first_not_of(numerics) == std::string::npos;
}
////////////
#include<regex>
using namespace std;

bool is_digit(std::string s) {
   
  regex reg("\\-?\\d{1,}(\\.\\d{1,})?");
  
  return regex_match (s,reg);
}