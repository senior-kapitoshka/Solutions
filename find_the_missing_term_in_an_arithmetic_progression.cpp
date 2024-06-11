#include <algorithm>
#include <numeric>
#include <cassert>
#include <limits>
static long findMissing(std::vector<long> l){
  std::sort(l.begin(),l.end());
  long m=std::numeric_limits<long>::max();
  std::for_each(l.begin(),prev(l.end()),[&l,&m,j=1](auto& i)mutable{
    m=std::min(m,l[j++]-i);
  });
  std::vector<long> nv(l.size()+1);
  std::vector<long> res;
  std::generate(nv.begin(),nv.end(),[&m,n=l.front()]()mutable{return n+=m;});
  std::set_difference(nv.begin(),nv.end(),l.begin(),l.end(),std::inserter(res,res.begin()));
  return res.front();
}
/////////////
#include <numeric>

static long findMissing(std::vector<long> list)
{
  long long expectedSum = (list.front() + list.back()) * (list.size() + 1);
  long long actualSum = std::accumulate(list.begin(), list.end(), 0ll);
  
  return (expectedSum - 2 * actualSum) / 2;
} 
/////////////
static long findMissing(std::vector<long> v)
{
	std::vector<long> res;
	std::adjacent_difference(v.begin(), v.end(), std::back_inserter(res));
	return v.front() + std::distance(res.begin(), std::max_element(res.begin() + 1, res.end(), [](long a, long b) { return std::abs(a) < std::abs(b); })) * *std::min_element(res.begin() + 1, res.end(), [](long a, long b) { return std::abs(a) < std::abs(b); });
}
///////////
using namespace std;

static long findMissing(std::vector<long> list) {
  const auto n1 = list.at(1) - list.at(0);
  const auto n2 = list.at(list.size() - 1) - list.at(list.size() - 2);
  const auto step = abs(n1) < abs(n2) ? n1 : n2;

  vector<long> tmp(list.size() + 1);
  generate(tmp.begin(), tmp.end(),
           [n = (list[0] - step), step]() mutable { return n += step; });

  return  accumulate(tmp.begin(), tmp.end(), 0l) - accumulate(list.begin(), list.end(), 0l);
}
/////////////
