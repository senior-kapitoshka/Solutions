#include <vector>
#include <algorithm>
#include <queue>


int addAll (const std::vector<int>& n) {
  std::priority_queue<int,std::vector<int>,std::greater<int>>pq(n.begin(),n.end());
  int ans=0;
  while(pq.size()>1){
    int f=pq.top();
    pq.pop();
    int s=pq.top();
    pq.pop();
    ans+=f+s;
    pq.push(f+s);
  }
  
  return ans;
}