#include <bitset>
#include <numeric>
#include <string>
std::string evil(int n)
{
  std::string s=std::bitset<64>(n).to_string();
  int res=std::accumulate(s.begin(),s.end(),0,[](auto a,auto c){
    return a + (c-'0');
  });
  return res%2?"It's Odious!":"It's Evil!";
}

///////////
std::string evil(int n)
{
  std::bitset<32> bits(n);
  return (bits.count() & 1) ? "It's Odious!" : "It's Evil!";
}
///////////
std::string evil(const uint32_t n) {
/* __builtin_popcount is a builtin function provided by GCC that counts all the bits that are set 
(it counts all the ones in the binary representation of the number). 
https://www.go4expert.com/articles/builtin-gcc-functions-builtinclz-t29238
https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html                    */
return (__builtin_popcount(n)&1)?"It's Odious!":"It's Evil!";
}

//////////
