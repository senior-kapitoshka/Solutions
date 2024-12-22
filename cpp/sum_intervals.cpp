#include <iostream>

using namespace std;
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
  if(intervals.empty()) return 0;
  if(intervals.size()==1) return intervals[0].second-intervals[0].first;
  sort(intervals.begin(),intervals.end(),[&]
       (std::pair<int,int>a,std::pair<int,int>b)
       {return a.first<b.first;});
 //   sort(intervals.begin(),intervals.end());
  std::stack<std::pair<int,int>>st;
  st.push(intervals[0]);
  for(size_t i=1;i<intervals.size();++i){
    /*if(st.top().second >= intervals[i].first && st.top().second < intervals[i].second){
      std::pair<int,int>tmp={st.top().first,intervals[i].second};
      st.pop();
      st.push(tmp);*/
    if(st.top().second>=intervals[i].first){
      st.top().second=std::max(st.top().second,intervals[i].second);
    }else st.push(intervals[i]);
  }
  int ans=0;
  while(!st.empty()){
    ans+=st.top().second-st.top().first;
    st.pop();
  }
  return ans;
}

int main()
{
    cout<<sum_intervals({ { -65, -28 }, { 425, 450 }, { 181, 360 },
  { -460, -415 },
  { 398, 474 },
  { -75, 211 },
  { -425, 234 },
  { 34, 495 },
  { 91, 461 }});

    return 0;
}
