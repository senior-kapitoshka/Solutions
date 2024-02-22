#include <iostream>
using namespace std;
void fib(int& a,int& b){
    int i=a;
    int j=b;
    a=j;
    b=i+j;
}

int Fibonacci(int x){
    int a=0;
    int b=1;
    while(x!=0){
        --x;
        fib(a,b);
    }
    return a;
}
int main() {
    cout << Fibonacci(6) << endl;
}
//////////////////////////////
int Fibonacci(int i) {
    if (0 == i) {
        return 0;
    }
    if (1 == i) {
        return 1;
    }
    return Fibonacci(i - 1) + Fibonacci(i - 2);
}

int main() {
    cout << Fibonacci(6) << endl;
    return 0;
}
/////////////////////////
//compile time//
//////////////
template<size_t N>
struct Fib: integral_constant<size_t,
Fib<N-1>{}
+
Fib<N-2>{}>
{};

template<>
struct Fib<1>: integral_constant<size_t,1>{};
template<>
struct Fib<0>: integral_constant<size_t,0>{};

///////////////////////////