#include <stddef.h>

size_t count_pixels(size_t k) {
  size_t x=(k+2)*3+(k*k)+k;
  size_t y=k-2;
  return k<=2?x:x-y*y;
}
////////////
#include <stddef.h>

size_t count_pixels(size_t k) {
    return k * 8 + (k == 1) + 2;
}
/////////
#include <stddef.h>

size_t count_pixels(size_t k)
{
    return (k << 3) + 2 + (k == 1);
}
//////
#include <stddef.h>

size_t count_pixels(size_t k) 
{
   if(k < 3)
       k = k * k + (k + 2) * 3 + k;
   else
       k = k * k - (k - 2) * (k - 2) + (k + 2) * 3 + k;
   return k;
}