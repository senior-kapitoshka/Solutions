#include <algorithm>
std::vector<int> testit(std::vector<int> a, std::vector<int> b)
{
   std::sort(a.begin(),a.end());
   std::sort(b.begin(),b.end());
  a.erase(std::unique(a.begin(),a.end()),a.end());
  b.erase(std::unique(b.begin(),b.end()),b.end());
  std::move(b.begin(),b.end(),std::back_inserter(a));
 std::sort(a.begin(),a.end());
    return a;
}
///////////////
#include <set>
using Vi = std::vector< int >;
Vi testit( Vi a, Vi b ) {
  const std::set< int > A( a.cbegin(), a.cend() ), B( b.cbegin(), b.cend() ); Vi v;
  return merge( A.cbegin(), A.cend(), B.cbegin(), B.cend(), back_inserter( v )), v;
}
///////////
#include <range/v3/algorithm/merge.hpp>
#include <range/v3/range/conversion.hpp>
#include <range/v3/iterator.hpp>
#include <vector>
#include <set>

std::vector<int> testit(std::vector<int> mergeLeft, std::vector<int> mergeRight)
{
  std::vector<int> result;
  ranges::merge(mergeLeft  | ranges::to<std::set<int>>(),
                mergeRight | ranges::to<std::set<int>>(),
                ranges::back_inserter(result));
  return result;
}
//////////////
