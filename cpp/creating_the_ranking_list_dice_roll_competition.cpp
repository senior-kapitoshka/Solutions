#include <vector> 
#include <unordered_map>
#include <algorithm>


std::vector <int> ranking (std::vector<int> pt, std::vector<int> rs) {
  if(pt.empty()) return {};
  std::unordered_map<int,int>mp;
  for(auto i:rs) ++mp[i];
  std::vector<std::pair<int,int>>vp;
  vp.reserve(pt.size());
  std::transform(pt.begin(),pt.end(),std::back_inserter(vp),
                 [i=0,&mp](auto& j)mutable{
          return mp.count(j)?std::pair<int,int>{mp[j],i++}:
                   std::pair<int,int>{0,i++};         
      });
  std::sort(vp.begin(),vp.end(),[](auto lhs, auto rhs)
            {return lhs.first>rhs.first || 
              (lhs.first==rhs.first && lhs.second<rhs.second);});
  std::vector<int>res;
  res.reserve(pt.size());
  std::transform(vp.begin(),vp.end(),std::back_inserter(res),
              [](auto& p){
                return p.second;
              });
  return res;
}

////////////////////////////
#include <numeric>
#include <unordered_map>
#include <vector>

std::vector<int> ranking (std::vector<int> players_bet, std::vector<int> rolls) {
  std::unordered_map<int,int> counts = {};
  for (int n : rolls) counts[n]++;
  std::vector<int> res(players_bet);
  std::iota(std::begin(res), std::end(res), 0);
  std::stable_sort(res.begin(), res.end(), [&] (int a, int b) { return counts[players_bet[a]] > counts[players_bet[b]]; });
  return res;
}

//////////////////////////
#include <array>
#include <numeric>
#include <vector> 

std::vector<int> ranking(const std::vector<int>& player_bets, const std::vector<int>& rolls) {
  std::array<int, 6> bet_counts = {};
  for (int r : rolls)
    bet_counts[r - 1]++;
  std::vector<int> res(player_bets.size());
  std::iota(res.begin(), res.end(), 0);
  std::sort(res.begin(), res.end(), [&](int i, int j) {
    auto a = bet_counts[player_bets[i] - 1], b = bet_counts[player_bets[j] - 1];
    return a > b || a == b &&  i < j;
  });
  return res;
}

///////////////////
// Wanted to make an elegant solution with ranges..
// Actually takes... 4 secs to compile !
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
// Should not be required with C++20 support
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/algorithm/stable_sort.hpp>
#include <range/v3/iterator/insert_iterators.hpp> // Seems there is a bug for std::back_inserter() not satisfying weak incrementable concept 
#include <range/v3/to_container.hpp>
#include <range/v3/view/transform.hpp>
//#include <range/v3/view/iota.hpp> See some help required
//#include <range/v3/view/zip.hpp>

std::vector <int> ranking (std::vector<int> players_bet, std::vector<int> rolls) {

  // Accumulate once and for all the rolls for each possible dice value [1..6]  
  std::map<int,int> counts;
  for (auto d:rolls) ++counts[d];
  
  // Could be 'std::pair' as well, prefer this for readability
  struct Player {int pos,score;};
  
  // Would be much nicer with a zip and a iota: some help and fork on kumite there ??
  auto players=  players_bet 
               | ranges::views::transform([&,i=0](auto t) mutable{return Player{i++,counts[t]};})
               | ranges::to<std::vector<Player>>();
  
  ranges::stable_sort(players,std::greater<>{},&Player::score);
    
  return         players 
               | ranges::views::transform(&Player::pos) 
               | ranges::to<std::vector<int>>();
}

/////////////////////

