#include <string>
#include <algorithm>
#include <vector>

int countValleys(const std::string& s){
  if(s.empty() || all_of(s.begin(),s.end(),[](auto& c){return c=='F';})) return 0;
  int degree=0;
  std::vector<int>vc;
  vc.push_back(0);
  std::transform(s.begin(),s.end(),std::back_inserter(vc),[degree](auto& c)mutable{
    if(c=='U') ++degree;
    else if(c=='D') --degree;
    return degree<0?1:0;
  });
  vc.erase(std::unique(vc.begin(),vc.end()),vc.end());
  int cnt=0;
  for(size_t i=1;i<vc.size()-1;++i){
    if(vc[i]==1 && vc[i-1]==0 && vc[i+1]==0) ++cnt;
  }
  return cnt;
}

/////////////////////////////////
#include <string>

int countValleys(const std::string& s){
  auto level = 0, result = 0;
  for (auto const e : s) {
    if (e == 'D') --level;
    else if (e == 'U' && ++level == 0)
        ++result;
  }
  return result;
}

//////////////////////////////
int countValleys( const std::string& s ) {
  int level{}, vcount{};
  for ( const char c : s )
    if ( c == 'U' && !++level ) ++vcount;
    else if ( c == 'D' ) --level;
  return vcount;
}
////////////////////
#include <string>

int countValleys(std::string s)
{
	int x{}, r{};
	for (auto c : s)
	{
		c == 'U' ? ++x : c == 'D' ? --x : x;
		if (c == 'U' && !x) ++r;
	}
	return r;
}
/////////////////
