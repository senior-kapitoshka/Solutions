#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    return input.empty()?std::vector<int>{}:std::vector<int>{(int)std::count_if(input.begin(),input.end(),[]
                                           (auto& c){return c>0;}),std::accumulate(input.begin(),input.end(),0,[]
                                                             (int& s,auto& c){return s+=c<0?c:0;})};
}
////////////////////////
#include <vector>
#include <numeric>
#include <vector>
#include <algorithm>
std::vector<int> countPositivesSumNegatives(std::vector<int> input){
    if(input.empty()) return {};
    std::vector<int>::iterator it = std::partition(input.begin(), std::end(input), [&](int i) {return i>0; });
    return {(int)std::distance(input.begin(), it),std::accumulate(it, input.end(),0) };
}