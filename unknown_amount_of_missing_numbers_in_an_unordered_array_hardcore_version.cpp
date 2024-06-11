#include <vector>
#include <set>
#include <algorithm>
#include <execution>

std::vector<unsigned int> missNumsFinder(const std::vector<unsigned int>& arr) {
  auto mx=*std::max_element(arr.begin(),arr.end());
  std::vector<bool>vc(mx+1,0);
  for(auto i:arr){
    vc[i]=1;
  }
  std::vector<unsigned int>res;
  res.reserve(mx);
  for(unsigned int i=1; i <= mx; ++i)
  {
    if(vc[i] == 0)
    {
      res.push_back(i);
    }
  }
  return res;
}



#if 0

constexpr unsigned int T=10000;

std::vector<unsigned int> missNumsFinder(const std::vector<unsigned int>& arr) {
  std::vector<unsigned int>st(arr.begin(),arr.end());
  if(st.size()>=T)std::sort(std::execution::par,st.begin(),st.end());
  else std::sort(st.begin(),st.end());
  std::vector<unsigned int>res;
  auto x=st.begin();
  for(auto it=next(st.begin());it!=st.end();++it){
    if((*it)-(*x)!=1){
      unsigned int y=(*it)-(*x);
      unsigned int z=(*x);
      while(y>1){
        ++z;
        res.push_back(z);
        --y;
      }
    }
    ++x;
  }
  return res.empty()?std::vector<unsigned int>{(*st.begin())-1}:res;
}

#endif