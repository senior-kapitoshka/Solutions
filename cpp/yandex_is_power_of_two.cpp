#include <iostream>
using namespace std;

bool IsPowOfTwo(int x){
    if(x==0)return false;
    if(x==1) return true;
    return (x%2==1)?false:IsPowOfTwo(x/2);
}

int main() {
    int result = IsPowOfTwo(1024);
    cout << result << endl;
}