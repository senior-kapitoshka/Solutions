#include <vector>
#include <string>
#include <algorithm>
#include <fmt/format.h>

using namespace std::literals;

std::string warn_the_sheep(const std::vector<std::string>& q)
{
    return q.back()=="wolf"s?"Pls go away and stop eating my sheep"s:
  fmt::format("Oi! Sheep number {}! You are about to be eaten by a wolf!"s,
              std::distance(q.rbegin(),std::find(q.rbegin(),q.rend(),"wolf"s)));
}