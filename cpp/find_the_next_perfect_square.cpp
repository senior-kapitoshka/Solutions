#include <cmath>
long int findNextSquare(long int sq) {
  long int s=std::sqrt(sq);
  if(s*s!=sq) return -1;
  return std::pow(std::sqrt(sq)+1,2);
}

///////////////////
#include <cmath>    
long int findNextSquare(long int sq) {
  if(sqrt(sq) != (int)sqrt(sq)){return -1;}
  return  pow(sqrt(sq) + 1,2);
}

//////////////////
#include <cmath>

long int findNextSquare(long int sq) {
  auto sqrt = std::sqrt(sq);

  return std::modf(sqrt, &sqrt) == 0 ? std::pow(sqrt + 1, 2) : -1;
}

//////////////
#include <cmath>

long int findNextSquare(long int sq)
{
    return (sqrt(sq) == floor(sqrt(sq))) ? (pow(sqrt(sq) + 1, 2)) : -1;
}

/////////////
