#include <vector>
#include <algorithm>
std::vector<int> countBy(int x,int n){
  std::vector<int>res(n);
  std::generate(res.begin(),res.end(),[&x,i=0]()
                mutable{
    i+=x;
    return i;
  });
  return res;
}
/////////////////
#include <vector>
#include <numeric>
std::vector<int> countBy(int x, int n){
  std::vector<int> output(n, x);
  std::partial_sum(output.begin(), output.end(), output.begin());
  return output;
}
//////////////////
#include <vector>
#include <numeric>
using namespace std;
std::vector<int> countBy(int x,int n){
  vector vec(n,x);
  inclusive_scan(vec.cbegin(),vec.cend(),vec.begin(),plus{});
  return vec;
}
///////////
