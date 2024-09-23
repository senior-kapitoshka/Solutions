#include <vector>

int MaxSumBetweenTwoNegatives(std::vector<int> arr) {
  int max=-1;
  int sum=0;
  bool flag=false;
  for(auto i:arr){
    if(i>=0 && !flag) continue;
    else if(i<0 && !flag){
      flag=true;
    }else if(i>=0 && flag){
      sum+=i;
    }else if(i<0 && flag){
      max=std::max(sum,max);
      sum=0;
    }
  }
  return max;
}
////////////////////////////////////
#include <range/v3/algorithm/max_element.hpp>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/sliding.hpp>
#include <vector>

int MaxSumBetweenTwoNegatives(const std::vector<int>& numbers) 
{
  using namespace ranges;
  
  const auto negativeIndexes = accumulate(numbers, std::vector<int>{}, 
                                          [i = 0] (auto& acc, const int num) mutable -> auto& {
                                            if (num < 0) { acc.push_back(i); }
                                            ++i; return acc;
                                          });

  const auto rangeBetweenNegatives = negativeIndexes | views::sliding(2);
  const auto betweenNegatives = accumulate(rangeBetweenNegatives, std::vector<int>{}, 
                                           [&numbers] (auto& acc, const auto& r) -> auto& {
                                             const auto beg = numbers.begin();
                                             acc.push_back(accumulate(beg + r[0] + 1, beg + r[1], 0));
                                             return acc;
                                           });
  
  return betweenNegatives.empty() ? -1 : *max_element(betweenNegatives);
}

