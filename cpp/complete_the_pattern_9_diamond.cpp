#include <sstream>
#include <array>

std::string make_pal(int n,int m){
  std::stringstream ss;
  std::array<int,10> ar={1,2,3,4,5,6,7,8,9,0};
  ss<<std::string(m-n,' ');
  for(int i=0;i<n-1;++i){
    if(i<10)ss<<ar[i];
    else ss<<ar[i%10];
  }
  for(int i=n-1;i>=0;--i){
    if(i<10)ss<<ar[i];
    else ss<<ar[i%10];
  }
  ss<<std::string(m-n,' ');
  return ss.str();
}

std::string pattern(int n)
{
  std::stringstream ss;
  for(int i=1;i<n;++i){
      ss<<make_pal(i,n)<<"\n";
  }
  for(int i=n;i>=1;--i){
      if(i!=1)ss<<make_pal(i,n)<<"\n";
    else ss<<make_pal(i,n);
  }
  return ss.str();
}

//////////////////////////////
#include <sstream>
std::string pattern(int n)
{
    if(n<1) return "";
    int a;
    std::stringstream s;
    for(int j=-n+1; j<n; ++j){
        for(int i=-n+1; i<n; ++i){
            a = n-abs(i)-abs(j);
            if(a<1) s << " ";
            else s << a%10;
        }
		s << "\n";
    }
	return s.str().substr(0, s.str().size()-1);
}

////////////////////
