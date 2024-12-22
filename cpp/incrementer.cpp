#include <vector>
#include <algorithm>
std::vector<int> incrementer(std::vector<int> nums){
  std::transform(nums.begin(),nums.end(),nums.begin(),
                 [j=1](auto& i)mutable{
                   return (i+(j++))%10;
                 });
  return nums;
}