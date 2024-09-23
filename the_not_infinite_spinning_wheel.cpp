#include <string>
#include <algorithm>
#include <numeric>

int spinning_wheel(std::string w) {
  if(std::all_of(w.begin(),w.end(),[](auto i){
    return i=='N';
  })) return 0;
  return std::accumulate(w.begin(),w.end(),0,[i=0,&w](int sum,auto c)mutable{
    if(c=='W'){
      ++sum;
      ++i;
      return sum;
    }else{
      int l=0,r=0;
      int j=i;
      while(true){
        if(j==(int)w.size()-1){
          j=0;
          ++r;
        }else{
          ++r;
          ++j;
        }
        if(w[j]=='W')break;
      }
      j=i;
      while(true){
        if(j==0){
          j=w.size()-1;
          ++l;
        }else{
          ++l;
          --j;
        }
        if(w[j]=='W')break;
      }
      ++i;
      return sum+=std::min(r,l)%2==0?1:0;
    }
  })*100/w.size();
}

/////////////////////
#include <string>
#include <algorithm>
#include <array>

int spinning_wheel(std::string wheel) {
  // You need: the number of "W", as well as the number of "N" with an even distance from a "W"
  int wn=std::count(wheel.begin(),wheel.end(),'W');
  if (wn==0) return 0;
  if (wn==(int)wheel.size()) return 100;
  
  // A little trick there: expand the base string so that you can safely iterate down or up till 'W'; from the middle
  // provided that... the string as at most one 'W' (was checked before)
  auto nwins=[&,trick=wheel+wheel+wheel](int i) {
    i+=wheel.size();
    int j=1;
    while(trick[i+j]!='W' && trick[i-j]!='W') ++j;
    return j%2==0;
  };
  for (size_t i=0; i!=wheel.size(); ++i) {
    if (wheel[i]=='W') continue;
    wn+=nwins(i);
  }
  return wn*100/wheel.size();
      
}

////////////////
#include <string>
#include <vector>
#include <algorithm>

int spinning_wheel(std::string wheel) 
{
  auto l = wheel.find('W');
  if (l == std::string::npos) return 0;
  auto r = wheel.size() - 1 - wheel.rfind('W');
  std::vector<int> dist(wheel.size());
  std::transform(std::begin(wheel), std::end(wheel), std::begin(dist),
    [&r] (auto c)  { return c == 'W' ? (r = 0) : ++r; });
  std::transform(std::rbegin(wheel), std::rend(wheel), std::rbegin(dist), std::rbegin(dist),
    [&l] (auto c, auto s)  { return c == 'W' ? (l = 0) : ++l < s ? l : s; });
  auto win = std::count_if(std::cbegin(dist), std::cend(dist),
    [] (auto k) { return ~k & 1; });
  return 100 * win / wheel.size();
}

///////////////////
#include <algorithm>
#include <string>

using namespace std;

int spinning_wheel(const string& wheel) {
  int n = 0;
  int l = wheel.size();
  while (l > 0 && wheel[l-1] == 'N') {
    --l;
    ++n;
  }
  int w = 0;
  for (int i = 0; i < l; ++i) {
    if (wheel[i] == 'W') {
      w += 1 + (n % 2 ? n / 2 : n / 4 * 2);
      n = 0;
    }
    else {
      ++n;
    }
  }
  return 100 * w / wheel.size();
}

///////////////////////
#include <algorithm>
#include <string>

int spinning_wheel(const std::string &s) {
  auto r = 0;
  for (auto &x : s) r += (x == 'W');
  if (!r) return 0;
  for (auto i = 0; i < (int)s.size(); i++)
    if (s[i] == 'N')
      for (auto j = 1; ; j++)
        if (s[(i+j)%s.size()] == 'W' || s[s.size()*(j>i)+i-j] == 'W') {
          r += 1 - j % 2;
          break;
        }
  return r * 100 / s.size();
}
///////////////////
