#include <string>
long long shiftLeft(std::string s, std::string t){
  if(s==t) return 0;
  long long i=(long long)s.size()-1;
  long long j=(long long)t.size()-1;
  while(s[i]==t[j] || i!=0 || j!=0){
    if(s[i]==t[j]){
      --i;
      --j;
    }else break;
  }
  return i+j+2;
}

//////////////////
#include <algorithm>
#include <string>

long long shiftLeft(const std::string& s, const std::string& t) {
  auto mm = std::mismatch(s.crbegin(), s.crend(), t.crbegin());
  return (s.crend() - mm.first) + (t.crend() - mm.second);
}

//////////////
long long shiftLeft( std::string s, std::string t ) {
  const auto [ is, it ]{ mismatch( s.crbegin(), s.crend(), t.crbegin() ) };
  return distance( is, s.crend() ) + distance( it, t.crend() );
}

//////////////
#include <string>
long long shiftLeft(std::string s, std::string t)
{
	long long c{};
	while (s != t && ++c) s.size() > t.size() ? s.erase(0, 1) : t.erase(0, 1);
	return c;
}

////////////
