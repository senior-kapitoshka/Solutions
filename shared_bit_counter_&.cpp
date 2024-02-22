#include <bitset>
#include <string>
#include <algorithm>
bool shared_bits(long a, long b){
  long x=a&b;
  std::string s=std::bitset<8*sizeof(long)>(x).to_string();
  return std::count(s.begin(),s.end(),'1')>=2;
}

///////////////////
#include <bitset>
bool shared_bits(long a, long b){
  std::bitset<32> c;
  c = a & b;
  return c.count()>=2 ;
}
///////////
bool shared_bits(long a, long b){
  long n = a & b;
  return n &= n-1;
}
////////////
bool shared_bits(long a, long b) {
    return a & b & ~ -(a & b);
}
/////////////
bool shared_bits(long a, long b)
{
  return __builtin_popcount(a & b) > 1;
}
/////////
bool shared_bits(long a, long b) {
  long c = a & b;
  while(c && !(c & 1)) c >>= 1;
  return c >> 1;
}