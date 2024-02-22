#include <array>
#include <map>
#include <vector>

using namespace std;

void tr(int n, std::vector<int>&vc){
  vc.push_back(n%10);
  int t=n/10;
  if(t==0) return;
  tr(t,vc);
}

array<int, 10> paint_letterboxes(int start, int end)
{
    array<int, 10> ans;
    map<int,int> mp;
    std::vector<int> vc;
    for(int i=start;i<=end;++i){
      tr(i,vc);
    }
    for(auto i: vc){
      ++mp[i];
    }
    for(int i=0;i<10;++i){
      ans[i]=mp[i];
    }
  
  return ans;
}

/////////////////////////////////
#include <array>

using namespace std;

array<int, 10> paint_letterboxes(int start, int end)
{
    array<int, 10> frequencies = { 0 };
    for (int i = start; i <= end; i++)
        for (int n = i; n > 0; n /= 10)
            frequencies[n % 10]++;
    return frequencies;
}
/////////////////////////////
#include <array>

using namespace std;

array<int, 10> paint_letterboxes(int start, int end)
{
    string str;
    array <int, 10> arr;
    
    for(auto i = start; i <= end; i++) str+= to_string(i);
    for(auto i = 0; i < 10; i++)  arr[i] = count(str.begin(), str.end(), i + '0');
    
    return arr;
}
///////////////////////////
#include <array>

std::array<int, 10> paint_letterboxes(int start, int end)
{
	std::array<int, 10> m{};
	for (int i = start; i <= end; ++i)
	{
		std::string s = std::to_string(i);
		std::for_each(s.begin(), s.end(), [&](char c) { ++m[c - '0']; });
	}
	return m;
}