#include <algorithm>
#include <numeric>
using namespace std;

vector<int> squareUp(int n)
{
    std::vector<std::vector<int>>vc(n,std::vector<int>(n,0));
    int i=n-1;
    std::for_each(vc.begin(),vc.end(),[&i](auto& v){
      std::iota(v.rbegin(),v.rend()-i,1);
      --i;
    });
    std::vector<int>res;
    res.reserve(n*n);
    for(auto i:vc)
      for(auto j:i)
        res.push_back(std::move(j));
    return res;
}
///////////////////////
#include <vector>

std::vector<int> squareUp(int n)
{
  std::vector<int> result(n * n);
  
  for (auto i = 1; i <= n; ++i) {
    for (auto j = i; j <= n; ++j) {
      result[j * n - i] = i;
    }
  }
  
  return result;
}
//////////////////////
#include <numeric>

using namespace std;

std::vector<int> squareUp(int n)
{
  std::vector<int> result;
  for (int i = n - 1; i >= 0; --i) {
    std::vector<int> part(n);
    std::iota(part.rbegin(), part.rend() - i, 1);
    std::move(part.begin(), part.end(), std::back_inserter(result));
  }
  return result;
}