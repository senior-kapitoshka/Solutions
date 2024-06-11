#include <string>
#include <sstream>

std::string pattern(int n){
  std::stringstream ss;
  for(int i=n;i>0;--i){
    for(int j=n;j>=i;--j){
      ss<<j;
    }
    if(i!=1)ss<<"\n";
  }
  return ss.str();
}
////////////
