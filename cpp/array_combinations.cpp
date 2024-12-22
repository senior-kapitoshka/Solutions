#include <vector>
#include <numeric>
#include <unordered_set>

int solve(const std::vector<std::vector<int>> &d)
{
    return std::accumulate(d.begin(),d.end(),1,[](int& prd,auto& v){
      std::unordered_set<int>tmp(v.begin(),v.end());
      return prd*=tmp.size();
    }); 
}

//////////////////////////
//transform_reduce
//////
#include <functional>
#include <numeric>
#include <unordered_set>
#include <vector>

int solve(const std::vector<std::vector<int>>& data) {
  return std::transform_reduce(data.cbegin(), data.cend(), 1, std::multiplies(), [](const auto& xs) {
    return std::unordered_set<int>(xs.cbegin(), xs.cend()).size();
  });
}

//////////////////
#include <vector>
#include <unordered_map>

int binomial(int n, int k) {
    if (k > n) return 0;
    if (k == n || k == 0) return 1;
    int diff, result;
    diff = n - k;
    result = 1;
    if (diff > k) {
        for (int i = n; i > diff; --i ) 
            result *= i;
        for (int i = k; i > 1; --i )
            result /= i;
    } else {
        for (int i = n; i > k; --i ) 
            result *= i;
        for (int i = diff; i > 1; --i )
            result /= i;
    }
    return result;
}

int solve(const std::vector<std::vector<int>> &data) {
    int count, result;
    result = 1;
    for (size_t i = 0; i < data.size(); ++i) {
      std::unordered_map<int, int> input;
      count = 0;
      for (size_t j = 0; j < data[i].size(); ++j) {
        input[data[i][j]]++;
        if (input[data[i][j]] == 1) count++; 
      }
      result *= binomial(count, 1);
    }
    return result;
}

//////////////////////
