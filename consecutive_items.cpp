#include <functional>

bool consecutive(std::vector<int>arr, int a,int b){
  std::vector<int>p={a,b};
  std::vector<int>p2={b,a};
  auto it1=std::search(arr.begin(), arr.end(),
                  std::boyer_moore_horspool_searcher(
                      p.begin(), p.end()));
  auto it2=std::search(arr.begin(), arr.end(),
                  std::boyer_moore_horspool_searcher(
                      p2.begin(), p2.end()));
  return it1!=arr.end() || it2!=arr.end();
}

/////////////////////////////////////////////
#include <vector>
#include <cmath>
bool consecutive(std::vector<int> arr, int a, int b) {
	int a_pos = std::find(arr.begin(), arr.end(), a) - arr.begin();
	int b_pos = std::find(arr.begin(), arr.end(), b) - arr.begin();
	return abs(a_pos - b_pos) == 1;
}
//////////////////////////////////////////
using namespace std;

bool consecutive(std::vector<int>v, int a,int b){
  auto it = find(v.begin(), v.end(), a);
  if (*(it + 1) == b || *(it - 1) == b) return true;
  return false;
}
////////////////////////////////////////
bool consecutive(std::vector<int>arr, int a, int b)
{
  return std::abs(std::distance(arr.begin(), std::find(arr.begin(), arr.end(), a)) - std::distance(arr.begin(), std::find(arr.begin(), arr.end(), b))) == 1;
}
////////////////////////////////////////
