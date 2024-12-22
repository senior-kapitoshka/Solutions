#include <vector>
#include <numeric>
using namespace std;

int missingNo(vector<int> n){
  return std::accumulate(n.begin(),n.end(),0,
        [i=1](auto sum,auto curr)mutable{
            return sum+=(i++)-curr;
        });
}

//////////////
#include <functional>
#include <numeric>
#include <vector>

int missingNo(const std::vector<int>& arr) {
  return std::accumulate(arr.begin(), arr.end(), 100, std::bit_xor<>());
}