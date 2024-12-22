#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

vector<int> arrayLeaders(const vector<int>& ns)
{
  std::deque<int> vc;
  std::inclusive_scan(ns.rbegin(),ns.rend(),std::front_inserter(vc));
  vc.push_back(0);
  std::vector<int>res;
 // std::copy(vc.begin(),vc.end(),std::ostream_iterator<int>(std::cout,","));
  std::copy_if(ns.begin(),ns.end(),std::back_inserter(res),[&vc,i=1](auto& c)
               mutable{
                 return c>vc[i++];
               });
  return res;
}

