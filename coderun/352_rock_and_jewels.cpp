#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
    std::string s,j;
    std::cin>>j;
    std::cin>>s;
    long long res=0;
    if(s.empty() || j.empty()) std::cout<<res;
    else{
        std::for_each(s.begin(),s.end(),[&j,&res](auto& c){
            res+=j.find(c)!=j.npos?1:0;
        });
        std::cout<<res<<"\n";
    }
	return 0;
}