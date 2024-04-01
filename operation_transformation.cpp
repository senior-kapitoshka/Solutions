#include <cstdio>

class Transform {
  static bool is_multi_bit(unsigned x) {
    return (x & (x - 1)) != 0;
  }

public:
  static int operation(int a, int b) {
    assert(!is_multi_bit(b));

    int c = 0;
    while (is_multi_bit(a)) {
      a /= 2;
      c++;
    }

    while (a != b) {
      if (a < b)
        a *=2 ;
      else
        a /=2 ;
      c++;
    }

    return c;
  }
};

/////////////////////
namespace Transform {

bool isPowerOf2(unsigned x) {
  return x != 0 && (x & x - 1) == 0;
}

unsigned operation(unsigned a, unsigned b) {
  unsigned res = 0;
  while (a > b || !isPowerOf2(a))
    a >>= 1, res++;
  while (a < b)
    a <<= 1, res++;
  return res;
}

}
//////////////////////
class Transform {
public:
  static int operation(int a, int b) {
    return a == b ? 0 : 1 + operation(a > b ? a >> 1 : a, a > b ? b : b >> 1);
  }
};