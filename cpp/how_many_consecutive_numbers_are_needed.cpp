#include <vector>
#include <numeric>
#include <algorithm>

int consecutive(const std::vector<int>& arr) {
    auto [from,to]=std::minmax_element(arr.begin(),arr.end());
    int res=0;
    for(int i=*(from)+1;i<*(to);++i){
      if(std::find(arr.begin(),arr.end(),i)==arr.end()) ++res;
    }
    return res;
}

///////////////
#include <vector>
using namespace std;
int consecutive(const vector<int>& arr) {
    if (arr.empty())
      return 0;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    return temp.back() - temp.front() + 1 - temp.size();
}

///////////
int consecutive(const std::vector<int>& v)
{
	if (v.empty()) return 0;
	auto [minv, maxv] = std::minmax_element(v.cbegin(), v.cend());
	return *maxv - *minv + 1 - (int)v.size();
}

////////////
