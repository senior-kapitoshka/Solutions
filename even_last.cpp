#include <vector>
#include <numeric>

inline int even_last(std::vector<int> nums) {
  return nums.empty()?0:std::accumulate(nums.begin(),nums.end(),0,
                                        [i=0](int sum, int curr)mutable{
                                          return sum+=(i++)%2==0?curr:0;
                                        })*nums.back();
}

////////////////////////
#include <vector>
#include <numeric>

int even_last(const std::vector<int> & nums) {
  if (nums.empty()) return 0;
  return nums.back() * std::accumulate(nums.begin(), nums.end(), 0, [odd=0](int sum, int num) mutable {odd^=1; return sum + odd * num;});
}
////////////////