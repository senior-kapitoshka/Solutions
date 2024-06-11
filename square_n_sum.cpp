#include <vector>
#include <numeric>

int square_sum(const std::vector<int>& n)
{
    return std::accumulate(n.begin(),n.end(),0,[](auto sum,auto curr)
                           {
                             return sum+=curr*curr;
                           });
}

////////////////
#include <vector>
#include <numeric>

int square_sum(const std::vector<int>& v) {
  int x = std::inner_product(v.begin(), v.end(), v.begin(), 0 );
  return x;
}

///////////////
#include <vector>
#include <numeric>
#include <functional>

int square_sum(const std::vector<int>& numbers)
{
    return std::transform_reduce(numbers.cbegin(), numbers.cend(), numbers.cbegin(), 0);
}

////////////////
