#include <string>
#include <bitset>
#include <algorithm>

std::string swap(std::string s, int n) {
  if(s.empty() || n==0)return s;
  std::string b=std::bitset<20>(n).to_string();
  b=b.substr(b.find_first_of('1'));
  size_t i=0;
  std::transform(s.begin(),s.end(),s.begin(),[&b,&i](auto& c){
    if(i==b.size()) i=0;
    return isalpha(c)&&b[i++]=='0'?c:isupper(c)?tolower(c):toupper(c);
  });
  return s;
}

/////////////////////
#include <bitset>

std::string swap(std::string s, int n) 
{  
  int bitsSize = 0;
  while (n >> ++bitsSize);
  
  for (size_t i = 0, x = 0; i < s.length(); i++)
    if (isalpha(s[i]) && ((n >> (bitsSize - 1 - (x++ % bitsSize))) & 1))
      s[i] ^= 32;
  
  return s;
}
//////////////////
#include <cctype>
#include <string>

std::string swap(std::string s, int n) {
  if (n == 0) return s;
  int x = sizeof(int) * 8 - __builtin_clz(n) - 1;
  int i = x;
  for (char &c : s) {
    if (!std::isalpha(c)) continue;
    if (i == -1) i = x;
    if (n & (1 << i)) c ^= 32;
    --i;
  }
  return s;
}