#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

int main() 
{
    long x=std::numeric_limits<long>::min();
    long y=std::numeric_limits<long>::min();
    long z=std::numeric_limits<long>::min();
    long i;
	while(std::cin>>i){
        if(x==std::numeric_limits<long>::min()){
            x=i;
        }
        else if(y==std::numeric_limits<long>::min()){
            y=i;
        }
        else if(z==std::numeric_limits<long>::min()){
            z=i;
            if(y<z) std::swap(y,z);
            if(x<y) std::swap(x,y);
        }
        else {
            if(i>x){
                std::swap(y,z);
                std::swap(x,y);
                x=i;
            }else if(i>y){
                std::swap(y,z);
                y=i;
            }else if(i>z){
                z=i;
            }
        }
    }
    std::cout<<x<<y<<z<<"\n";

	return 0;
}