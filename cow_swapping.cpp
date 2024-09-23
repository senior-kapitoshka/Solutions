#include <vector>
#include <numeric>

using namespace std;

int min_cow_swaps(const vector<int>& ck) {
  std::vector<int>vs;
  std::vector<bool>vb(ck.size(),false);
  for(int i=0;i<(int)ck.size();++i){  
    if(i!=ck[i] && !vb[i] && !vb[ck[i]]){
      int ch=2;
      vb[i]=true;
      vb[ck[i]]=true;
      int x=ck[i];
      while(true){
        if(!vb[ck[x]]){
          vb[ck[x]]=true;
          ++ch;
          x=ck[x];
        }else break;
      }
      vs.push_back(ch);
    }
  }
  return std::accumulate(vs.begin(),vs.end(),0,[](int sum,auto c){
    return sum+=c-1;
  });
}
//////////////////
#include <vector>
using namespace std;

int min_cow_swaps(const vector<int>& cow_rank) {
  vector<int> cows(cow_rank);
  int n = cow_rank.size();
  int swaps = 0;
  for (int i = 0; i < n; i++) {
    while (cows[i] != i) {
      swaps++;
      swap(cows[i], cows[cows[i]]);
    }
  }
  return swaps;
}
////////////////
#include <vector>
using namespace std;

int min_cow_swaps(vector<int>& c) {
  int s = 0, i = c.size();
  while (i--) while (c[i]!=i && ++s) swap(c[i], c[c[i]]);
  return s;
}

/////////////////
#include <vector>
using namespace std;

int min_cow_swaps(const vector<int>& cow_rank) {
  int n = cow_rank.size(), swaps = 0;
  vector<int> ranks;
  for (int i: cow_rank) {
    ranks.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    while (i != ranks[i]) {
      int tmp = ranks[ranks[i]];
      ranks[ranks[i]] = ranks[i];
      ranks[i] = tmp;
      swaps++;
    }
  }
  return swaps;
}

//////////////
