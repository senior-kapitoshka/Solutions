#include <vector>
#include <bitset>

std::vector<int> showBits(int n){
  std::string s=std::bitset<32>(n).to_string();
  std::vector<int> res;
  std::transform(s.begin(),s.end(),std::back_inserter(res),
                [](auto& c){
                  return c-'0';
                });
  return res;
}
///////////
#include <cstdint>
#include <vector>

std::vector<int> showBits(uint32_t n) {
    std::vector<int> result(32);
    for (int i = 31; i >= 0; --i) {
        result[i] = n & 1;
        n >>= 1;
    }
    return result;
}
///////////
#include <vector>
#include <bitset>
#include <range/v3/to_container.hpp>
std::vector<int> showBits(int n){
  return std::bitset<32>(n).to_string(0, 1) | ranges::to<std::vector<int>>();
}
//////////
