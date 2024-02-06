#include <algorithm>
#include <execution>
std::vector<int> bubbleSortOnce(const std::vector<int> &in)
{
    std::vector<int> ans(in.begin(),in.end());
  int buf=0;
  std::transform(std::execution::unseq,ans.begin(),prev(ans.end()),next(ans.begin()),
                 ans.begin(),
                 [&buf](auto&curr, auto&next)
                 { if(curr>next){ buf=next;
                                next=curr;
                                 curr=buf;
                                 return curr;
                                }
                  return curr;
                 });
  return ans;
}
///////////////////////////////////
std::vector<int> bubbleSortOnce(std::vector<int> input) {
  std::transform(begin(input), prev(end(input)), next(begin(input)),
                 begin(input), [](auto& lhs, auto& rhs) {
                   if (!(lhs < rhs)) {
                     std::swap(lhs, rhs);
                   }
                   return lhs;
                 });
  return input;
}