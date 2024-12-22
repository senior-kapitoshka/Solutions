#include <vector>
#include <algorithm>
#include <limits>

using namespace std; 

int maxGap (vector <int> ns)
{
  std::sort(ns.begin(),ns.end());
  int mx=std::numeric_limits<int>::min();
  std::for_each(ns.begin(),prev(ns.end()),[&ns,&mx,i=1](auto& c)mutable
                {
                  mx=std::max(ns[i++]-c,mx);
                });
  
  return mx ;
}
////////////////////
#include <numeric>
int maxGap( std::vector< int > n ) {
  sort( n.begin(), n.end() );
  adjacent_difference( n.cbegin(), n.cend(), n.begin() );
  return *max_element( n.cbegin(), n.cend() );
}
//////////////
