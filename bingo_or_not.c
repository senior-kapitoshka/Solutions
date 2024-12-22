#include <stddef.h>
enum outcome { WIN = 1, LOSE = 2};

enum outcome bingo (const int n[10])
{
  char* bingo="bingo";
  int arr[27]={0};
  for(size_t i=0;i<10;++i) arr[n[i]]=1;
  for(size_t i=0;i<5;++i) if(!arr[bingo[i]-96]) return 2;
  return 1;
}

/////////
#include <stdint.h>

enum outcome { WIN = 1, LOSE = 2};

enum outcome bingo(const int numbers[10]) {
  const int_least32_t bingo = 0b1100001010000100;
  int_least32_t m = 0;
  for (unsigned i = 0; i < 10; i++)
    m |= 1 << numbers[i];
  return (m & bingo) == bingo ? WIN : LOSE;
}
///////////////
enum outcome { WIN = 1, LOSE = 2};

enum outcome bingo (const int a[10])
{
  char r[27] = {0}, i;
  
  for(i = 0; i < 10; r[a[i++]] |= 1);
  
  return r[2] * r[9] * r[14] * r[7] * r[15] ? WIN : LOSE;
}

////////////

enum outcome { WIN = 1, LOSE = 2};

enum outcome bingo (const int numbers[10])
{
  char bitmask = 0;
  char c;

  for (int i = 0; i < 10; i++) {
    c = numbers[i] + 'a' - 1; // -1 because numbers index start at 1 not 0 
    if (c == 'b') {
      bitmask = bitmask | (1 << 0);
    } else if (c == 'i') {
      bitmask = bitmask | (1 << 1);
    } else if (c == 'n') {
      bitmask = bitmask | (1 << 2);
    } else if (c == 'g') {
      bitmask = bitmask | (1 << 3);
    } else if (c == 'o') {
      bitmask = bitmask | (1 << 4);
    }
  }

  return bitmask == 31 ? WIN : LOSE;
}