bool is_pal(const std::string& s){
  std::string t(s.rbegin(),s.rend());
  return s==t;
}

bool solve(std::string s){
    if(is_pal(s) && s.size()%2!=0) return true;
  if(is_pal(s) && s.size()%2==0) return false;
  int i=0;
  int j=(int)s.size()-1;
  bool flag=true;
  while(i<j){
     if(s[i]!=s[j] && flag){
      flag=false;
    }else if(s[i]!=s[j] && !flag){
      return false;
    } 
    ++i;
    --j;
  }
  return true;
}

///////////////////////
bool solve(std::string s)
{
	auto c = std::count_if(s.begin(), s.begin() + s.size() / 2, [=, i = s.size()](char x) mutable { return x != s[--i]; });
	return c == 1 || !c && s.size() % 2;
}

///////////
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>

bool solve(const std::string& s) {
  auto d = std::transform_reduce(
    s.begin(), s.begin() + (s.end() - s.begin()) / 2, s.rbegin(),
    std::string::size_type(0), std::plus(), std::not_equal_to());
  return d == 1 || d == 0 && s.size() % 2 == 1;
}

//////////////////
bool solve( std::string s ) {
  int c{};
  for ( size_t i{}, m{ s.size()/2 }; i < m; ++i )
    if (( c += s[ i ] != s[ s.size()-1 - i ] ) > 1 )
      return false;
  return c || s.size() & 1;
}

////////////////
bool solve(std::string s)
{
	int count = 0, n = s.length();

	for (int i = 0; i < n; ++i)
		if (s[i] == s[n - i - 1])
			++count;

	return count == n && (n & 1) || count == n - 2;
}
///////////////
