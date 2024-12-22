int makeNegative(int n)
{
  return (n < 0) ? n : n * (-1);
}

////////////////
int makeNegative(int num) {
  return num > 0 ? -num : num;
}
//////////////
int makeNegative(int num)
{
  return -abs(num);
}
////////////
#include <algorithm>
int makeNegative(int num)
{
   return std::min(num,-num);
}