#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> pyramid(std::size_t n) {
  std::vector<std::vector<int>>res;
  res.reserve(n);
  for(size_t i=1;i<=n;++i){
    res.emplace_back(std::vector<int>(i,1));
  }
  return res;
}
///////////////
#include <vector>
#include <cstdlib>

auto pyramid(std::size_t n) {
  std::vector<std::vector<int>> output(n);
  std::generate(output.begin(), output.end(), [n=0]() mutable {return std::vector(++n, 1);});
  return output;
}
///////////////
