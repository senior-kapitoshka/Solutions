#include <vector>

void wave_sort(std::vector<int> &v) {
  if(v.empty()) return;
  bool flag=true;
  for(size_t i=0;i<v.size()-1;++i){
    if(v[i]>=v[i+1] && !flag){
      std::swap(v[i],v[i+1]);
      flag=true;
    }else if(v[i]<=v[i+1] && flag){
      std::swap(v[i],v[i+1]);
      flag=false;
    }else{
      if(flag){
        flag=false;
      }else if(!flag){
        flag=true;
      }
    }
  }
}
////////////////
#include <vector>
#include <algorithm>

void wave_sort(std::vector<int> &v) 
{
  std::sort(v.begin(), v.end(), [](int& x, int& y){ return x > y; });
  for (int i = 1; i+1 < v.size(); i+=2) {
    std::swap(v[i], v[i+1]);
  }
}
/////////////////
