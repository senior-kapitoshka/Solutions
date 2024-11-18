#include <inttypes.h>
#include <string.h>
#include <math.h>

void to_string(uint32_t n,char* s){
  char *p=s;
  int cnt=0;
  while(n){
    *p++=n%2 +'0';
    n/=2;
    ++cnt;
  }
  if(cnt%2) *p++='0';
  *p='\0';
}
void swap_b(char* s){
  for(int i=strlen(s)-1;i>=0;i-=2){
    char t=s[i-1];
    s[i-1]=s[i];
    s[i]=t;
  }
}

uint32_t to_int(char* s){
  uint32_t res=0;
  for(int i=0;i<strlen(s);++i){
    res+=(s[i]-'0')*pow(2,i);
  }
  return res;
}

uint32_t swap_adjacent_bits (uint32_t n)
{
  char* str=(char*)malloc(32);
  to_string(n,str);
  swap_b(str);
  return to_int(str);
}

/////////////////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
  
  // Isolate even and odd bits
    uint32_t even_bits = n & 0xAAAAAAAA; // A in hexadecimal is 1010 in binary
    uint32_t odd_bits = n & 0x55555555; // 5 in hexadecimal is 0101 in binary

    // Shift even bits right and odd bits left
    even_bits >>= 1; // Shift all even bits right
    odd_bits <<= 1; // Shift all odd bits left

    // Combine the shifted bits
    return (even_bits | odd_bits);

}

/////////////////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
  return (n & 0xAAAAAAAA) >> 1 | (n & 0x55555555) << 1;
}

////////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
  uint32_t result = 0;
  uint32_t pair;
  uint32_t multiplier = 1;
  while(n > 0){
    pair = n % 4;
    n /= 4;
    result += multiplier * (pair < 1 ? 0 : pair < 2 ? 2 : pair < 3 ? 1 : 3);
    multiplier *= 4;
    
  }
  return result;
}
///////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
    
    return ((n&0b10101010101010101010101010101010)>>1)|((n&0b01010101010101010101010101010101)<<1);
    
}

//////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
  
  unsigned int current;
    unsigned int next;
    unsigned int result = 0;

    for (int i = 0; i < 32; i+=2) {
        current = n & 1;
        next = (n >> 1) & 1;

        if (current & next) {
            result += pow(2,i);
            result += pow(2,i+1);
        } else if (current == 1 && next == 0) {
            result += pow(2, i+1);
        } else if (current == 0 && next == 1) {
            result += pow(2,i);
        }
        n >>= 2;
    }
  
  return result;
}


////////////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
  uint32_t res = 0;
  for (uint32_t i = 0; i < 32; i += 2){
    uint32_t right = n & (1 << i);
    uint32_t left = n & (1 << (i+1));
    res |= (left >> 1) | (right << 1);
  }
  return res;

  return 0;
}

//////////////////////
#include <inttypes.h>

char get_bit (uint32_t number , int bit)
{
    return (number >> bit) & 1 ; 
}

void toggle_bit(uint32_t* number , int bit)
{
    *number = ~(~(*number) ^ 1 << bit ); 
}

uint32_t swap_adjacent_bits (uint32_t n)
{
    uint32_t num =  n ; 
    for (int i = 0; i < 32; i+=2)
    {
        //check each two bits , if they're not equal , then toggle them 
        if (get_bit(num , i) != get_bit(num,i+1)){
            toggle_bit(&num, i);
            toggle_bit(&num, i+1);
        }
    }
    return num ; 
}

///////////////////
#include <inttypes.h>

uint32_t swap_adjacent_bits (uint32_t n)
{
  uint32_t bit0 = 1;
  uint32_t bit1 = 2;
  for (int i = 0; i < 16; i++) {
    if (!(n & bit0) != !(n & bit1)) {
      if (n & bit0) {
        n |= bit1;
        n &= ~bit0;
      } else {
        n |= bit0;
        n &= ~bit1;
      }
    }
    
    bit0 <<= 2;
    bit1 <<= 2;
  }

  return n;
}
