#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include <set>


void tr(std::vector<int>& a,std::unordered_map<int,int>& amp, std::set<int>&ks){
  for_each(a.begin(),a.end(),[&ks,&amp](auto& i){++amp[i];
                                                ks.insert(i);});
}

int common(std::vector<int> a, std::vector<int> b, std::vector<int> c) {

  std::unordered_map<int,int>amp,bmp,cmp;
  std::set<int>ks;
  tr(a,amp,ks);
  tr(b,bmp,ks);
  tr(c,cmp,ks);
  std::vector<int> vc;
  for_each(ks.begin(),ks.end(),[&amp,&bmp,&cmp,&vc](auto& k){
    if(amp.count(k) && bmp.count(k) && cmp.count(k)){
      std::vector<int> t={amp[k],bmp[k],cmp[k]};
      vc.push_back(k*(*min_element(t.begin(),t.end())));
    }
    
  });
  return std::accumulate(vc.begin(),vc.end(),0);
}
/////////////////////////////////
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
int common(std::vector<int> a, std::vector<int> b, std::vector<int> c) {
    std::vector<int> vec,other;
  
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    std::sort(c.begin(),c.end());
    std::set_intersection(a.begin(),a.end(),b.begin(),b.end()
                          ,std::back_inserter(vec));
    std::set_intersection(vec.begin(),vec.end(),c.begin(),c.end()
                          ,std::back_inserter(other));
   return std::accumulate(other.begin(),other.end(),0);
  
}
//////////////////////////////////
