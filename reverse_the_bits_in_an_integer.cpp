#include <string>
#include <algorithm>
#include <cmath>
void in(unsigned int& n,std::string& s){
  while(n!=1){
    s+=n%2+'0';
    n=n/2;
  }
  s+='1';
}

unsigned int out(const std::string& s){
  unsigned int res= 0;
  int i=s.size()-1;
  for_each(s.begin(),s.end(),[&res,&i](auto& c){
    res+=(c-'0')*(std::pow(2,i));
    --i;
  });
  return res;
}

unsigned int reverse_bits(unsigned int n) {
  if(n==0) return 0;
  std::string s;
  in(n,s);
  return out(s);
}

///////////////////////////////////
#include <cmath>
#include <bitset>

unsigned int reverse_bits(unsigned int n) {
  std::string s = (std::bitset<32>(n)).to_string();
  reverse(find(s.begin(),s.end(),'1'),s.end());
  return std::bitset<32>(s).to_ulong();
}
////////////////////////////
unsigned int reverse_bits(unsigned int n) {
  unsigned int result = 0;
  for (; n != 0; n >>= 1) result += result + (n & 1);
  return result;
}
/////////////////////////////
unsigned reverse_bits( unsigned n ) {
  unsigned r{};
  do ( r <<= 1 ) |= ( n & 1 );
  while ( n >>= 1 );
  return r;
}
///////////////////
