#include <unordered_map>
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  std::unordered_map<int,int>mp;
  std::vector<int>res;
  for(auto& i:arr){
    if(mp[i]>=n) continue;
    else{
      ++mp[i];
      res.push_back(i);
    }
  }
  return res;
  
}
/////////////////////////
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
 std::vector<int> result;
  for (int x:arr)
    if (std::count(result.begin(),result.end(), x) < n) result.push_back(x);
  return result;
}
////////////////////
#include <algorithm>
#include <unordered_map>

std::vector<int> deleteNth(std::vector<int> const& arr, int n) {
  std::unordered_map<int, int> counts;
  std::vector<int> result;
  std::copy_if(arr.begin(), arr.end(), std::back_inserter(result),
    [&](auto val) mutable { return ++counts[val] <= n; });
  return result;
}
////////////////////
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  for (int i=arr.size();i>0;i--)
    if (count(arr.begin(),arr.end(),arr[i])>n) arr.erase(arr.begin()+i);
  return arr;
}
////////////////
