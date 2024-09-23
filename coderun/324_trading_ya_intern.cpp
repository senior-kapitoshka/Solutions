#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
    long n,m;
	std::cin>>n>>m;
    std::vector<long long>vn,vm;
    vn.reserve(n);
    vm.reserve(m);
    for(long i=0;i<n;++i){
        long long x;
        std::cin>>x;
        vn.push_back(x);
    }
    for(long i=0;i<m;++i){
        long long x;
        std::cin>>x;
        vm.push_back(x);
    }
    std::sort(vn.begin(),vn.end());
    std::sort(vm.rbegin(),vm.rend());
    long long res=0;
    for(long i=0;(n>m)?i<m:i<n;++i){
        if(vn[i]<vm[i]){
            res+=vm[i]-vn[i];
        }
    }
    std::cout<<res;
	return 0;
}