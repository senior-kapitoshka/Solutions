#include <algorithm>
std::vector<int> solve(std::vector<int>v) {
    std::sort(v.begin(),v.end());
  int i=0,j=v.size()-1;
  std::vector<int>res;
  res.reserve(v.size());
  while(i<=j){
    res.push_back(v[j]);
    res.push_back(v[i]);
    ++i;--j;
  }
  res.erase(std::unique(res.begin(),res.end()),res.end());
  return res;
}
/////////////////////
#include <algorithm>

using std::max_element;
using std::min_element;
using std::swap;
std::vector<int> solve(std::vector<int> v) {
    for (auto it {v.begin()}; it != v.end();++it){
      swap (*it,*max_element(it,v.end()));
      if (++it != v.end()) swap (*it,*min_element(it,v.end()));
    }
  return v;
}
///////////////////
std::vector<int> solve(std::vector<int>v) {
    std::sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
        if(i%2==0)
            std::reverse(&v[i],&v[v.size()]);
        else
            std::sort(&v[i],&v[v.size()]);
    return v;
}
///////////////////
