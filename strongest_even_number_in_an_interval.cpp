#include <bitset>
int strongest_even(int n, int m) {
    int msk= unsigned(-1) << 1;//left shift

    m = m & msk; //and
    int res = m;
    while (m>=n) {
        msk= msk<<1;
        res = m;
        m= m & msk;
    }
    return res;
}
///////////////////////

int strongest_even(int n, int m) {
    unsigned int mask = (unsigned int)(-1) << 1;
    m &= mask;
    int result = m;
    while (m >= n) {
        mask <<= 1;
        result = m;
        m &= mask;
    }
    return result;
}

//////////////////
int strongest_even(int n, int m) {
  if (n == m) return n;
  else {
    n = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    m = (m % 2 == 0) ? m / 2 : (m - 1) / 2;
    return 2 * strongest_even(n, m);
  }
}

/////////////
int strongest_even(int n, int m) {
    long k = n;

    for (int i = 1; k + i <= m; i *= 2) {
        if ((k + i) % (i * 2) == 0) k += i;
    }

    return (int)k;
}