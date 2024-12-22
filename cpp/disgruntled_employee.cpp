#include <vector>
#include <algorithm>
std::vector<int> off(int n) {
  std::vector<int>vc(n,1);
  for(int i=1;i<=n;++i){
    for(int j=i-1;j<n;j+=i){
      vc[j]=vc[j]==0?1:0;
    }
  }
  std::vector<int>res;
  std::for_each(vc.begin(),vc.end(),[&res,i=1](auto& j)mutable{
    if(j==0) res.push_back(i);
    ++i;
  });
  return res;
}

///////////////
#include <vector>
#include <cmath>
using namespace std;
vector<int> off(int n) {
  vector<int> answer;
  for (int i=1;i<=sqrt(n);i++)
    answer.push_back(i*i);
  return answer;
}

/////////////
#include <vector>

// The only switches that will stay off are those with an odd number of divisors, that is, perfect squares
std::vector<int> off(int n)
{
  std::vector<int> res;
  for (int i = 1 ; i*i <= n ; i++)
    res.push_back(i*i);
  return res;
}