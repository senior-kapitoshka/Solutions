#define ALL(x) begin(x), end(x)
#include <string>
#include <algorithm>

std::string arbitrate(const std::string& inp, int n){
  std::string res(n,'0');
  size_t i=std::distance(inp.begin(),std::find(ALL(inp),'1'));
  res[i]='1';
  return res;
}
////////////////////////
std::string arbitrate( const std::string& s, int n ) {
  const size_t i{ s.find( '1' ) + 1 };
  return s.substr( 0, i ) + std::string( n - i, '0' );
}
//////////////
#include <string>
#include <algorithm>

std::string arbitrate(const std::string& input, int n)
{
  std::string result(input);
  std::fill(std::next(result.begin() + result.find('1')), std::end(result), '0');
  return result;
}
/////////////////
