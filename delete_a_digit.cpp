#include <string>
int deleteDigit(int n)
{
  int res=0;
  std::string s=std::to_string(n);
  size_t sz=s.size();
  for(size_t i=0;i<sz;++i){
    std::string t;
    for(size_t j=0;j<sz;++j){
      if(i!=j)t+=s[j];
    }
    res=std::max(res,std::stoi(t));
  }
  return res;
}

/////////////////////
int deleteDigit(int n)
{
  int s=n/10;
  int k=10;
  while(n%k !=n){
    int r=n/(k*10)*k+n%k;
    if(r>s){
      s=r;
    }
    k=k*10;
  }
  return s;
  
}
//////////////////
using namespace std;

int deleteDigit(int n)
{
  int mx = -1;
  string sb = to_string(n);
  for (int i = 0; i < sb.length(); i++)
    mx = max(mx, stoi(sb.substr(0,i)+ sb.substr(i+1)));
  return mx;
}
///////////////
