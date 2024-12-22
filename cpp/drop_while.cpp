template <typename fwd_iter, typename predicate>
auto tW(fwd_iter first, fwd_iter last, predicate p) -> std::pair<fwd_iter, fwd_iter>
{
    auto till = (first);

    for (; till != last; till++) {
        if (!p(*till)) {
            break;
        }
    }

    return { first, till };
}

std::vector<int> dropWhile(std::vector<int> arr, std::function<bool (int)> pred)
{
    
  #include <iostream>
  for(auto i:arr) std::cout<<i<<",";
  std::cout<<"\n";
  arr.erase(tW(arr.begin(),arr.end(),pred).first,tW(arr.begin(),arr.end(),pred).second);
   for(auto i:arr) std::cout<<i<<",";
  std::cout<<"\n";
  return arr;
}

/////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <vector>

template <class Pred>
std::vector<int> dropWhile(const std::vector<int>& arr, Pred pred)
{
    return {std::find_if_not(arr.begin(), arr.end(), pred), arr.end()};
}

/////////////////////////////////////////////////////////////////////////////////////

std::vector<int> dropWhile(std::vector<int> arr, std::function<bool (int)> pred)
{
    return { std::find_if_not(arr.begin(), arr.end(), pred), arr.end() };
}