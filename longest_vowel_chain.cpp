#include <regex>
#include <algorithm>

using namespace std;

int solve(string s){
	std::regex r("[aeiou]+");
  auto rb= std::sregex_iterator(s.begin(),s.end(),r);
  auto er =std::sregex_iterator();
  int res=0;
  for(auto it=rb;it!=er;++it){
    res = std::max(res,(int)((*it).str()).size());
  }
  return res;
}

////////////////////////////////
#include <regex>
#include <numeric>

using namespace std;

int solve(const string& s){
    static const regex v{ R"([aeiou]+)" };
    return accumulate(
        sregex_token_iterator{ s.cbegin(), s.cend(), v },
        sregex_token_iterator{},
        0,
        [](const int acc, const std::string& match) { 
          return max<int>(acc, match.size()); 
        }
    );
}
//////////////////////////
int solve( std::string s ) {
  int l{}, t{};
  const std::string v{ "aeiou" };
  for ( const char c : s )
    if ( v.find( c ) != v.npos ) ++t;
    else l = std::max( l, t ), t = 0;
  return std::max( l, t );
}
///////////////////
