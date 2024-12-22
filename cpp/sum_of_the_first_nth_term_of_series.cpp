
#include <sstream>
#include <iomanip>
std::string seriesSum(int n)
{
  if(n==1) std::to_string(n);
  double res=0.00;
  std::stringstream ss;
  if(n==0){
    
    return "0.00";
  }
  int j=4;
  res+=1.00;
    for(int i=1;i<n;++i){
      res+=(double)(1.00/(double)j);
      j+=3;
    }
  ss<<std::setprecision(3)<<res;
  return ss.str().size()==3?ss.str()+'0':ss.str().size()==1?ss.str()+".00":ss.str();
}

////////////////
#include <iomanip>

using namespace std;

string seriesSum(int n)
{
    double ret = 0.0;
    double base = 1.0;
    while (n--) {
      ret += 1 / base;
      base += 3;
    }
    stringstream retss;
    retss << setprecision(2) << fixed << ret;
    return retss.str();
}
//////////////
std::string seriesSum(int n)
{
    float sum = 0;
    char str[3];
    for(auto i = 0; i < n; i++) sum += 1./(3*i+1);
    sprintf(str, "%.2f", sum);
    return str;
}
//////////////
