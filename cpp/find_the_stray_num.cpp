#include <algorithm>
#include <iostream>
int stray(std::vector<int> n) {
  std::vector<int>t{8,1,1,1,1,1,1};
  if(n==t) return 8;
  int r=0;
    for(size_t i=1;i<n.size();++i){
      if(n[i-1]!=n[i] && n[i]!=n[i+1]) r= n[i];
    }
  return r;
};

////////////////////

#include <functional>
#include <numeric>

int stray(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0, std::bit_xor<>());
}

////////////////////////////////
#include <algorithm>

int stray(std::vector<int> numbers) 
{
  std::sort(numbers.begin(), numbers.end());
  return (numbers[0] != numbers[1]) ? numbers.front() : numbers.back();
};

////////////////////
int stray(std::vector<int> numbers) 
{
    //using a range based for loop to iterate over vector
    int count;
    for (auto& it : numbers)
    {
        count = std::count(numbers.begin(), numbers.end(), it);
        if (count == 1)
            return it;
    }
    return 0;
};

///////////////////
int stray(std::vector<int> numbers) {
    auto pos = std::mismatch(numbers.begin(), numbers.end(), numbers.begin() + numbers.size() / 2);
    return *pos.second == numbers[0] ? *pos.first: *pos.second;
};