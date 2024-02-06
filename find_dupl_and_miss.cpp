#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

std::pair<int, std::vector<int>> findDupsMiss(const std::vector<int>& arr) {
  std::vector<int>vc(arr.begin(),arr.end());
  //std::priority_queue<int, std::vector<int>, std::greater<int> >pq(arr.begin(),arr.end());
  int k=0;
  std::vector<int>st;
  std::vector<int>db;
  std::sort(vc.begin(),vc.end());
  st.push_back(vc[0]);
  for(size_t i=1;i<vc.size();++i){
    if(vc[i]!=st.back() && (vc[i]-st.back())>1)
      {
          k=vc[i-1]+1;
          st.push_back(k);
          st.push_back(vc[i]);
          
        }
     else if(vc[i]!=st.back() && (vc[i]-st.back())==1){
          st.push_back(vc[i]);
        }
    else if(vc[i]==st.back()){
      db.push_back(vc[i]);
    }
  }
  return {k,db};
    }

    ////////////////////////////////////////////////////////////////////////

    #include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
std::pair<int, std::vector<int>> findDupsMiss(const std::vector<int>& a) {
  vector<int> arr{a.begin(),a.end()};
  sort(arr.begin(),arr.end());
  unordered_map<int,int> find;
  size_t i,j;
  for(i=0;i<arr.size();i++)
  {
     find[arr[i]]++;
  }
  pair<int,vector<int>> last;
  for(i=1;i<=find.size();i++)
  {
     if(find[i]==0)
     {
        last.first=i;
     }
     if(find[i]>1)
     {
       last.second.push_back(i);
     }
  }
  return last;
}

///////////////////////////////////////////////////////////

#include <utility>
#include <vector>
#include <algorithm>

std::pair<int, std::vector<int>> findDupsMiss(std::vector<int>& arr) {
  if (arr.size() == 0) return {};
  
  std::sort(arr.begin(), arr.end());
  
  int a = arr.front();
  
  int missing = a;
  int last = a - 1;
  std::vector<int> d;
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    if (last == *it) d.push_back(*it);
    if (missing == *it) missing++;
    last = *it;
  }
  
  return {missing, d};
}

////////////////////////////////////////////////////////////////


#include <utility>
#include <vector>
#include <map>

std::pair<int, std::vector<int>> findDupsMiss(const std::vector<int>& arr) 
{
  std::map<int, int> numberOccuranceFrequencies;
  for (const int number : arr) { ++numberOccuranceFrequencies[number]; }
  
  int current = numberOccuranceFrequencies.begin()->first; bool found = false;
  std::pair<int, std::vector<int>> result = { 0, {} };
  for (const auto& [number, amount]  : numberOccuranceFrequencies)
  {
    if (amount > 1) { result.second.push_back(number); }
    if (!found && current != number) { result.first = current; found = true; }
    ++current;
  }
  return result;
}