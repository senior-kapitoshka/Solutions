#include <vector>
#include <string>
#include <type_traits>
#include <exception>
using namespace std;

template<class T>
vector<T> add_arrays(const vector<T>& arr1, const vector<T>& arr2) {
  std::vector<T>res;
  if(arr1.size()!=arr2.size()) throw std::logic_error("error");
  res.reserve(arr1.size());
  std::for_each(arr1.begin(),arr1.end(),[i=0,&arr2,&res](auto& j)
                mutable{
                  res.emplace_back(j+arr2[i++]);
                });
  return res;
}
////////////////////
#include <exception>
#include <functional>
#include <vector>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/transform.hpp>

using namespace std;
using namespace ranges;

template<class T>
vector<T> add_arrays(const vector<T>& xs, const vector<T>& ys) {
  if (xs.size() != ys.size())
    throw logic_error("lengths are not equal");
  return views::transform(xs, ys, plus<>()) | to<vector>();
}
///////////////
template< typename T >
std::vector<T> add_arrays( const std::vector<T>& a, const std::vector<T>& b ) {
  std::vector<T> v( a.size() );
  for ( size_t i{}; i < a.size(); ++i ) v.at( i ) = a.at( i ) + b.at( i );
  return v;
}
////////////////
#include <vector>

template<class T>
std::vector<T> add_arrays(const std::vector<T>& v1, const std::vector<T>& v2)
{
	if (v1.size() != v2.size()) throw std::exception();
	std::vector<T> res;
	std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(res), std::plus<T>());
	return res;
}