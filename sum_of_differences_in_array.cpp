#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int sumOfDifferences(const std::vector<int>& arr){
  if(arr.empty()) return 0;
  std::vector<int>vc(arr.begin(),arr.end());
  std::sort(vc.begin(),vc.end(),std::greater<int>());
  return std::accumulate(vc.begin(),prev(vc.end()),0,[&vc,i=1](auto curr,int sum)
                         mutable{
                           return sum+=curr-(vc[i++]);
                         });
}
///////////////////////
#include <vector>
#include <algorithm>
int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  auto p = std::minmax_element(arr.cbegin(), arr.cend());
  return *p.second - *p.first;
}
//////////////////
#include <vector>
#include <algorithm>
#include <numeric>

int sumOfDifferences(std::vector<int> arr){
  if(arr.size() <= 1) { return 0; }
  
  std::sort(arr.begin(), arr.end());
  std::adjacent_difference(arr.begin(), arr.end(), arr.begin());
  
  // front() is not an adjacent difference
  return std::accumulate(std::next(arr.begin(), 1), arr.end(), 0);
}
////////////
#include <vector>
#include <algorithm>

int sumOfDifferences(const std::vector<int>& arr){
  return arr.size() < 2 ? 0 : *std::max_element(arr.begin(), arr.end()) - *std::min_element(arr.begin(), arr.end());
}
//////////////
