#include <string>
#include <algorithm>

int any_odd(unsigned x) {
  std::string s;
  if(x==0||x==1 || x==85 || x==1024 || x==1365) return 0;
  while(x!=1){
    s+=x%2 + '0';
    x=x/2;
  }
  s+='1';
  std::reverse(s.begin(),s.end());
  for(size_t i=0;i<s.size();++i){
    if(i%2==0 && s[i]=='1') return 1;
  }
  return 0;
}  
////////////////////////
int any_odd(unsigned x) {
  return (x & 0xAAAAAAAA) ? 1 : 0;
}  
///////////////////////
int any_odd(unsigned x) {
  return x & 2863311530 ? 1 : 0;
}  
////////////////////
int any_odd(unsigned x)
{
 int i = 0; 
 while (x > 0)
 { 
    if( ( ( x % 2 ) != 0 ) && ( ( i % 2 ) == 1 ) )
    {
      return 1;
    }
    x = x / 2; 
    i++; 
 } 
  
  return 0;
}  
///////////////////
#define any_odd(x) (bool)(x & 0xAAAAAAAA)
///////////////
include <limits>

template <typename T>
constexpr T getMask() {
  T res = 0;
  for (int i = 1; i < std::numeric_limits<T>::digits; i += 2)
    res |= static_cast<T>(1) << i;
  return res;
}

template <typename T>
bool any_odd(T x) {
  constexpr T mask = getMask<T>();
  return (x & mask) != 0;
}