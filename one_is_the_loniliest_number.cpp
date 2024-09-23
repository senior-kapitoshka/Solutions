#include <numeric>
#include <string>
#include <limits>
#include <algorithm>

bool loneliest(unsigned long n) {
  int min=std::numeric_limits<int>::max();
  int min1=std::numeric_limits<int>::max();
  std::string s=std::to_string(n);
  std::for_each(s.begin(),s.end(),[i=0,&s,&min1,&min](auto& c)
                mutable{
    int sum=0;              
    if(c=='1'){
      sum+=i>0?s[i-1]-'0':0;
      sum+=i<(int)s.size()-1?s[i+1]-'0':0;
      min1=std::min(sum,min1);
    }else if(c!='1'){
      int ld=std::min(i,c-'0');
      int rd=std::min((int)s.size()-(i+1),c-'0');
      for(int j=i-1;j>=i-ld;--j){
        sum+=s[j]-'0';
      }
      for(int j=i+1;j<=i+rd;++j){
        sum+=s[j]-'0';
      }
      min=std::min(sum,min);
    }             
    ++i;
  });
  return min>=min1;
}

/////////////////////////////
bool loneliest( unsigned long number ) {
  const std::string s{ std::string( 9, '0' ) + std::to_string( number ) + std::string( 9, '0' )};
  for ( size_t i{ 9 }, lim{ s.size() - 9 }, lon_min{ 162 }; i < lim; ++i ) {
    size_t num( s[ i ] - '0' ), lon{ -num };
    for ( size_t j{ i - num }; j <= i + num; ++j ) lon += s[ j ] - '0';
    if ( lon < lon_min ) lon_min = lon, number = 0;
    if ( num == 1 && lon <= lon_min ) number = 1;
  }
  return static_cast< bool >( number );
}

/////////////////
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

bool loneliest(unsigned long number)
{
  string s = to_string(number);
  vector<int> min_loneliness(10, s.size()*9);
  for (int i = 0 ; i < (int) s.size() ; i++)
  {
    int d = s[i]-'0';
    int start = max(0,i-d), end = min(i+d+1, (int)s.size());
    min_loneliness[d] = min(min_loneliness[d], accumulate(s.begin()+start,s.begin()+end,-(end-start)*'0'-d));
  }
  
  return min_loneliness[1] == *min_element(min_loneliness.begin(), min_loneliness.end());
}

/////////////////////
