#include <set>

bool bingo(unsigned long x,int h){
  std::string s1=std::to_string(x*h);
  std::string s2=std::to_string(x*(h+1));
  return std::multiset<char>(s1.begin(),s1.end())==
    std::multiset<char>(s2.begin(),s2.end());
}

unsigned long findLowestInt(unsigned int k) {
  unsigned long ans=0;
  for(long i=1;i<std::numeric_limits<long>::max();++i){
    if(bingo(i,k)){
      ans=i;
      break;
    }
  }
  return ans;
}


////////////////////
#include <climits>
unsigned long findLowestInt( unsigned k ) {
  for ( unsigned long n{ 1 }; n < ULONG_MAX; ++n ) {
    auto nk1{ n * k }, nk2{ n * ( k + 1 )};
    int m[ 10 ]{};
    do ++m[ nk1 % 10 ]; while ( nk1 /= 10 );
    do --m[ nk2 % 10 ]; while ( nk2 /= 10 );
    for ( int i{}; i < 10 && !m[ i ]; ++i )
      if ( i == 9 ) return n;
  }
  return {};
}

////////////////////
#include <range/v3/algorithm/permutation.hpp>

unsigned long findLowestInt(unsigned int k1) 
{
  const unsigned int k2 = k1 + 1;
  
  unsigned long n = 2;
  for ( ; !ranges::is_permutation(std::to_string(k1 * n), std::to_string(k2 * n)); ++n) {}
  return n;
}

//////////////////
