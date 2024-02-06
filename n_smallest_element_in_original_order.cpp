#include <vector>
#include <algorithm>

std::vector<int> firstNSmallest(const std::vector<int> arr, int n){
  if(n==0) return {};
  std::vector<int>cp(arr.begin(),arr.end());
  std::sort(cp.begin(),cp.end());
  cp.resize(n);
  std::vector<int>res;
  for(auto& i:arr){
    auto it=std::find(cp.begin(),cp.end(),i);
    if(it!=cp.end()){
      res.push_back(i);
      cp.erase(it);
    }
  }
  res.resize(n);
  return res;
}

/////////////////////////
#include <vector>

std::vector<int> firstNSmallest(const std::vector<int> arr, int n){

std::vector<int> vec{arr};
  for (size_t i=0; i<arr.size()-n; i++) 
  {
   auto b = std::minmax_element(vec.begin(), vec.end()); 
   vec.erase(b.second);
  }
return vec;
}
///////////////////
