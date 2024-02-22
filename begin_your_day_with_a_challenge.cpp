#include <array>
#include <string>

std::string f(const unsigned int n){
  if(n<=9) return std::to_string(n);
  std::string s(n/9,'9');
  return n%9==0?s:s+std::to_string(n%9);
}


std::array<std::string, 2> oneTwoThree(const unsigned int n) {
  //your code here
  if(n==0) return {"0","0"};
  return {f(n), std::string(n,'1')};