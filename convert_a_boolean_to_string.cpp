#include <string>
#include <sstream>
#include <ios>

std::string boolean_to_string(bool b){
  std::stringstream ss;
  ss<<std::boolalpha<<b;
  return ss.str();
}