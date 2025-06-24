#include <vector>
#include <algorithm>

std::vector<int> seqList(int f, int c, std::size_t l)
{
  auto res=std::vector<int>{f};
  res.resize(l);
  std::generate(res.begin()+1,res.end(),[&f,&c](){
    return f+=c;    
  });
    return res;
}

///////////
#include <vector>
#include <numeric>

std::vector<int> seqList(int first, int c, std::size_t l)
{
    std::vector<int> arr(l, c);
    std::exclusive_scan(arr.cbegin(), arr.cend(), arr.begin(), first);
    return arr;
}

/////////
#include <vector>

std::vector<int> seqList(int first, int c, std::size_t l)
{
	std::vector<int> v(l);
	std::generate(v.begin(), v.end(), [=, i = 0]() mutable { return first + i++ * c; });
	return v;
}