#include <vector>
#include<algorithm>

std::vector<int> remove_values(std::vector<int> in, std::vector<int> val) {
 std::vector<int>ans;
  for(auto i:in){
     if(count(val.begin(),val.end(),i)==0){
       ans.push_back(i);
     }
 }
  
  return ans;
}

//////////////////////////////////////////

#include <vector>

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values) {
  for(int i: values) integers.erase(std::remove(integers.begin(), integers.end(), i), integers.end());
  return integers;
}
////////////////////////////////////////////


#include <vector>
#include <unordered_set>

using namespace std;

vector<int> remove_values(vector<int> a, vector<int> b) {
  unordered_set<int> s(b.begin(), b.end());
  vector<int> r;
  for (int x : a) if (!s.count(x)) r.push_back(x);
  return r;
}

/////////////////////////////////////////

#include <vector>
#include <algorithm>
using namespace std;
vector<int> remove_values(vector<int> integers, vector<int> values) {
  integers.erase(remove_if(integers.begin(), integers.end(), 
    [&](int i){
      return (find(values.begin(), values.end(), i) != values.end());
    }
  ), integers.end());
  return integers;
}