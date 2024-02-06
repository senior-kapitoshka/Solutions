#include <vector>
#include <numeric>

std::vector<int> beggars(const std::vector<int>& val, unsigned int n){
  if(n==0) return {};
  if(n==1) return {std::accumulate(val.begin(),val.end(),0)};
  if(n>=val.size()){
    std::vector<int>v{val.begin(),val.end()};
    v.resize(n);
    return v;
  }
  std::vector<int>v{val.begin(),val.end()};
  std::vector<int>res;
  int j=0;
  while(j<(int)v.size()){
    int t=0;
    for(int i=j;i<(int)v.size();i+=n){
      t+=v[i];
    }
    res.push_back(t);
    ++j;
  }
  res.resize(n);
  return res;
}
//////////////////////////////
auto beggars(const std::vector<int>& values, unsigned int n) {
    std::vector<int> result(n);
    if (n)
        for (std::vector<int>::size_type i = 0, values_size = values.size(); i < values_size; ++i)
            result[i % n] += values[i];
    return result;
}
////////////////////
#include <numeric>
using namespace std;
vector<int> beggars(const vector<int>& v, unsigned int n){
  vector<int> res (n,0);
   for (int i = 0; i < n; ++i)
     for (int j = i; j < v.size(); j += n)       
       res[i] += v[j];
  return res;
}  
////////////////////////