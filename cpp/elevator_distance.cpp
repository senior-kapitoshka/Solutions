#include <vector>
#include <numeric>
#include <cmath>

int elevator_distance(std::vector<int> a) {
  return std::accumulate(a.begin(),prev(a.end()),0,[&a,i=1](int& sum,int& curr)mutable{
    return sum+=std::abs(curr-a[i++]);
  });
}
/////////////////////
#include <vector>
#include <numeric>

int elevator_distance(std::vector<int> v)
{
  std::adjacent_difference(v.begin(), v.end(), v.begin(), [](int x, int y) {return std::abs(x - y); });
  return std::accumulate(v.begin() + 1, v.end(), 0);
}
//////////////////
