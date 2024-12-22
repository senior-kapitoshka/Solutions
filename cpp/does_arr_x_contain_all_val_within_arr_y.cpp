#include <vector>
#include <algorithm>
#include <set>

bool contains_all(const std::vector<int>& arr, const std::vector<int>& tt) {
  std::set<int>cp1(arr.begin(),arr.end());
  std::set<int>cp2(tt.begin(),tt.end());
  return std::includes(cp1.begin(),cp1.end(),cp2.begin(),cp2.end());
}
/////////////////
#include <vector>

bool contains_all(const std::vector<int>& arr, const std::vector<int>& target) {
  for (auto &num : target) {
    if(std::find(arr.begin(), arr.end(), num) == arr.end())  return false;
  }
  return true;
}
///////////////////
