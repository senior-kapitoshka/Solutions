#include <numeric>
#include <algorithm>
class CountDig
{
public:
    static int nbDig(int n, int d){
      std::vector<int>vc(n+1);
      std::iota(vc.begin(),vc.end(),0);
      std::transform(vc.begin(),vc.end(),vc.begin(),[](auto& i){return i*i;});
      int cnt=0;
      std::for_each(vc.begin(),vc.end(),[d,&cnt](auto& i){
        std::string s=std::to_string(i);
        cnt+=std::count_if(s.begin(),s.end(),[d](auto& c){
          return c-'0'==d;
        });
      });
      return cnt;
    }
};
/////////////
class CountDig
{
public:
    static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d) { 
  int count = 0;
  for (int k = 0; k <= n; ++k) {
    int m = k*k;
    do {
      if ((m % 10) == d) count += 1;
      m /= 10;
    } while(m);
  }
  return count;
}
//////////
namespace CountDig
{
  int nbDig(int n, int d)
  {
    std::string digits;
    for (int k = 0; k <= n; ++k)
      digits += std::to_string(k * k);
  
    return std::count(digits.begin(), digits.end(), std::to_string(d)[0]);
  }
}
////////////////
