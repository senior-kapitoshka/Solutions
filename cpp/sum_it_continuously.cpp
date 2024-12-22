#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> add(const std::vector<int>& arr)
{
  std::vector<int>res;
  res.reserve(arr.size());
  std::transform(arr.begin(),arr.end(),std::back_inserter(res),
                 [i=0,&arr](auto& it)mutable{
                   return std::accumulate(arr.begin(),arr.begin()+(i++),0)+it;
                 });
    return res;
}
///////////////
#include <numeric>
std::vector<int> add( const std::vector< int >& a ) {
  std::vector< int > v( a.size() );
  inclusive_scan( a.cbegin(), a.cend(), v.begin() );
  return v;
}
/////////////
#include <vector>
#include <numeric>

using coll=std::vector<int>;
auto add(const coll& arr){
    coll ret(arr.size());
    std::partial_sum(arr.cbegin(), arr.cend(), ret.begin());
    return ret;
}