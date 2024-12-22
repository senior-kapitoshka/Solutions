#include <numeric>

bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

int solve(std::vector<int> v){
  return std::accumulate(v.begin(),v.end(),0,
                [i=0](int& sum, int& cur)mutable{
                  return sum+=isPrime(i++)?cur:0;
                  });
}
////////////////
int solve(std::vector<int> v){
  auto isPrime = [] (int x) {
    for (int i = 2; i * i <= x; i ++) if (x % i == 0) return false;
    return x > 1;
  };
  
  int summa = 0;
  for (unsigned i = 2; i < v.size(); i ++)
    if (isPrime(i)) summa += v[i];
  
  return summa;
}