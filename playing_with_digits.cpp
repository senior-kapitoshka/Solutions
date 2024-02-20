#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <string>

class DigPow
{
public:
  static int digPow(int n, int p){
    std::string s=std::to_string(n);
    std::vector<int>vc;
    std::transform(s.begin(),s.end(),std::back_inserter(vc),[&p](auto& i){
      int x=std::pow((i-'0'),p);
      ++p;
      return x;
    });
    return std::accumulate(vc.begin(),vc.end(),0)%n==0?std::accumulate(vc.begin(),vc.end(),0)/n:-1;
  }
};
///////////////////
#include <cmath>
using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p){
   long long sum=0;
   for(char digit : to_string(n)){
     sum+=pow(digit-'0',p++);
   }
   return (sum/n)*n==sum ? sum/n : -1;
  }
};
////////////////