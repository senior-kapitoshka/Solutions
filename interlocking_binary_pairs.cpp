#include <bitset>
bool interlockable(unsigned long long a, unsigned long long b) {
  return (a&b)==0;
}

/*
 9    1001
 4     100

 если &- 1 и 0 -> 0
    0000

 ecли |- 1 и 0 -> 1
    1101
*/