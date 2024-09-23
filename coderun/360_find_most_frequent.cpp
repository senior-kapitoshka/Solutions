#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() 
{
	long n;
    std::cin>>n;
    std::unordered_map<long long,int>mp;
    for(long i=0;i<n;++i){
        long long x;
        std::cin>>x;
        ++mp[x];
    }
    std::cout<<
        std::max_element(mp.begin(),mp.end(),
        [](auto lhs, auto rhs){
            return lhs.second<rhs.second || 
                (lhs.second==rhs.second &&
                lhs.first<rhs.first);
        })->first;

	return 0;
}