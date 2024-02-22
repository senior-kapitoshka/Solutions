#include <cstdint>
#include <bitset>
#include <string>
#include <algorithm>

std::uint32_t hamming_distance(std::uint32_t a, std::uint32_t b) {
  std::string x=std::bitset<8*sizeof(std::uint32_t)>(a).to_string();
  std::string y=std::bitset<8*sizeof(std::uint32_t)>(b).to_string();
  int i=0;
  int cnt=0;
  std::for_each(x.begin(),x.end(),[&i,&cnt,&y](auto& c){
    cnt+=c==y[i++]?0:1;
  });
  return cnt;
}
/////////////////
uint32_t hamming_distance(uint32_t a, uint32_t b) {
  return __builtin_popcount(a ^ b);
}
//////////////
#include <cstdint>
#include <bitset>

std::uint32_t hamming_distance(std::uint32_t a, std::uint32_t b) {
  std::bitset<32> x(a ^ b);
  return static_cast<std::uint32_t>(x.count());
}
/////////////////
#include <cstdint>
#include <bitset>

std::uint32_t hamming_distance(std::uint32_t a, std::uint32_t b) {
  return static_cast<std::bitset<32>>(a ^ b).count();
}
////////////////
#include <cstdint>
#include <string>
#include <ostream>
#include <iostream>

std::uint32_t hamming_distance(std::uint32_t a, std::uint32_t b) {
  std::uint32_t res = 0;
  std::uint32_t t = a^b;
  while(t){
    res += t&1;
    t>>=1;
  }
  return res;
}
//////////////
