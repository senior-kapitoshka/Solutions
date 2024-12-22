#include <vector>
#include <algorithm>

int microWorld(std::vector<int> b , int k){
  int cnt=0;
  std::sort(b.begin(),b.end());
  for(auto& i:b){
    if(std::find_if(b.begin(),b.end(),[i,k](auto& j){
      return j>i && j<=i+k;
    })==b.end()) ++cnt;
  }
  return cnt;
}
/////////////////////
#include <vector>
#include <algorithm>

int microWorld(const std::vector<int>& bacteria, int k) {
  return std::count_if(bacteria.begin(), bacteria.end(), [&](int x) {
    return std::all_of(bacteria.begin(), bacteria.end(), [&](int y) {
      return y <= x || x + k < y;
    });
  });
}
////////////////
int microWorld(std::vector<int> l, int k) {
  std::sort(l.begin(), l.end());
  int c=1, s=1;
  for(int i=1; i<l.size(); i++, s++) {
    if(l[i]-l[i-1]>k) c+=s;
    if(l[i]>l[i-1]) s=0;
  }
  return c+s-1;
}
/////////////////
