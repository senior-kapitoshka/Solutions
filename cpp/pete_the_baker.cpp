#include <unordered_map>
#include <algorithm>
#include <limits>

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& rec, const Ingredients& av) {
  int mn=std::numeric_limits<int>::max();
  for(auto& p:rec){
    if(!av.count(p.first)){
      return 0;
    }else{
      mn=std::min(mn,av.at(p.first)/p.second);
    } 
  }
  return mn;
}
////////////////
#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available) {
  return std::transform_reduce(recipe.begin(), recipe.end(), std::numeric_limits<int>::max(),
    [](int a, int b){ return std::min(a, b); },
    [&](auto&& r) {
      auto ia = available.find(r.first);
      return ia == available.end() ? 0 : ia->second / r.second;
    });
}