#include <vector>
#include <map>

std::vector<int> solve(std::vector<int> vec){    
    std::map<int,int> mp;
    for(auto&& i:vec) ++mp[i];
  std::vector<int>ans;
  for(auto&& i:vec){
    if(mp[i]>1){
      --mp[i];
    }else{
      ans.push_back(i);
    }
  }
  return ans;
}

//////////////////////////////////
#include <vector>
#include <unordered_set>

std::vector<int> solve(std::vector<int> vec){    
    std::unordered_set<int> s(vec.rbegin(), vec.rend());
    vec.assign(s.begin(),s.end());
    return vec;
}
//////////////////////////////


#include <vector>
using namespace std;


vector<int> solve(vector<int>vec) {

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] == vec[j])
            {
                vec.erase(vec.begin() + i);
                i--;
            }
        }
    }


    return vec;
}
//////////////////////////////////////////////
#include <unordered_set>
std::vector<int> solve( std::vector< int > v ) {
  const std::unordered_set s( v.crbegin(), v.crend() );
  return { s.cbegin(), s.cend() };
}
///////////////////////////////////////
// In-place algorithm. Complexity: n (n - 1) / 2 + 2 n.
std::vector<int> solve(std::vector<int> v) {
    std::reverse(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
        v.erase(std::remove(it + 1, v.end(), *it), v.end());
    std::reverse(v.begin(), v.end());
    return v;
}

