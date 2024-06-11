#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <cmath>

std::vector<uint64_t> powers_of_two(int n) {
  std::vector<uint64_t>vc(n+1);
  std::generate(vc.begin(),vc.end(),[i=0]()
                mutable{
                  return std::pow(2,i++);
                });
  return vc;
}

/////////////////
#include <vector>
#include <cstdint>

struct generator
{
    uint64_t _num;
    generator(uint64_t n) : _num(n) {};
    uint64_t operator() () { return (_num *= 2); }
};

std::vector<uint64_t> powers_of_two(int n)
{
    std::vector<uint64_t> vec(n + 1, 1);
    std::generate(vec.begin() + 1, vec.end(), generator(1));
    return {vec};
}

///////////////
#include <numeric>

std::vector<uint64_t> powers_of_two(int n) {
    std::vector<uint64_t> v(n + 1, 2);
    v[0] = 1;
    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<uint64_t>());
    return v;
}