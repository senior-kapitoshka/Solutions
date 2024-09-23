#include <limits>
#include <cmath>
bool is_square(int n)
{
  //std::cout<<n<<"\n";
  if(n<0) return false;
  for(int i=0;i<std::numeric_limits<int>::max()/100;++i){
    if(std::pow(i,2)==n){
      return true;
    }
  }
  return false;
}


///////////////////
#include<cmath>

bool is_square(int n) {
  if (n < 0) return false;
  int square = sqrt(n);
  return square * square == n;
}

//////////////
#include <cmath>

bool is_square(int n)
{
  return fmod(sqrt(n), 1) == 0;
}

///////////
bool is_square(int n)
{
  for (int i = 0; i <= n/2 + 1; i++){
  if ( i * i == n)
  return true;
  }
  return false;
}

///////////////
