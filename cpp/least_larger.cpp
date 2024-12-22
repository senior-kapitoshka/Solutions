#include <vector>
#include <set>
#include <cstddef>

int least_larger(const std::vector<int>& a, std::size_t i)
{
    int x=a[i];
  std::set<int> vc(a.begin(),a.end());
  return std::next(vc.lower_bound(x))==vc.end()?-1:std::distance(a.begin(),std::find(a.begin(),a.end(),*std::next(vc.lower_bound(x))));
}

//////////////////
#include <vector>
#include <cstddef>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/algorithm/min.hpp>
using namespace ranges::views;

std::ptrdiff_t least_larger(const std::vector<int>& a, std::size_t i)
{
    auto view = zip(a, indices) | filter([&](auto kv) { return kv.first > a[i]; });
    return ranges::empty(view) ? -1 : ranges::min(view).second;
}
///////////
#include <vector>
#include <cstddef>
#include <optional> // Incluyo potional para utilizar value_or()

std::ptrdiff_t least_larger(const std::vector<int>& arr, std::size_t index) {
    int target = arr[index];
    std::optional<std::ptrdiff_t> result; // Uso el std::optional para controlar si no encuentra un indice que posea un elemento mayor    
    for (std::size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > target && (!result.has_value() || arr[i] < arr[result.value()])) {
            result = i;
        }
    }
    
    // Devuelve -1 si no encuentra el index
    return result.value_or(-1);
}

////////
#include <vector>
#include <cstddef>

std::ptrdiff_t least_larger(const std::vector<int>& a, std::size_t index)
{
    ssize_t min_idx = -1;
    for(size_t i=0; i<a.size(); ++i)
        if(a[i]>a[index] && (min_idx==-1||a[min_idx]>a[i]))
            min_idx = i;
    return min_idx;
}
