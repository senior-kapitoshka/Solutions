using namespace std;
#include <unordered_map>
#include <utility>
#include <iostream>
#include <algorithm>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ (h2<<1);  
    }
};

vector<string> escape(const vector<vector<int>> &cp)
{
  std::unordered_map<std::pair<int,int>,std::pair<int,int>,pair_hash>mp;
  std::pair<int,int>pt;
  std::pair<int,int>ex;
  for(size_t i=0;i<cp.size();++i){
    for(size_t j=0;j<cp[i].size();++j){
      if(cp[i][j]==2) pt=std::make_pair(i,j);
      else if(cp[i][j]==1) mp[{i,j}]={i+1,j};
      if(i==cp.size()-1 && j==cp[i].size()-1){
        ex={i,j};
        mp[ex]=ex;
      }
    }
  }
  std::vector<std::pair<char,int>>vp;
  while(pt!=ex){
    auto it=find_if(mp.begin(),mp.end(),[&pt](auto& p){return pt.first==p.first.first;});
    if((*it).first==pt){
      if(vp.back().first!='D'){
        vp.push_back({'D',1});
      }else if(vp.back().first=='D'){
        ++vp.back().second;
      }
      pt=(*it).second;
    }
    else if((*it).first.second>pt.second){
      int t=(*it).first.second-pt.second;
      vp.push_back({'R',t});
      pt=(*it).first;
    }
    else if((*it).first.second<pt.second){
      int t=pt.second-(*it).first.second;
      vp.push_back({'L',t});
      pt=(*it).first;
    }
  }
  std::vector<std::string>res;
  std::transform(vp.begin(),vp.end(),std::back_inserter(res),[](auto& p){
    return p.first+std::to_string(p.second);
  });
  
    return res; // Code here
}