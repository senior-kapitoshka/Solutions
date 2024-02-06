#include <vector>
#include <numeric>
#include <cmath>

int sum_even_numbers(const std::vector<double> &seq) {
  return std::transform_reduce(seq.cbegin(),seq.cend(),0,std::plus{},[](auto &d)
                               { return (std::fmod(d, 2) == 0 ? d : 0.0);});
}

///////////////////////////////////////////////
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

int sum_even_numbers(const std::vector<double> &seq) {
  int res=0;
  std::for_each(seq.begin(),seq.end(),[&res](auto& d)
           { double c=d;
             if(std::fmod(c, 2) == 0) res+=c;});
  return res;
}
//////////////////////////////
#include <vector>
#include <numeric>
#include <cmath>

int sum_even_numbers(const std::vector<double> &seq) {
  return std::accumulate(seq.begin(), seq.end(), 0.0, [](double sum, double value)
    {
        return sum + (std::fmod(value, 2) == 0 ? value : 0.0);
    });
}