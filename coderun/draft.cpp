#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() 
{
	std::vector<int>neg;
    std::vector<int>poz;
    int i=0;
    while(std::cin){
        std::cin>>i;
        if(i<0) neg.emplace_back(i);
        else poz.emplace_back(i);
    }
for(auto i:neg)std::cout<<i<<"\n";

for(auto i:poz)std::cout<<i<<"\n";

    if(!neg.empty())std::sort(neg.begin(),neg.end());
    if(!poz.empty())std::sort(poz.begin(),poz.end(),std::greater<long long>());
    neg.empty()?std::cout<<poz[1]<<" "<<poz[0]:poz.empty()?std::cout<<neg[0]<<" "<<neg[1]:neg[1]*neg[0]>poz[1]*poz[0]?std::cout<<neg[0]<<" "<<neg[1]:std::cout<<poz[1]<<" "<<poz[0];
	return 0;
}