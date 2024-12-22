#include <vector>
#include <algorithm>
#include <map>
#include <set>

Pegs get_hints(const std::vector<int> &a, const std::vector<int> &g) {
  Pegs p{0,0};
  std::vector<int>vp(a.size(),0);
  std::map<int,int>mp;
  std::for_each(a.begin(),a.end(),[&p,&g,&vp,&mp,i=0](auto& c)mutable{
    if(c==g[i]){
      ++p.black;
      vp[i]=1;
    }else{
      ++mp[c];
    }
    ++i;
  });
  std::for_each(vp.begin(),vp.end(),[&mp,&g,&p,i=0](auto& f)mutable{
    if(f==0){
      if(mp.count(g[i]) && mp[g[i]]>0){
          --mp[g[i]];
          ++p.white;
      }
    }
    ++i;
  });
  return p;
}
///////////////
#include <map>
#include <vector>

Pegs get_hints(const std::vector<int> &a, const std::vector<int> &b) {
  Pegs r = {0, 0};
  std::map<int, int> d;
  for (unsigned i = 0; i < a.size(); i++) a[i] == b[i] ? r.black++ : d[a[i]]++;
  for (unsigned i = 0; i < a.size(); i++) a[i] != b[i] && d[b[i]]-- > 0 && r.white++;
  return r;
}
//////////////