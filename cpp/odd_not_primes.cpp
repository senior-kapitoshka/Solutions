#include <cmath>

unsigned int oddNotPrime(unsigned int n){
  int cnt=1;
  for(unsigned int i=1;i<=n;i+=2){
    for(unsigned int j=3;j<=std::sqrt(i);++j){
      if(i%j==0) {
        ++cnt;
        break;
      }
    }
  }
  return cnt;
}

////////////
bool prime( const unsigned n ) {
  if ( n < 2 ) return false;
  for ( unsigned f{ 3 }; f * f <= n; f += 2 )
    if ( !( n % f ) ) return false;
  return true;
}
unsigned oddNotPrime( unsigned n ) {
  unsigned c{ 1 };
  for ( unsigned i{ 3 }; i <= n; i += 2 )
    if ( !prime( i ) ) ++c;
  return c;
}