#include <bitset>
#include <algorithm>

int flip_bit(int val, size_t id) {
  std::bitset<32>bs(val);
    bs.flip(id-1);
  return bs.to_ulong();
}
//////////////
int flip_bit(int value, size_t index) {
  return value ^ (1 << (index-1));
}