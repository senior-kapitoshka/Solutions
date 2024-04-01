#include <algorithm>


int solve(std::vector <int> v) {
    int res = 0;
    std::sort(v.begin(),v.end());
    for(auto& i:v){
        if( i > res + 1) break;
        res += i;
    }
return res + 1;
}

#if 0

int solve(std::vector <int> v) {
  std::sort(v.begin(),v.end());
  std::vector<int> res;
  res.push_back(0);
  for(auto& it:v){
    size_t sz=res.size();
    for(size_t j=0;j<sz;++j){
      int t=res[j];
      t+=it;
      res.emplace_back(t);
    }
  }
  std::sort(res.begin(),res.end());
  res.erase(std::unique(res.begin(),res.end()),res.end());
  for(int i=0;i<(int)res.size();++i){
    if(i!=res[i]){
      return i;
    }
  }
  return res.back()+1;
}

#endif

////////////////////
int solve(std::vector <int> v) {
	sort(v.begin(),v.end());
  int t = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    if (i + 1 != v[i] && v[i] > t + 1) return t + 1;
    t += v[i];
  }
  return t + 1;
}
////////////////////
#include <vector>
#include <unordered_set>

int solve(std::vector <int> arr) {
  if(arr.size() == 0) {
    return 0;
  }

  std::unordered_set<int> set;
  set.insert(arr[0]);

  for(int i=1; i < arr.size(); i++) {
    std::vector<int> toAdd(set.size());
    for(int v : set) {
      toAdd.push_back(v + arr[i]);
    }
    set.insert(toAdd.begin(), toAdd.end());
    set.insert(arr[i]);
  }

  int res = 1;
  while(set.find(res) != set.end()) {
    res++;
  }