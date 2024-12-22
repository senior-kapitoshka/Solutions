#include <string>
#include <string_view>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std::literals;


std::string grid(int n) {
  if(n<=0)return "";
  if(n==1) return "a";
  std::vector<std::string>vs(n,"");
  std::string_view a="abcdefghijklmnopqrstuvwxyz"sv;
  std::for_each(vs.begin(),vs.end(),[i=0,a,&n](auto& s)mutable{
    std::string t;
    for(size_t j=i;j<(size_t)n;++j){
      t+=a[j%a.size()];
      t+=" ";
    }
    t.pop_back();
    std::swap(s,t);
    ++i;
    ++n;
  });
   std::string res=std::accumulate(next(vs.begin()),vs.end(),vs.front(),[](auto& lhs, auto& rhs){
    return std::move(lhs)+"\n"+std::move(rhs);
  });
  return res;
}


////////////////
#include <string>

std::string grid(int n) {
  std::string s = "abcdefghijklmnopqrstuvwxyz";
  std::string ans;
  if(n < 0)
    return "";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans += s[(i + j) % 26];
      ans += j == n - 1 ? "" : " ";
    }
    ans += i == n - 1 ? "" : "\n";
  }
  return ans;
}
////////////////////////////
std::string grid( int n ) {
  if ( n < 1 ) return {};
  std::string s;
  for ( int i{}; i < n; ++i, s.back() = '\n' )
    for ( int j{}; j < n; ++j, s += ' ' )
      s += 97 + ( i + j ) % 26;
  return s.pop_back(), s;
}
////////////////////