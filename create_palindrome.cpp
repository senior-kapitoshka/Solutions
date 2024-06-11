#include <cmath>

bool solve(std::string s) {
  std::string t(s.rbegin(),s.rend());
  if(s==t) return true;
    int i=0;
  int j=s.size()-1;
  while(i<j){
    if(s[i]==s[j]){
      ++i;
      --j;
    }else if(s[i]!=s[j] && std::abs(s[i]-s[j])==2){
      ++i;
      --j;
    }else return false;
  }
  return true;
}

///////////////
