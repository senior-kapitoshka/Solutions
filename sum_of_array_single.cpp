#include <unordered_map>
#include <algorithm>
int repeats(std::vector<int>v){
  std::unordered_map<int,int>mp;
  std::for_each(v.begin(),v.end(),[&mp](auto& i){
    ++mp[i];
  }); 
  int sum=0;
  for_each(mp.begin(),mp.end(),[&sum](auto& p){
    sum+=p.second==1?p.first:0;
  });
  return sum;
}

/////////////////////////
#include<vector>
#include<algorithm>

int repeats(std::vector<int>v){
  int c = 0;
  for (int e : v)
    c += e * (std::count (v.begin(), v.end(), e) == 1);   
  return c;      
}
//////////////////////
#include <set>
#include <numeric>
int repeats(std::vector<int>v){
  std::set<int> unique(v.begin(), v.end());
  return  2 * std::accumulate(unique.begin(), unique.end() , 0) 
            - std::accumulate(v.begin(), v.end() , 0);
}
////////////////////
#include <numeric>

int repeats(std::vector<int> v) 
{
  std::map<int, int> m;
  for (auto x : v) ++m[x];
  return std::accumulate(m.begin(), m.end(), 0, [](int s, auto x) { return x.second == 1 ? s + x.first : s; });
}