#include <vector>
#include <numeric>
#include <exception>
#include <cmath>

class NewAverage
{
public:
   static long long newAvg(std::vector<double> &arr, double n){
     long long res= std::ceil(n*(arr.size()+1)-std::accumulate(arr.begin(),arr.end(),0.0));
     return res<=0?
       throw std::invalid_argument(""):
        res;
   }
};


//////////////////