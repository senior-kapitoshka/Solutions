#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> sort_the_pile(std::vector<std::string> ps, const std::vector<unsigned> &ws) {
  std::for_each(ws.begin(),ws.end(),[&ps](auto i){
    std::partition(prev(ps.end(),i),ps.end(),[](auto& s){return s=="red";});
  });
  return ps;
}

/////////////////////////////////
#include <range/v3/algorithm/max_element.hpp>
using Vs_t = std::vector< std::string >;
Vs_t sort_the_pile( Vs_t pile, const std::vector< unsigned >& used ) {
  sort( pile.end() - *ranges::max_element( used ), pile.end(), std::greater() );
  return pile;
}

///////////////////////
#include <string>
#include <vector>

std::vector<std::string> sort_the_pile(std::vector<std::string> pile_of_towels, const std::vector<unsigned> &weekly_used_towels)
{
    std::sort(pile_of_towels.end() - *std::max_element(weekly_used_towels.cbegin(), weekly_used_towels.cend()), pile_of_towels.end(), std::greater<std::string>{});
    return pile_of_towels;
}