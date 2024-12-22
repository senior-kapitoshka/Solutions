#include<vector>
#include <deque>
#include <algorithm>

long long queue(const std::vector<int>& qs, int pos){
  std::deque<std::pair<int,bool>>dq;
  std::transform(qs.begin(),qs.end(),std::back_inserter(dq),[pos,i=0](auto& c)mutable{
    return pos==i++?std::pair<int,bool>{c,true}:std::pair<int,bool>{c,false};
  });
  long long cnt=0;
  while(true){
    if(dq.front()==std::pair<int,bool>{1,true}) break;
    else{
      if(dq.front().first!=1){
        dq.push_back(std::pair<int,bool>{dq.front().first-1,dq.front().second});
        dq.pop_front();
      }else{
        dq.pop_front();
      }
      ++cnt;
    }
  }
  return cnt+1;
}

////////////////////////
#include<vector>

long long queue(const std::vector<int>& queuers, int pos){
  //your code here
  long long countQueueTime = 0;
  for (int i = 0; i < queuers.size(); i++) {
    if (i <= pos)
      // The rule here is each people standing in front of your buddy will get at least
      // the number of tickets your buddy want to get before your buddy can get all the tickets
      countQueueTime += (queuers[i] <= queuers[pos]) ? queuers[i] : queuers[pos];
    else
      // The rule here is each people standing behind your buddy will get at least
      // the number of tickets your buddy want minus 1 before your buddy get all the tickets
      countQueueTime += (queuers[i] < queuers[pos]) ? queuers[i] : (queuers[pos] - 1);
  }
  return countQueueTime;
}

///////////////////
#include<vector>

long long queue(const std::vector<int>& queuers, int pos){
  std::vector<int> q=queuers;
  long long c = 0;
  while(q[pos])
    for (auto &i:q)
    {
      if (i)
      {
        c++; 
        i--;
      }
      if (!q[pos])
        return c;
    }
}