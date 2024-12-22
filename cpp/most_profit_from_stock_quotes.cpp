#include <vector>
#include <map>
#include <set>
#include <functional>
#include <limits>

int most_profit(const std::vector<int>& q)
{
    std::map<int,std::vector<std::pair<int,size_t>>,std::greater<int>>mp;
  std::set<size_t>st;
  std::for_each(q.begin(),q.end(),[i=0,&q,&mp](auto& it)mutable{
    if(i==0)mp[it].push_back({std::numeric_limits<int>::max(),0});
    std::for_each(q.begin(),q.begin()+i,[j=0,it,&mp](auto& jt)mutable{
      mp[it].push_back({jt,j++});
    });
    ++i;
  });
  int sum=0;
  int id=0;
  int sum_id=0;
  for(auto& pp:mp){
    for(auto& p:pp.second){
      if(pp.first<=p.first) continue;
      else{
        if(!st.count(p.second)){
          ++id;
          sum+=p.first;
          st.insert(p.second);
        }
      }
      id=pp.first*id;
      sum_id+=id;
      id=0;
    }
  }

  return sum_id-sum;
}
///////////////////////
#include <vector>

int most_profit(const std::vector<int>& quotes)
{
    auto profit = 0;
    for (auto it = quotes.begin(); it < quotes.end(); ++it)
    {
        profit += *std::max_element(it, quotes.end()) - *it;
    }
    return profit;
}

//////////////////
#include <vector>
#include <algorithm>

int most_profit(const std::vector<int>& quotes) {
  int profit{0};
  auto rolling_max_pos{std::max_element(quotes.begin(), quotes.end())};
  
  for (auto it{quotes.begin()}; it != quotes.end(); it++) {
    if (it > rolling_max_pos) {
      rolling_max_pos = std::max_element(it, quotes.end());
    }
    
    profit += std::max(*rolling_max_pos - *it, 0);
  }
  
  return profit;
}

//////////////////
#include <vector>
#include <algorithm>
#include <numeric>

int most_profit(const std::vector<int>& quotes)
{
  int profit = 0;
  std::vector<int>::const_iterator maxIt, maxItOld = quotes.cbegin();
  while(maxIt < quotes.cend())
  {
    maxIt = std::max_element(maxItOld, quotes.cend());
    int expense = std::accumulate(maxItOld, maxIt, 0); // суммируем траты на акции за период между максимумами
    profit += static_cast<int>(maxIt - maxItOld) * (*maxIt) - expense; // (кол. акций) * (на цену в пер. продаж) - траты
    maxItOld = maxIt + 1;
  }
  return profit;
}/////////////////
