#include <vector>
#include <cmath>

int tram(int stops, const std::vector<int>& a, const std::vector<int>& b) {
  int ans=0;
  int h=0;
  for(int i=1;i<=stops;++i){
    h+=b[i-1];
    ans=std::max(ans,h);
    h-=a[i];
    
  }
  return ans;
}

////////////////////////////////
#include <vector>

int tram(int stops, const std::vector<int>& a, const std::vector<int>& b) {
  int maxi = 0;
  int passengers = 0;
  for(int i = 0; i < stops; i++){
    passengers += b[i] - a[i];
    if(maxi < passengers)
      maxi = passengers;
  }
  return maxi;
}
/////////////////////////////

int tram( int stops, const std::vector< int >& a, const std::vector< int >& b ) {
  int r{};
  for ( int i{}, c{}; i < stops; ++i )
    r = std::max( r, c += b[ i ] - a[ i ] );
  return r;
}
////////////////////////////
#include <vector>
#include <numeric>

int tram(int stops, const std::vector<int>& a, const std::vector<int>& b) {
  // "GoodLuck";
  return std::inner_product(a.cbegin(), std::min(a.cbegin() + stops, a.cend()), b.cbegin(),
    std::vector<int>{ 0, 0 }, 
    [](const auto& acc, const int& delta) {return std::vector<int>{std::max(acc[0], acc[1] + delta), acc[1] + delta }; },
    [](const int& a, const int& b) { return b - a; })[0];
}

////////////////////////////

#include <vector>

int tram(int stops, const std::vector<int>& a, const std::vector<int>& b)
{
	int s{}, ms{};
	for (int i = 0; i < stops; ++i)
	{
		s += b[i] - a[i];
		ms = std::max(s, ms);
	}
	return ms;
}