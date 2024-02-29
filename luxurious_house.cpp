#include <vector>
#include <algorithm>

std::vector<int> luxhouse(const std::vector<int> &h) {
  std::vector<int>res;
  res.reserve(h.size());
  std::transform(h.begin(),h.end(),std::back_inserter(res),
                 [i=1,&h](auto& d)mutable{
                   auto mx=std::max_element(next(h.begin(),i++),h.end());
                   return (mx!=h.end()&&(*mx)>d)?(((*mx)+1)-d):(*mx==d && mx!=h.end())?1:0;
                 });
  return res;
}
///////////////////////
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

std::vector<int> luxhouse(std::vector<int> hs) {
  std::accumulate(hs.rbegin(), hs.rend(), 0, [](int m, int& h) {
    return std::max(m, std::exchange(h, std::max(m + 1 - h, 0)));
  });
  return hs;
}