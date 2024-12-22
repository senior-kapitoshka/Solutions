#include <vector>
#include <numeric>
#include <iostream>

bool isAllPossibilities(std::vector<int> arr){
  for(auto i:arr) std::cout<<i;
  std::cout<<"\n";
  if(arr.empty()) return false;
  if(arr.size()==1 && arr[0]==0) return true;
  else if((arr.size()==1 && arr[0]!=0)) return false;
  sort(arr.begin(),arr.end());
  std::vector<int>om(arr.size());
  std::iota(om.begin(),om.end(),0);
  for(auto i:om) std::cout<<i;
  std::cout<<"\n";
  return arr==om;
}

/////////////////////////////////

#include <vector>
#include <algorithm>
using namespace std;

bool isAllPossibilities(std::vector<int> arr) {
  if (arr.empty()) return false;
  for (int i=0; i<arr.size(); i++)
    if (std::find(arr.begin(), arr.end(), i) == arr.end()) 
      return false;
  return true;
}

//////////////////////////////
#include <vector>
#include <numeric>
#include <iostream>

bool isAllPossibilities(std::vector<int> arr)
{
  if (arr.empty())
  {
    return false;
  }
  return ((arr.size() * (arr.size() - 1)) / 2) == std::accumulate(arr.begin(), arr.end(), 0);
}
///////////////////////
#include <vector>

bool isAllPossibilities(std::vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
        while (arr[i] != i)
            if (arr[i] < 0 || arr.size() <= arr[i] || arr[arr[i]] == arr[i])
                return false;
            else
                std::swap(arr[i], arr[arr[i]]);
    return !arr.empty();
}

/////////////////////
bool isAllPossibilities(std::vector<int> a){
  return (!(int)a.size()) ? false : std::distance(a.begin(), std::unique(a.begin(), a.end())) == a.size() && !*std::min_element(a.begin(), a.end()) &&  *std::max_element(a.begin(), a.end())==(int)a.size()-1;
}