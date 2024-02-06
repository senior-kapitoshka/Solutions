#include <algorithm>

std::vector<double> averages(std::vector<int> n)
{
    if(n.empty() || n.size()==1) return {};
    std::vector<double> result;
    std::transform(next(n.begin()),n.end(),n.begin(),
                   std::back_inserter(result),[](double prev, double next)->double
                   {
                     return (prev+next)/2;
                   });
  
    return result;
}
/////////////////////////////////
#include <numeric>

std::vector<double> averages(const std::vector<int>& numbers) {
    if(numbers.size() < 2) return {};
  
    std::vector<double> result;
    
    std::adjacent_difference(
        numbers.cbegin(), numbers.cend(),
        std::back_inserter(result),
        [](double a, double b) { return (a + b) / 2; }
    );
  
    result.erase(result.begin());
  
    return result;
}
/////////////////////////////
