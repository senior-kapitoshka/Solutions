#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() 
{
    int a,b,c;
    std::cin>>a>>b>>c;
    if(c<0){      
        std::cout<<"NO SOLUTION";
        return 0;
    }
    if(a==0){
        if(std::pow(c,2)==b){
             std::cout<<"MANY SOLUTIONS";
            return 0;
        }else {
           std::cout<<"NO SOLUTION";
            return 0; 
        }
    }
    if(!((c*c - b) %a)) {
        int x=(std::pow(c,2)-b)/a;
        std::cout<<x<<"\n";
        return 0;
    }else{
           std::cout<<"NO SOLUTION";
            return 0; 
    }


	return 0;
}