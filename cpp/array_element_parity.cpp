#include <map>
#include <algorithm>
#include <cmath>
#include <set>
int solve (std::vector<int> v){
  std::map<int,std::set<int>>mp;
  for(auto& i:v){
    mp[std::abs(i)].insert(i);
  }
  auto it=find_if(mp.begin(),mp.end(),[](auto& p){return p.second.size()!=2;});
  return *std::begin(it->second);
}

////////////////
#include<set>
#include<numeric>

int solve (std::vector<int> v){
  std::set<int> s (v.begin(), v.end() );
  return std::accumulate(s.begin(), s.end(), 0);  
}
///////////
using namespace std;
int solve (vector<int> v){
  vector<int>r;
		for (int num : v)
		{
			r.push_back(num);
			for (int n : v)
			{
				if (-num == n)
				{
					r.pop_back();
					break;
				}
			}
		}
		return r[0];	
}
////////////
#include <vector>
#include <algorithm>

int solve(std::vector<int> v)
{
    for (int element : v)
    {
        if (std::find(v.begin(), v.end(), -element) == v.end())
        {
            return element;
        }
    }
}
///////////
int solve(std::vector<int> v) 
{
  std::map<int, int> m;
  for (auto x : v) (x < 0) ? --m[abs(x)] : ++m[abs(x)];
  auto it = std::find_if(m.begin(), m.end(), [](auto x) { return x.second != 0; });
  return it->second > 0 ? it->first : -it->first;
}
//////////////
