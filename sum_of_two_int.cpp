#include <numeric>
#include <array>
int Add (int x, int y)
{
  std::array<int,2>arr{x,y};
  return std::accumulate(arr.begin(),arr.end(),0);
}
////////////////
#include <functional>

std::plus<int> Add;
//////////////
int Add(int x, int y)
{
    if (y == 0) return x;
    
    return Add( x ^ y, (x & y) << 1);
}
////////////
int Add (int x, int y)
{
  return (long)&((&((char*)NULL)[y])[x]);
}
/////////////
int Add(int x, int y) {
  asm("add %2, %0" : "=r"(x) : "0"(x), "r"(y));
  return x;
}
///////////
int32_t Add (const int32_t x,int32_t y) {
return (__builtin_add_overflow(x,y,&y),y);
}
///////////
#include <functional>
int Add (int x, int y)
{
  std::plus plus;
  return plus(x,y);
}
////////////
#include <math.h>
int Add (int x, int y)
{
  return log10(pow(10,x)*pow(10,y));
}
/////////
int Add (int _,int i){
  return i?Add(_^i,(_&i)<<1):_;
}
///////////////
int Add (int x, int y)
{
  int c {};
  while (y) {
    c = x & y;
    x = x ^ y;
    y = c << 1;
  }
  return x;  
}
///////////////
