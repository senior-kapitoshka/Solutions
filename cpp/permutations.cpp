#include <string>
#include <vector>
#include <algorithm>

void rev(std::string& s, int m){
  int i=0;
  int j=m;
  while(i<j){
    std::swap(s[i],s[j]);
    ++i;
    --j;
  }
}

void antylex(std::string& s,std::vector<std::string>& vs,int m, int n ){
  if(m==0){
    std::string t;
    for(int i=0;i<n;++i){
      t+=s[i];
    }
    vs.push_back(t);
  }else{
    for(int i=0;i<=m;++i){
      antylex(s,vs,m-1, n);
      if(i<m){
        std::swap(s[i],s[m]);
        rev(s,m-1);
      }
    }
  }
}

std::vector<std::string> permutations(std::string s) {
  if(s.empty()) return {""};
  int n=(int)s.size();
  std::vector<std::string> res;
  antylex(s,res,n-1, n);
  std::sort(res.begin(),res.end());
  res.erase(std::unique(res.begin(),res.end()),res.end());
  return res;
}

///////////////////////////
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> permutations(std::string s)
{
    std::sort(s.begin(), s.end());
    std::vector<std::string> result;
    do
    {
        result.push_back(s);
    }
    while (std::next_permutation(s.begin(), s.end()));
    return result;
}