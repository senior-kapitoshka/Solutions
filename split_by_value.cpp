#include <algorithm>

std::vector<int> split_by_value(int k, std::vector<int> e)
{
  std::stable_partition(e.begin(),e.end(),[k](auto& c){
    return c<k;
  });
    return e;
}

////////////////
std::vector<int> split_by_value(int k, std::vector<int> elements) {
  std::vector<int> result;
  for (auto elem:elements) {
    if (elem < k) {
      result.push_back(elem);
    }
  }
  for (auto elem:elements) {
    if (elem >= k) {
      result.push_back(elem);
    }
  }
  return result;
}

/////////////
