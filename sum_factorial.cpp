#include <vector>
#include <numeric>

template<typename T>
unsigned long long int sum_f(int i,T n){
  return (i==1 ||i==0)?(n+1):(n+(i*sum_f(i-1,n)));
}

unsigned long long int sum_factorial(std::vector<int> vi){
  unsigned long long int x=0;
  return std::accumulate(vi.begin(),vi.end(),x,[](auto sum,auto& c){
    return sum+=sum_f(c,0);
  });
}

////////////////////
#include <vector>
#include <numeric>

size_t sum_factorial(std::vector<int> v)
{
	return std::accumulate(v.cbegin(), v.cend(), 0ull, [](size_t s, size_t x) { size_t fact = 1; for (size_t i = 1; i <= x; ++i) fact *= i; return s + fact; });
}

///////////////
#include <vector>

unsigned long long int sum_factorial(std::vector<int> vi)
{
    static const unsigned long long factorial[21] = 
    {
        0x1,
        0x1,
        0x2,
        0x6,
        0x18,
        0x78,
        0x2d0,
        0x13b0,
        0x9d80,
        0x58980,
        0x375f00,
        0x2611500,
        0x1c8cfc00,
        0x17328cc00,
        0x144c3b2800,
        0x13077775800,
        0x130777758000,
        0x1437eeecd8000,
        0x16beecca730000,
        0x1b02b9306890000,
        0x21c3677c82b40000
    };

    unsigned long long sum = 0;

    for (const int& i : vi)
        sum += factorial[i];

    return sum;
}

///////////////////
#include <numeric>
using namespace std;
long long f(int n) { if (n == 0) return 1; return n*f(n-1); }

unsigned long long sum_factorial(vector<int> vi){return accumulate(vi.begin(), vi.end(), 0LL, [](auto a, auto b) {return a + f(b);});}

/////////////
#include <vector>
#include <numeric>
using namespace std;

unsigned long long int sum_factorial(vector<int> vi, vector<unsigned long long> res = {}) {
    if(all_of(vi.cbegin(), vi.cend(), [](const int n) { return n < 2; }))
        return std::accumulate(res.cbegin(), res.cend(), 0ull);
    
    if(res.size() != vi.size()) {
        fill_n(back_inserter(res), vi.size(), 1);
    }
    
    transform(
        vi.cbegin(), vi.cend(), res.cbegin(), res.begin(),
        [](const int n, const unsigned long long res) {
            return res * n;
        }
    );
  
    transform(
        vi.cbegin(), vi.cend(), vi.begin(),
        [](const int n) {
            if(n < 2) return n;
            return n - 1;
        }
    );
  
    return sum_factorial(vi, res);
}

///////////////////