# define M_PI           3.14159265358979323846
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>

using vec_rect_circle = std::vector<std::pair<double, double>>;

vec_rect_circle sort_by_area(vec_rect_circle v) {
  std::sort(v.begin(),v.end(),[](const auto& lhs,const auto& rhs){
    return (lhs.second==0 && rhs.second==0)?M_PI*std::pow(lhs.first,2)<M_PI*std::pow(rhs.first,2):
    (lhs.second==0 && rhs.second!=0)?M_PI*std::pow(lhs.first,2)<rhs.first*rhs.second:
    (lhs.second!=0 && rhs.second==0)?lhs.first*lhs.second<M_PI*std::pow(rhs.first,2):
    lhs.first*lhs.second<rhs.first*rhs.second;
  });
  return v;
}
////////////////////////
#include <utility>
#include <vector>
#include <cmath>

using vec_rect_circle = std::vector<std::pair<double, double>>;

vec_rect_circle sort_by_area(vec_rect_circle v) {
  auto area = [] (auto x) {
    static const double pi = acos(-1);
    return ((x.second == 0) ? (pi * x.first * x.first) : (x.first * x.second));
  };
  std::sort(v.begin(), v.end(), [&] (const auto x, const auto y) {
    return area(x) < area(y);
  });
  return v;
}
///////////////
#include <utility>
#include <vector>
#include <algorithm>

#include <math.h>

using vec_rect_circle = std::vector<std::pair<double, double>>;

double area(std::pair<double, double> o)
{
  return o.second == 0 ? o.first * o.first * M_PI : o.first * o.second;
}

vec_rect_circle sort_by_area(vec_rect_circle v) {
  
  sort(v.begin(), v.end(), [&](auto x, auto y) {
    return area(x) < area(y);
  });

  return v;
}
