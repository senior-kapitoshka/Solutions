#include <vector>
#include <algorithm>

int maximizePoints(const std::vector<int>& t1, const std::vector<int>& t2) {
  std::vector<int>x(t1.begin(),t1.end());
  std::vector<int>y(t2.begin(),t2.end());
  std::cout<<"\n--\n";
  std::sort(x.begin(),x.end());
  std::sort(y.begin(),y.end());
  int cnt=0;
  for(size_t i=0,j=0;i<x.size();){
    if(x[i]>y[j]){
      ++cnt;
      ++i;
      ++j;
    }else{
      ++i;
    }
  }
  return cnt;;
}

/////////////////
#include <algorithm>
#include <numeric>
#include <vector>

int maximizePoints(std::vector<int> team1, std::vector<int> team2) {
  std::sort(team1.begin(), team1.end());
  std::sort(team2.begin(), team2.end());
  return std::accumulate(team1.cbegin(), team1.cend(), 0, [&team2](int a, int p1) {
    return a + (p1 > team2[a]);
  });
}

//////////////////
#include <iostream>
#include <vector>

using namespace std;

int maximizePoints(const vector<int>& team1, const vector<int>& team2) {
  vector<int> local_team2 = team2;
  int wins = 0;
  for (auto & iter1 : team1) {
    int j = 0, best_match = -1, min_delta = 101;
    for (auto & iter2 : local_team2) {
      int power_delta = iter1 - iter2;
      if ( power_delta > 0 && power_delta < min_delta) {
        best_match = j;
        min_delta = power_delta;
      }
      j++;
    }
    // Remove best option, smallest power differential.
    if (min_delta > 0 && best_match >= 0) {
      local_team2.erase(local_team2.begin() + best_match);
      wins += 1;
    }
  }
  return wins;
}

//////////////////////
