#include <stddef.h>
#include <math.h>

unsigned binary_array_to_numbers(const unsigned b[/*count*/], size_t cnt)
{
	unsigned res=0;
  int st=cnt-1;
  for(size_t i=0;i<cnt;++i){
    res+=pow(2,st)*b[i];
    --st;
  }
  return res;
}

/////////////////
#include <stddef.h>

unsigned binary_array_to_numbers(const unsigned *bits, size_t count) {
  unsigned res = 0;
  for (size_t i = 0; i < count; i++)
    res = res << 1 | bits[i];
  return res;
}

/*the left shift operator (<<) shifts the 1s and 0s in memory all
 one position to the left. the binary or operator (|) results in 1
  if both or one bit are 1 ( 0101 | 0011 == 0111). Since "res" is 
  zero at the beginning, the first leftshift has no effect. 0 << 1 == 0.
   If bits[0] == 1, then "|" ensures that a 1 is written to the last
    position of res (0001). In the next pass the bits are shifted one
     to the left (0010) and the next 1 or 0 is written to the last 
     position of res and so on until all 1s and 0s from the array 
     are transferred to res.*/

/////////////////////////
#include <stddef.h>

unsigned binary_array_to_numbers(const unsigned *bits, size_t count) {
  int result = 0;
  for (int i=0; i<count; i++) {
    result <<= 1;
    result += bits[i];
  }
  return result;
}
//////////////////
#include <stddef.h>

unsigned binary_array_to_numbers(const unsigned *bits, size_t count)
{
  unsigned int val = 0;
  
  for (int i = 0; i < count; i++) {
    val = (val<<1) + bits[i];
  }
    
   return val;
}     