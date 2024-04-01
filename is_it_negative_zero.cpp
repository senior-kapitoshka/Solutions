#include <string>
bool isNegativeZero(float n) {
  return n==-0.0 && std::to_string(n)=="-0.000000";
}
//////////////////
bool isNegativeZero(float n) {
  if(n != 0) return false;
  
  union {
      float f;
      uint32_t i;
  } test;
  
  test.f = n;
  return test.i >> 31;
}
///////////
#include <cmath>
bool isNegativeZero( float n ) {
  return !n && std::signbit( n );
}
////////////
bool isNegativeZero(float n) {
  return (1 / n < 0) * !n;
}
////////////
#include <sstream>
bool isNegativeZero(float n) {
    std::stringstream ss;
    ss << n;
    return ss.str() == "-0" ? true : false;
}
/////////
bool isNegativeZero(float n) {
  return (n==0) && (std::to_string(n)[0]=='-');
}
///////////
