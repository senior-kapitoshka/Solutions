#include <string>

std::string switcheroo(const std::string &s) {
  std::string ans;
  for(auto&& i:s){
    if(i=='a'){
      ans+='b';
    }else if(i=='b'){
      ans+='a';
    }else{
      ans+=i;
    }
  }
  return ans;
}
////////////////////////////

#include <string>
#include <algorithm>

std::string switcheroo(const std::string &s) {
  std::string r = s;
  transform(r.begin(),r.end(),r.begin(),[](char c) {return c == 'a' ? 'b' : c == 'b' ? 'a' : c;});
  return r;
}
//////////////////////////////////////////////

std::string switcheroo(std::string s) 
{
  for (char & e : s)
    e = e == 'a' ? 'b' : e != 'c' ? 'a' : e;
  return s;
}