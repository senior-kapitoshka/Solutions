#include <iostream>
#include <string>
#include <vector>

int main() 
{
	int all=0;
    int x=0,y=0,l=0;
    std::cin>>all>>x>>y;
    int mn=std::min(x,y);
    int mx=std::max(x,y);
    --all;
    int sum=mx*all;

        while(l<sum){
            int med=(l+sum)/2;
            if ((med/x + med/y)<all) l = med+1;
            else sum = med;
        }

    std::cout<<sum+mn;
	return 0;
}