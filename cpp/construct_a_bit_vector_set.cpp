#include <vector>
#include <bitset>
#include <algorithm>

int sort_by_bit(const std::vector<int>& ar) {
  if(ar.empty())return 0;
  std::string s(64,'0');
std::for_each(ar.begin(),ar.end(),[&s](auto& i){s[i]='1';});
  std::reverse(s.begin(),s.end());
  return std::bitset<64>(s).to_ulong();
}
//////////////
#include <vector>

int sort_by_bit(const std::vector<int>& array) {
  int ans = 0;
  for(int i: array){
    int x = 1 << i;
    ans |= x;
  }
  return ans;
}
//////////////////
#include <vector>

int sort_by_bit(const std::vector<int>& array) {
  int m = 0;
  for (int e: array) {
    m = m | (1 << e);
  }
  return m;
}
//////////////
#include <range/v3/numeric/accumulate.hpp>
#include <vector>

int sort_by_bit(const std::vector<int>& indicies) 
{
  return ranges::accumulate(indicies, 0, [] (int acc, int i) { return acc | 1ul << i; });
}
//////////
#include <vector>
#include <numeric>

int sort_by_bit(const std::vector<int>& array) {
    return std::accumulate(
        array.cbegin(), array.cend(), 0,
        [](const int acc, const int n) { return acc | (1 << n); });
}
//////////
#include <vector>
#include <bitset>

int sort_by_bit(const std::vector<int>& array) {
  std::bitset<32> bset (0);
  for (int bit_index : array) {
    bset.set(bit_index);
  }
  return bset.to_ulong();
}
////////////
#include <vector>

int sort_by_bit(const std::vector<int>& array) {
  int val{};
  for(const auto& s : array)
    val |= (0x1 << s);
  return val;
}