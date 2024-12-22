#include <cmath>
bool is_even(double n)
{
    return std::ceil(n)==n?(int)(n)%2==0:false;
}

//////////////////
#include <cmath>

bool is_even(double n)
{
    return fmod(n, 2) == 0;
}
///////////////
#include <cmath>
bool is_even(double n)
{
    if(ceil(n) != floor(n)) return false;
    return ((int)n)%2 == 0;
}

/////////////////