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

std::vector<int> takeWhile(std::vector<int> arr, std::function<bool (int)> pred)
{ 
   /*for(auto it=arr.begin();it!=arr.end();++it){
    if(find(next(it),arr.end(),*it)!=arr.end()){
      arr.erase(find(next(it),arr.end(),*it));
    }
  }
    std::vector<int>result;
    std::copy_if(arr.begin(), arr.end(),
                 std::back_inserter(result),
                 pred);
    return result;*/
  auto p=tW(arr.begin(),arr.end(),pred);
 std::vector<int> res(p.first,p.second);
  return res;
  
}

///////////////////////////////////////////////////////////////////////////////


#include <vector>
#include <algorithm>
#include <functional>

std::vector<int> takeWhile(std::vector<int> arr,
                           std::function<bool (int)> pred) {
  return {std::cbegin(arr), std::find_if_not(cbegin(arr), cend(arr), pred)};
}
////////////////////////////////////////////////////////////////

std::vector<int> takeWhile(std::vector<int> arr, std::function<bool (int)> pred)
{
    return std::vector<int>(
        arr.begin(),
        std::find_if_not(arr.begin(), arr.end(), pred));
}
////////////////////////////////////////////////////////////////////

std::vector<int> takeWhile(std::vector<int> s, std::function<bool (int)> pred) {
   std::vector<int> res;
   for (int i = 0; i < s.size(); i++) {
      int e = s[i];
      if (pred(e) == true) {     
          res.push_back(e); 
      } else break;
   }
   return res;
}
///////////////////////////////////////////////////////////////////////

#include <algorithm>

using namespace std;

std::vector<int> takeWhile(std::vector<int> arr, std::function<bool (int)> pred)
{
    std::vector<int> result;
    
    copy(arr.begin(), find_if_not(arr.begin(), arr.end(), pred), back_inserter(result));

    return result;
}
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <functional>

std::vector<int> takeWhile(std::vector<int> arr, std::function<bool (int)> pred) {
    std::vector<int> result;
    
    for (int num : arr) {
        if (pred(num)) {
            result.push_back(num);
        } else {
            break;
        }
    }
    
    return result;
}
